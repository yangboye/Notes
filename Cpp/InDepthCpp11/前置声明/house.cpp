#include "bed.h"
#include "house.h"
#include <iostream>

House::House()
{
	my_bed_ = new Bed();
	std::cout << __FUNCTION__ << std::endl;
}

House::~House()
{
	std::cout << __FUNCTION__ << std::endl;
}

void House::GoToBed() {
	my_bed_->Sleep();
}

void House::Leave()
{
	std::cout << __FUNCTION__ << std::endl;
}

