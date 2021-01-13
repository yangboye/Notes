#pragma once

class Test {
public:
	Test();
	~Test();

private:
	static const int kNumTurns_ = 5;
	int score_[kNumTurns_];
};

