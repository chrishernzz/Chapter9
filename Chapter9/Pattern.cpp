#include "Pattern.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
Pattern::Pattern() :left(0), length(0) {}

//precondition: going to get the new left and length 
//postcondition: going to set the private left with the new left member and the private length with the new length member
Pattern::Pattern(int newLeft, int newLength){
	left = newLeft;
	length = newLength;
}

//precondition: going to have the parameters: int left(spaces) & int length(length of pattern)
//postcondition: going to returns only when variable length == 0
void Pattern::pattern(int left, int length){
	if (length == 0) {
		return;				// STOP or BASE case
	}

	pattern(left, length / 2); // Recursive call
	cout << '\t';

	for (int i = 0; i < left; i++) {
		cout << "  ";
	}
	for (int i = 0; i < length; i++) {
		cout << "* ";
	}
	cout << '\n';
	pattern(left + length / 2, length / 2);

}