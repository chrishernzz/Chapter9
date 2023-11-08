//Name: Christian Hernandez
//Date: 11/7/2023
//subscription: CMPR131

//Credit: Christian Hernandez,Bryan Alarcon,Thanh Tran, Joe Bryant,Erik Santana, Saul Merino

#include<iostream>
#include"input (1).h"
#include"Pattern.h"
#include"GuessNumber.h"
#include"TowerHanoi.h"
#include"n_Queens.h"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge2();
void challenge3();
void challenge4();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: challenge3(); break;
		case 4: challenge4(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}
//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption() {
	system("cls");
	cout << "\n\tCMPR131 Chapter 9: Recursive Applications by Christian Hernandez(11/6/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Pattern of asterisk and blanks";
	cout << "\n\t\t2> Guess a number";
	cout << "\n\t\t3> Solve Tower of Hanoi";
	cout << "\n\t\t4> Solve n-Queens";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 4);
}

//precondition: going to call my Pattern class
//postcondition: going to then put 0 and 8 as the parameters for the function pattern()
void challenge1() {
	Pattern menu;
	system("cls");
	cout << "\t1> Pattern of asterisk and blanks\n\n";
	menu.pattern(0,8);
}
//precondition: going to call my GuessNumber class
//postcondition: going to then call my numberGuess function, going to use setters and getters to set/get the random number
void challenge2() {
	GuessNumber menu;
	int min = 1, guessCount = 0;
	//to always change the random generator
	srand(static_cast<unsigned int>(time(nullptr)));
	//random number from 1-1000
	menu.setRandomNumber(rand() % 1000 + min);
	system("cls");
	cout << "\t2> Guess your number between "<<min<<" to "<<menu.getRandomNumber()<<".\n\n";
	cout << "\tThink of a number from " << min << " to "<<menu.getRandomNumber()<<".\n\n";
	system("pause");
	menu.numberGuess(min, menu.getRandomNumber(), guessCount);
}
//precondition: going to call my TowerHanoi class
//postcondition: going to then call my mainMenuInformation function that will have all the information and the menus as well 
void challenge3() {
	TowerHanoi menu;
	menu.hanoiMenu();
}
//precondition: going to call my n_Queens class
//postcondition: going to then call my mainMenuInformation function that will have all the information and the menus as well 
void challenge4() {
	n_Queens menu;
	menu.n_QueensMenu();
}
