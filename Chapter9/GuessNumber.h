#pragma once
#include <iostream>
#include<random>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
char inputChar(string prompt, char yes, char no);

//precondition: going to create a GuessNumber that will use rand() as well
//postcondition: going to pass in default constructor, getters and setters and one member function
class GuessNumber{
private:
	int randomNumber;
public:
	//default constructor
	GuessNumber();

	//getters(accessors)
	int getRandomNumber() const;
	//setters(mutators)
	void setRandomNumber(int newRandomNumber);

	//member function 
	void numberGuess(int min, int max, int guessCount);

};

