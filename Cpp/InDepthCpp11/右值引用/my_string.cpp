#include <iostream>

#include "my_string.h"



MyString::MyString()
	: data_(nullptr), len_(0) {
	std::cout << "默认构造函数" << std::endl;
}

MyString::MyString(const char * p)
	: len_(strlen(p)) {
	CopyData(p);
	std::cout << "const char* p构造函数" << std::endl;
}

MyString::MyString(const MyString & str)
	:len_(str.len_) {
	CopyData(str.data_);
	std::cout << "拷贝构造函数" << std::endl;
}

MyString::MyString(MyString && str)
	: len_(std::move(str.len_)), data_(std::move(str.data_))
{
	std::cout << "移动构造函数" << std::endl;
}

MyString & MyString::operator=(const MyString & str)
{
	if (this != &str) {
		len_ = str.len_;
		CopyData(str.data_);
	}

	std::cout << "拷贝赋值函数" << std::endl;

	return *this;
}

MyString & MyString::operator=(MyString && str)
{
	if (this != &str) {
		len_ = std::move(str.len_);
		data_ = std::move(str.data_);
	}

	std::cout << "移动赋值函数" << std::endl;

	return *this;
}

MyString::~MyString()
{
	if (data_) {
		delete[] data_;
	}

	std::cout << "析构函数" << std::endl;

}

char * MyString::GetCStr() const
{
	return data_;
}

void MyString::CopyData(const char* s)
{
	data_ = new char[len_ + 1];
	memcpy(data_, s, len_);
	data_[len_] = '\0';
}
