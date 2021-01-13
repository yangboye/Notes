#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>



int main() {
	std::vector<int> arr = { 1,2,3 };
	for (auto val : arr) {
		std::cout << val << std::endl;
		arr.push_back(0);
	}


  return 0;
}