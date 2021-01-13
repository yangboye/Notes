#pragma once
#include <map>

#include "non_copyable.h"

template<typename Func>
class Events: NonCopyable {
public:
	Events() {}
	~Events() {}

public:
	// 注册观察者, 支持右值引用
	int Connect(Func&& f) {
		return Assign(f);
	}

	// 注册观察者
	int Connect(const Func& f) {
		return Assign(f);
	}

	// 移除观察者
	void Disconnect(int key) {
		connections_.erase(key);
	}

	// 通知所有的观察者
	template<typename... Args>
	void Notify(Args&&... args) {
		for (auto& it: connections_) {
			it.second(std::forward<Args>(args)...);
		}
	}

private:
	// 保存观察者并分配观察者的编号
	template<typename F>
	int Assign(F&& f) {
		int k = observer_id_++;
		connections_.emplace(k, std::forward<F>(f));
		return k;
	}

private:
	int observer_id_ = 0;							// 观察者对应的编号
	std::map<int, Func> connections_;	// 观察者列表
};