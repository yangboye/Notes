#include <iostream>

#include "before/singleton.h"
#include "after/singleton.h"

using std::cout;
using std::endl;

struct A {
	A() {}
};

struct B {
	B(int x) {}
};

struct C {
	C(int x, double y) {}
};

int main() {

	// 创建A类型的单例
	before::Singleton<A>::Instance();
	// 创建B类型的单例
	before::Singleton<B>::Instance(1);
	// 创建C类型的单例
	before::Singleton<C>::Instance(1, 3.14);

	before::Singleton<A>::DestoryInstance();
	before::Singleton<B>::DestoryInstance();
	before::Singleton<C>::DestoryInstance();

	// 创建A类型的单例
	auto a = after::Singleton<A>::Instance();
	cout << a.use_count() << endl;
	// 创建B类型的单例
	after::Singleton<B>::Instance(1);
	// 创建C类型的单例
	after::Singleton<C>::Instance(1, 3.14);

	// 使用智能指针
	//after::Singleton<A>::DestroyInstance();
	//after::Singleton<B>::DestroyInstance();
	//after::Singleton<C>::DestroyInstance();

	return 0;
}