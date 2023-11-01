#pragma once
#include <iostream>
using namespace std;

class Pattern{
private:
	int left;
	int length;

public:
	//default constructor
	Pattern();
	Pattern(int newLeft, int newLength);
	void pattern(int left, int length);
};

