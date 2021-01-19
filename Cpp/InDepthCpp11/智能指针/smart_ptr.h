#pragma once
// 基于引用计数的智能指针实现

#include <iostream>

template<typename T>
class SmartPtr {
public:
	SmartPtr(T* p);
	SmartPtr(const SmartPtr<T>& orig);	// 拷贝构造函数
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);	// 拷贝赋值函数
	~SmartPtr();

private:
	void Free();	// 释放资源

private:
	T* ptr_;
	int* use_count_;
};

template<typename T>
SmartPtr<T>::SmartPtr(T* p)
	: ptr_(p) {
	try {
		use_count_ = new int(1);
	} catch (...) {
		Free();

		std::cout << "Allocate memory for `use_count_` fails" << std::endl;
		exit(1);
	}

	std::cout << "Constructor is called" << std::endl;
}

template<typename T>
SmartPtr<T>::~SmartPtr() {
	// 只在最后一个对象引用ptr时才释放内存
	if (--(*use_count_) == 0) {
		Free();

		std::cout << "Destructor is called" << std::endl;
	}
}

template<typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& orig) {
	ptr_ = orig.ptr_;
	use_count_ = orig.use_count_;
	++(*use_count_);
	std::cout << "Copy constructor is called" << std::endl;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& rhs) {
	if (&rhs == this) {
		return *this;
	}

	++(*(rhs.use_count_));	// 引用计数加1

	// 将左操作数对象的引用减一，如果该对象的引用计数为0，释放
	if (--(*use_count_) == 0) {
		Free();
		std::cout << "Left hand side object is deleted" << std::endl;
	}

	ptr_ = rhs.ptr_;
	use_count_ = rhs.use_count_;

	std::cout << "Copy assignment operator is called" << std::endl;
	return *this;
}

template<typename T>
void SmartPtr<T>::Free() {
	delete ptr_;
	ptr_ = nullptr;
	delete use_count_;
	use_count_ = nullptr;
}