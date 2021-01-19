#pragma once
// �������ü���������ָ��ʵ��

#include <iostream>

template<typename T>
class SmartPtr {
public:
	SmartPtr(T* p);
	SmartPtr(const SmartPtr<T>& orig);	// �������캯��
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);	// ������ֵ����
	~SmartPtr();

private:
	void Free();	// �ͷ���Դ

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
	// ֻ�����һ����������ptrʱ���ͷ��ڴ�
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

	++(*(rhs.use_count_));	// ���ü�����1

	// �����������������ü�һ������ö�������ü���Ϊ0���ͷ�
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