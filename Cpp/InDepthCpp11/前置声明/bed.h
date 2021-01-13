#pragma once

class House;

class Bed
{
public:
	Bed();
	Bed(House* const house);
	~Bed();

public:
	void SetHouse(House* const house);
	void Sleep();
	void LeaveMyHouse();
private:
	House* my_house_;
};

