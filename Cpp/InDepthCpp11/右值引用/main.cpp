#include <iostream>
#include <string>
#include <vector>

#include "my_string.h"


int main() {
	//MyString s1;


	MyString s2 = MyString("test2");
	MyString s3(std::move(s2));

	std::cout << s2.GetCStr() << std::endl;

	//std::cout << s2.GetCStr() << std::endl;

	std::vector<std::string> v1 = { "aaa", "bbb", "ccc" };
	std::vector<std::string> v2(std::move(v1));

	const char* tmp = "abckkjhkjhkjh";
	char tmp2[] = "a";
	std::cout << "sizeof(): " << sizeof(tmp2) << std::endl;
	std::cout << "strlen(): " << strlen(tmp) << std::endl;
	

	std::cout << "遍历 v1" << std::endl;
	for (const auto& it : v1) {
		std::cout << it << std::endl;
	}
	std::cout << "遍历 v1 end" << std::endl;

	std::cout << "遍历 v2" << std::endl;
	for (const auto& it : v2) {
		std::cout << it << std::endl;
	}
	std::cout << "遍历 v2 end" << std::endl;

	std::cout << v2.size() << std::endl;
	std::cout << v1.size() << std::endl;

	return 0;
}