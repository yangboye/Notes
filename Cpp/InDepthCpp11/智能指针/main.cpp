#include <iostream>
#include <memory>

class A : public std::enable_shared_from_this<A> {
public:
	A() {
		std::cout << "A constructor" << std::endl;
	}

	A(int a) {
		std::cout << "In constructor of A: param->" << a << std::endl;
	}

	~A() {
		std::cout << "A destructor" << std::endl;
	}

	std::shared_ptr<A> GetSelf() {
		return shared_from_this();
	}
};

int main(int argc, char** argv) {
	A a();	// 声明的是一个函数a, 返回类型为A
	A b = A(10);	// 栈对象, 会自动释放

	A* p_a = new A();	// 堆对象, 不会自动释放

	std::shared_ptr<A> p_b = std::make_shared<A>();

	std::shared_ptr<A> p_c = b.GetSelf();

	return 0;
}