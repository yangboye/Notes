#pragma once

class Bed;

class House
{
public:
	House();
	virtual ~House();

public:
	void GoToBed();
	void Leave();

private:
	Bed* my_bed_;

public:
};

