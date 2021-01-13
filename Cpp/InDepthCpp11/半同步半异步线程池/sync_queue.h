#pragma once
#include <iostream>
#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>

template<typename T>
class SyncQueue {
public:
	SyncQueue(int max_size)
		: max_size_(max_size), need_stop_(false){}

public:
	// ��������������
	void Put(const T& x) {
		Add(x);
	}

	// ��������������
	void Put(T&& x) {
		Add(std::forward<T>(x));
	}

	void Take(std::list<T>& list) {
		std::unique_lock<std::mutex> locker(mutex_);
		not_empty_.wait(locker, [this] {
			return need_stop_ || NotEmpty();
		});

		if (need_stop_) {
			return;
		}

		list = std::move(queue_);

		not_full_.notify_one();
	}

	void Take(T& t) {
		std::unique_lock<std::mutex> locker(mutex_);
		not_empty_.wait(locker, [this] {
			return need_stop_ || NotEmpty();
		});

		if (need_stop_) {
			return;
		}

		t = queue_.front();
		queue_.pop_front();
		not_full_.notify_one();
	}

	void Stop() {
		{
			std::lock_guard<std::mutex> locker(mutex_);
			need_stop_ = true;
		}
		not_full_.notify_all();
		not_empty_.notify_all();
	}

	bool Empty() const {
		std::lock_guard<std::mutex> locker(mutex_);
		return queue_.empty();
	}

	bool Full() const {
		std::lock_guard<std::mutex> locker(mutex_);
		return (queue_.size() == max_size_);
	}

	size_t Size() const {
		std::lock_guard<std::mutex> locker(mutex_);
		return queue_.size();
	}

	int Count() const {
		return queue_.size();
	}

private:
	// �жϻ����������Ƿ�δ��; �������, ����true; ���򷵻�false
	bool NotFull() const {
		bool full = this->queue_.size() >= this->max_size_;

		if (full) {
			std::cout << "����������, ��Ҫ�ȴ�..." << std::endl;
		}

		return !full;
	}

	// �жϻ����������Ƿ�δ��; ����ǿ�, ����true; ���򷵻�false
	bool NotEmpty() const {
		bool empty = this->queue_.empty();

		if (empty) {
			std::cout << "����������, ��Ҫ�ȴ�..., �첽����߳�ID: " << std::this_thread::get_id() << std::endl;
		}

		return !empty;
	}

	// �򻺳����������������
	template<typename F>
	void Add(F&& x) {
		std::unique_lock<std::mutex> locker(mutex_);
		not_full_.wait(locker, [this] {
			return need_stop_ || NotFull();
		});

		if (need_stop_) {
			return;
		}

		queue_.push_back(std::forward<F>(x));
		not_empty_.notify_one();
	}

private:
	std::list<T> queue_;								// ������
	std::mutex mutex_;									// ������(�������������ʹ��)
	std::condition_variable not_empty_;	// ��Ϊ�յ���������
	std::condition_variable not_full_;	// û��������������

	int max_size_;											// ͬ����������size
	bool need_stop_;										// ֹͣ�ı�־
};