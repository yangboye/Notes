#pragma once
#include <atomic>
#include <functional>
#include <memory>

#include "sync_queue.h"


class ThreadPool
{
public:
	using Task = std::function<void()>;
	static const int kMaxTaskCount = 100;	// �����������

public:
	ThreadPool(int num_therads = std::thread::hardware_concurrency())
		: queue_(kMaxTaskCount) {
		Start(num_therads);
	}

	~ThreadPool() {
		// ��û��ֹͣ��������ֹͣ�̳߳�
		Stop();
	}

public:
	void Stop() {
		std::call_once(flag_, [this] {
			StopThreadGroup();
		});
	}

	void AddTask(Task&& task) {
		queue_.Put(std::forward<Task>(task));
	}

	void AddTask(const Task& task) {
		queue_.Put(task);
	}

private:
	void Start(int num_threads) {
		running_ = true;
		// �����߳���
		for (int i = 0; i < num_threads; ++i) {
			thread_group_.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
		}
	}

	void RunInThread() {
		while (running_) {
			// ȡ����ֱ�ִ��
			std::list<Task> list;
			queue_.Take(list);

			for (auto& task : list) {
				std::cout << __FUNCTION__ << ": ";
				task();
			}
		}
	}

	void StopThreadGroup() {
		queue_.Stop();	// ��ͬ�������е��߳�ֹͣ
		running_ = false;	// ��Ϊfalse�����ڲ��߳�����ѭ�����˳�

		for (auto& thread : thread_group_) {
			if (thread) {
				thread->join();
			}
		}
		thread_group_.clear();
	}

private:
	std::list<std::shared_ptr<std::thread>> thread_group_;	// ����������߳���
	SyncQueue<Task> queue_;																	// ͬ������
	std::atomic_bool running_;															// �Ƿ�ֹͣ�ı�־
	std::once_flag flag_;																		// ��־
};

