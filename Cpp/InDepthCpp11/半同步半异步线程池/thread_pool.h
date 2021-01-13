#pragma once
#include <atomic>
#include <functional>
#include <memory>

#include "sync_queue.h"


class ThreadPool
{
public:
	using Task = std::function<void()>;
	static const int kMaxTaskCount = 100;	// 最大任务数量

public:
	ThreadPool(int num_therads = std::thread::hardware_concurrency())
		: queue_(kMaxTaskCount) {
		Start(num_therads);
	}

	~ThreadPool() {
		// 若没有停止，则主动停止线程池
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
		// 创建线程组
		for (int i = 0; i < num_threads; ++i) {
			thread_group_.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
		}
	}

	void RunInThread() {
		while (running_) {
			// 取任务分别执行
			std::list<Task> list;
			queue_.Take(list);

			for (auto& task : list) {
				std::cout << __FUNCTION__ << ": ";
				task();
			}
		}
	}

	void StopThreadGroup() {
		queue_.Stop();	// 让同步队列中的线程停止
		running_ = false;	// 置为false，让内部线程跳出循环并退出

		for (auto& thread : thread_group_) {
			if (thread) {
				thread->join();
			}
		}
		thread_group_.clear();
	}

private:
	std::list<std::shared_ptr<std::thread>> thread_group_;	// 处理任务的线程组
	SyncQueue<Task> queue_;																	// 同步队列
	std::atomic_bool running_;															// 是否停止的标志
	std::once_flag flag_;																		// 标志
};

