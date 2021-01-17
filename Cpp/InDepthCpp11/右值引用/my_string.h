#pragma once
#include <string>

class MyString
{
public:
	MyString();
	MyString(const char* p);
	MyString(const MyString& str);
	MyString(MyString&& str);
	MyString& operator=(const MyString& str);
	MyString& operator=(MyString&& str);
	~MyString();

	char* GetCStr() const;

private:
	void CopyData(const char*);

private:
	char* data_;
	std::size_t len_;
};

