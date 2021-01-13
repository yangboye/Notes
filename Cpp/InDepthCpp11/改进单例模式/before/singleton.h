#pragma once
namespace before {

// @brief: 实现一个通用的泛型单例模式, 这个泛型单例要能够创建所有的类型对象;
// 问题: 要创建的类型的构造函数形参可能不尽相同，参数个数和参数类型可能都不同
// 当前解决: 通过定义一些创建单例的模板函数来实现。一般情况下，类型的构造函数形参不超过
//					6个，所以可以通过定义0~6个形参的创建单例的模板函数来实现一个通用的单例模式
template <typename T>
class Singleton
{
public:
	// 支持0个参数的构造函数
	static T* Instance() {
		if (nullptr == instance_) {
			instance_ = new T();
		}
		return instance_;
	}

	// 支持1个参数的构造函数
	template<typename T0>
	static T* Instance(T0 arg0) {
		if (nullptr == instance_) {
			instance_ = new T(arg0);
		}
		return instance_;
	}

	// 支持2个参数的构造函数
	template<typename T0, typename T1>
	static T* Instance(T0 arg0, T1 arg1) {
		if (nullptr == instance_) {
			instance_ = new T(arg0, arg1);
		}
		return instance_;
	}

	// 支持3个参数的构造函数
	template<typename T0, typename T1, typename T2>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2) {
		if (nullptr == instance_) {
			instance_ = new T(arg0, arg1, arg2);
		}
		return instance_;
	}

	// 支持4个参数的构造函数
	template<typename T0, typename T1, typename T2, typename T3>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {
		if (nullptr == instance_) {
			instance_ = new T(arg0, arg1, arg2, arg3);
		}
		return instance_;
	}

	// 支持5个参数的构造函数
	template<typename T0, typename T1, typename T2, typename T3, typename T4>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4) {
		if (nullptr == instance_) {
			instance_ = new T(arg0, arg1, arg2, arg3, arg4);
		}
		return instance_;
	}

	// 支持6个参数的构造函数
	template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
	static T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5) {
		if (nullptr == instance_) {
			instance_ = new T(arg0, arg1, arg2, arg3, arg4, arg5);
		}
		return instance_;
	}

	// 获取单例
	static T* GetInstance() {
		if (nullptr == instance_) {
			throw std::logic_error("The instance is not init, please initialize the instance first.");
		}
		return instance_;
	}

	static void DestoryInstance() {
		delete instance_;
		instance_ = nullptr;
	}

private:
	Singleton();
	virtual ~Singleton();
	// 不允许赋值和赋值
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

private:
	static T* instance_;
};

}	// namespace before

template<typename T> T* before::Singleton<T>::instance_ = nullptr;
