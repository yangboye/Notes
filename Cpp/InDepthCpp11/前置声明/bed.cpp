#include "house.h"
#include "bed.h"
#include <iostream>

Bed::Bed()
{
	std::cout << __FUNCTION__ << std::endl;
}

Bed::~Bed()
{
	std::cout << __FUNCTION__ << std::endl;
}

void Bed::SetHouse(House* const house)
{
	if (nullptr != house) {
		my_house_ = house;
	} else {
		my_house_ = new House();
	}
}

void Bed::Sleep()
{
	std::cout << __FUNCTION__ << std::endl;
}

void Bed::LeaveMyHouse()
{
	my_house_->Leave();
}
