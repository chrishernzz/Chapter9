#include "Pattern.h"

//precondition: going to call the default constructor class
//postcondition: going to then intialize the privates 
Pattern::Pattern() :left(0), length(0) {}

Pattern::Pattern(int newLeft, int newLength){
	left = newLeft;
	length = newLength;
}

//precondition:
//postcondtion:
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