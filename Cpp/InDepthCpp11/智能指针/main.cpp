#include <iostream>
#include <memory>
#include "smart_ptr.h"

using std::cout;
using std::endl;


int main() {
	SmartPtr<int> p1(new int(0));	// 构造函数 SmartPtr<T>::SmartPtr(T*)
	p1 = p1;

	SmartPtr<int> p2(p1); // 拷贝构造函数 SmartPtr<T>::SmartPtr(const SmartPtr<T>&)
	SmartPtr<int> p3(new int(5));// 构造函数 SmartPtr<T>::SmartPtr(T*)
	p1 = p3;// 拷贝赋值函数 SmartPtr<T>::operator=(const SmartPtr<T>&)


	return 0;
}