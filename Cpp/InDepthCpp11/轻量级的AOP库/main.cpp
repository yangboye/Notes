#include "demo.h"

class A {
	A(A&& tmp) {
		p = tmp.p;
		tmp.p = nullptr;
	}
private:
	int* p;
};

int main() {
	TestProxy();
	return 0;
}