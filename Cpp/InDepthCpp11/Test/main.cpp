#include <iostream>

#include "test.h"

using std::cout;
using std::endl;

enum DIY
{
#define YDAR_FN(name) name,
//#include "name.def"
	YDAR_FN(YD)
	YDAR_FN(YYB)
#undef YDAR_FN
};

const char * get_name(DIY diy) {


	switch (diy)
	{
#define YDAR_FN(name) \
	case name:\
		return #name;

#include "name.def"
#undef YDAR_FN
		default:
			break;
	}
	return "null";
}

class A {
public:
	static int kValue;

public:
	void UpdateValue() const {
		kValue++;
	}
};
int A::kValue = 10;

int main() {
	cout << DIY::YD << endl;
	cout << DIY::YYB << endl;
	cout << get_name(DIY::YD) << endl;
	cout << get_name(DIY::YYB) << endl;

	return 0;
}