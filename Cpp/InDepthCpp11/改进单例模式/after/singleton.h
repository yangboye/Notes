#pragma once

#include <memory>

namespace after {

template<typename T>
class Singleton
{
public:
	template<typename... Args>
	static std::shared_ptr<T> Instance(Args&&... args) {
		if (nullptr == instance_) {
			instance_ = std::make_shared<T>(std::forward<Args>(args)...);	// 完美转换
		}
		return instance_;
	}

	// 获取单例
	static std::shared_ptr<T> GetInstance() {
		if (nullptr == instance_) {
			throw std::logic_error("The instance is not init, please initialize the instance first.");
		}
		return instance_;
	}

	// 销毁单例
	//static void DestroyInstance() {
	//	delete instance_;
	//	instance_ = nullptr;
	//}

private:
	Singleton();
	virtual ~Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

private:
	static std::shared_ptr<T> instance_;
};

} // namespace after

template<typename T> std::shared_ptr<T> after::Singleton<T>::instance_ = nullptr;