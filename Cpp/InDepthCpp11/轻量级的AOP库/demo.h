#pragma once

#include <memory>
#include <string>
#include <iostream>

class IHello {
public:
	IHello() {}
	virtual ~IHello() {}
	virtual void Output(const std::string& str) {}
};

class Hello : public IHello {
public:
	void Output(const std::string& str) override {
		std::cout << str << std::endl;
	}
};

class HelloProxy : public IHello {
public:
	HelloProxy(IHello *p)
		: ptr_(p) {}
	~HelloProxy(){
		delete ptr_;
		ptr_ = nullptr;
	}
	void Output(const std::string& str) override final {
		std::cout << "Before real Output" << std::endl;
		ptr_->Output(str);
		std::cout << "After real Output" << std::endl;
	}

private:
	IHello* ptr_;
};

void TestProxy() {
	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
	hello->Output("It is a test.");
}