#include <iostream>
#include <string>
#include <functional>


struct Demo {
	static const int a = 10;
};

class Demo2 {
public:
	static const int b = 2;
};

int main() {
	std::tuple<std::string, int, float> tp("Seven", 77, 66.1);

	std::string name;
	int age;
	float weight;

	auto tp2 = std::make_tuple(std::ref(name), std::ref(age), std::ref(weight)) = tp;

	std::cout << "before change: " << std::endl
		<< "name: " << name << ", " << "age: " << age << ", " << "weight: " << weight << std::endl;

	name = "Eight";
	age = 79;
	weight = 69;

	std::cout << "before change: " << std::endl
		<< "name: " << std::get<0>(tp2) << ", " << "age: " << std::get<1>(tp2) << ", " 
		<< "weight: " << std::get<2>(tp2) << std::endl;

	std::cout << std::tuple_size<decltype(tp)>::value << std::endl;

	return 0;
}