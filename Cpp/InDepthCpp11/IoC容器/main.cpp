#include <iostream>
#include <utility>
#include <string>

#include "my_any.h"

void TestMyAny() {
	MyAny n;
	std::cout << n.IsNull() << std::endl;	// true

	std::string s1 = "hello";
	n = s1;
	std::cout << n.Is<std::string>() << std::endl;	// true
	std::cout << n.AnyCast<std::string>() << std::endl;	// hello
}

int main() {
	TestMyAny();

	return 0;
}