#include "TowerHanoi.h"

//Precondition: An positive integer
//Postcondition: Sets size 
void TowerHanoi::setSize(int newSize){
	size = newSize;
}
//Precondition: NA
//Postcondition: returns size
int TowerHanoi::getSize() const{
	return size;
}
//Precondition: NA
//Postcondition: Displays hanoiMenu
void TowerHanoi::hanoiMenu(){
	int turns;
	char choice;
	do{
		system("cls");
		moves = 1;

		cout << "Tower of Hanoi (Recursive) by Joe Bryant\n";
		cout << string(100, char(196)) << endl << endl;

		setSize(inputInteger("\tEnter the number of rings (1..64): ", 1, 64));

		turns = size;

		initializePegs();

		displayPegs();

		updatePegs(turns);

		cout << "\tThe computer has solved the game in " << moves - 1 << " moves.\n\n";

		choice = toupper(inputChar("\tPlay again? (Y-yes or N-no) ", "YN"));



	} while (choice == 'Y');
	cout << endl;
}
//Precondition: an integer named turns
//Postcondition: calculates Hanoi solution
void TowerHanoi::updatePegs(int turns){
	if (turns == 0)  //stop-case: stops when turns is equal to 0
	{
		return;
	}

	updatePegs(turns - 1);
	if (size % 2 != 0)
	{
		if (moves % 3 == 1)
		{
			if (pegC.empty())
			{
				cout << "\tMove #" << moves << " from peg-A to peg-C...\n";
				pegC.push(pegA.top());
				pegA.pop();
			}
			else if (pegA.empty())
			{
				cout << "\tMove #" << moves << " from peg-C to peg-A...\n";
				pegA.push(pegC.top());
				pegC.pop();
			}
			else if (!pegC.empty() && !pegA.empty())
			{
				if (pegA.top() < pegC.top())
				{
					cout << "\tMove #" << moves << " from peg-A to peg-C...\n";
					pegC.push(pegA.top());
					pegA.pop();
				}
				else if (pegC.top() < pegA.top())
				{
					cout << "\tMove #" << moves << " from peg-C to peg-A...\n";
					pegA.push(pegC.top());
					pegC.pop();
				}
			}
		}
		else if (moves % 3 == 2)
		{
			if (pegB.empty())
			{
				cout << "\tMove #" << moves << " from peg-A to peg-B...\n";
				pegB.push(pegA.top());
				pegA.pop();
			}
			else if (pegA.empty())
			{
				cout << "\tMove #" << moves << " from peg-B to peg-A...\n";
				pegA.push(pegB.top());
				pegB.pop();
			}
			else if (!pegB.empty() && !pegA.empty())
			{
				if (pegA.top() < pegB.top())
				{
					cout << "\tMove #" << moves << " from peg-A to peg-B...\n";
					pegB.push(pegA.top());
					pegA.pop();
				}
				else if (pegB.top() < pegA.top())
				{
					cout << "\tMove #" << moves << " from peg-B to peg-A...\n";
					pegA.push(pegB.top());
					pegB.pop();
				}
			}
		}
		else if (moves % 3 == 0)
		{
			if (pegB.empty())
			{
				cout << "\tMove #" << moves << " from peg-C to peg-B...\n";
				pegB.push(pegC.top());
				pegC.pop();
			}
			else if (pegC.empty())
			{
				cout << "\tMove #" << moves << " from peg-B to peg-C...\n";

				pegC.push(pegB.top());
				pegB.pop();
			}
			else if (!pegB.empty() && !pegC.empty())
			{
				if (pegC.top() < pegB.top())
				{
					cout << "\tMove #" << moves << " from peg-C to peg-B...\n";
					pegB.push(pegC.top());
					pegC.pop();
				}
				else if (pegB.top() < pegC.top())
				{
					cout << "\tMove #" << moves << " from peg-B to peg-C...\n";
					pegC.push(pegB.top());
					pegB.pop();
				}
			}
		}
	}
	else if (size % 2 == 0)
	{
		if (moves % 3 == 1)
		{
			if (pegB.empty())
			{
				cout << "\tMove #" << moves << " from peg-A to peg-B...\n";
				pegB.push(pegA.top());
				pegA.pop();
			}
			else if (pegA.empty())
			{
				cout << "\tMove #" << moves << " from peg-B to peg-A...\n";
				pegA.push(pegB.top());
				pegB.pop();
			}
			else if (!pegA.empty() && !pegB.empty())
			{
				if (pegA.top() < pegB.top())
				{
					cout << "\tMove #" << moves << " from peg-A to peg-B...\n";
					pegB.push(pegA.top());
					pegA.pop();
				}
				else if (pegB.top() < pegA.top())
				{
					cout << "\tMove #" << moves << " from peg-B to peg-A...\n";
					pegA.push(pegB.top());
					pegB.pop();
				}
			}
		}
		else if (moves % 3 == 2)
		{
			if (pegC.empty())
			{
				cout << "\tMove #" << moves << " from peg-A to peg-C...\n";
				pegC.push(pegA.top());
				pegA.pop();
			}
			else if (pegA.empty())
			{
				cout << "\tMove #" << moves << " from peg-C to peg-A...\n";
				pegA.push(pegC.top());
				pegC.pop();
			}
			else if (!pegC.empty() && !pegA.empty())
			{
				if (pegA.top() < pegC.top())
				{
					cout << "\tMove #" << moves << " from peg-A to peg-C...\n";
					pegC.push(pegA.top());
					pegA.pop();
				}
				else if (pegC.top() < pegA.top())
				{
					cout << "\tMove #" << moves << " from peg-C to peg-A...\n";
					pegA.push(pegC.top());
					pegC.pop();
				}
			}
		}
		else if (moves % 3 == 0)
		{
			if (pegC.empty())
			{
				cout << "\tMove #" << moves << " from peg-B to peg-C...\n";
				pegC.push(pegB.top());
				pegB.pop();
			}
			else if (pegB.empty())
			{
				cout << "\tMove #" << moves << " from peg-C to peg-B...\n";
				pegB.push(pegC.top());
				pegC.pop();
			}
			else if (!pegC.empty() && !pegB.empty())
			{
				if (pegB.top() < pegC.top())
				{
					cout << "\tMove #" << moves << " from peg-B to peg-C...\n";
					pegC.push(pegB.top());
					pegB.pop();
				}
				else if (pegC.top() < pegB.top())
				{
					cout << "\tMove #" << moves << " from peg-C to peg-B...\n";
					pegB.push(pegC.top());
					pegC.pop();
				}
			}
		}
	}
	moves++;
	displayPegs();
	updatePegs(turns - 1);



}
//Precondition: NA
//Postcondition: initializes pegs
void TowerHanoi::initializePegs()
{
	while (!pegA.empty())
	{
		pegA.pop();
	}
	for (int i = size; i > 0; i--)
	{
		pegA.push(i);
	}

	while (!pegB.empty())
	{
		pegB.pop();
	}
	while (!pegC.empty())
	{
		pegC.pop();
	}

	if (pegA.size() == size)
	{
		result = pegA;
	}
}
//Precondition: NA
//Postcondition: prints out pegs
void TowerHanoi::displayPegs()
{
	stack<int> tempA(pegA);
	stack<int> tempB(pegB);
	stack<int> tempC(pegC);

	cout << endl << string(13, char(255)) << char(186) << string(15, char(255)) << char(186) << string(15, char(255)) << char(186) << endl;



	for (int index = 0; index < size; index++)
	{
		cout << setw(14);

		if (tempA.size() == (size - index))
		{
			cout << tempA.top();
			tempA.pop();
		}
		else
		{
			cout << char(186);
		}

		cout << setw(16);

		if (tempB.size() == (size - index))
		{
			cout << tempB.top();
			tempB.pop();
		}
		else
		{
			cout << char(186);
		}

		cout << setw(16);

		if (tempC.size() == (size - index))
		{
			cout << tempC.top();
			tempC.pop();
		}
		else
		{
			cout << char(186);
		}

		cout << endl;
	}

	cout << string(8, char(255)) << string(5, char(205)) << char(202) << string(5, char(205)) << string(5, char(255)) << string(5, char(205)) << char(202) << string(5, char(205)) << string(5, char(255)) << string(5, char(205)) << char(202) << string(5, char(205)) << endl;
	cout << string(13, char(255)) << "A" << string(15, char(255)) << "B" << string(15, char(255)) << "C\n\n";
}