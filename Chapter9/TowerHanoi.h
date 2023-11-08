#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<iomanip>
using namespace std;

//input (1) header files inputs validation
int inputInteger(string prompt, int startRange, int endRange);
char inputChar(string prompt, string options);

//precondition: going to create a TowerHanoi game
//postcondition: going to then have 4 stacks and 3 of them are to keep track of the pegs, have setters and getters, and then member functions
class TowerHanoi{
private:
	stack<int> pegA;
	stack<int> pegB;
	stack<int> pegC;
	stack<int> result;
	int size;
	int moves = 1;
public:
	void setSize(int newSize);
	int getSize() const;
	void hanoiMenu();
	void updatePegs(int turns);
	void initializePegs();
	void displayPegs();
};