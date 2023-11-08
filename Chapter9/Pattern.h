#pragma once
#include <iostream>
using namespace std;

//precondition: going to create a class that gives me the pattern in recursive
//postcondition: going to then pass in left and length as my privates, then default constructor, and the pattern function where it is going to be recursive
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

