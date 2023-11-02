#pragma once
#include <iostream>
#include<random>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
char inputChar(string prompt, char yes, char no);

class GuessNumber{
private:
	int randomNumber;
public:
	//defualt constructor
	GuessNumber();

	//getters(accesors)
	int getRandomNumber() const;
	//setters(mutators)
	void setRandomNumber(int newRandomNumber);

	//member function 
	void numberGuess(int min, int max, int guessCount);

};

