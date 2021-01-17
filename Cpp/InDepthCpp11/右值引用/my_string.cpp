#include <iostream>

#include "my_string.h"



MyString::MyString()
	: data_(nullptr), len_(0) {
	std::cout << "Ĭ�Ϲ��캯��" << std::endl;
}

MyString::MyString(const char * p)
	: len_(strlen(p)) {
	CopyData(p);
	std::cout << "const char* p���캯��" << std::endl;
}

MyString::MyString(const MyString & str)
	:len_(str.len_) {
	CopyData(str.data_);
	std::cout << "�������캯��" << std::endl;
}

MyString::MyString(MyString && str)
	: len_(std::move(str.len_)), data_(std::move(str.data_))
{
	std::cout << "�ƶ����캯��" << std::endl;
}

MyString & MyString::operator=(const MyString & str)
{
	if (this != &str) {
		len_ = str.len_;
		CopyData(str.data_);
	}

	std::cout << "������ֵ����" << std::endl;

	return *this;
}

MyString & MyString::operator=(MyString && str)
{
	if (this != &str) {
		len_ = std::move(str.len_);
		data_ = std::move(str.data_);
	}

	std::cout << "�ƶ���ֵ����" << std::endl;

	return *this;
}

MyString::~MyString()
{
	if (data_) {
		delete[] data_;
	}

	std::cout << "��������" << std::endl;

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
