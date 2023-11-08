#include "n_Queens.h"

bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace);

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates variables
n_Queens::n_Queens() :shiftDirection('R'), firstColumnPermutaions(0), boardSize(0), filled(0), gameWon(false) {}

//precondition: going to get the new boardSize
//postcondition: going to set the private boardSize with the new boardSize member
void n_Queens::setBoardSize(int newBoardSize){
	boardSize = newBoardSize;
}
//precondition: going to get the new filled
//postcondition: going to set the private filled with the new filled member
void n_Queens::setFilled(int newFilledAmount){
	filled = newFilledAmount;
}
//precondition: going to get the boardSize 
//postcondition: going to return the private boardSize
int n_Queens::getBoardSize() const{
	return boardSize;
}
//precondition: going to get the filled 
//postcondition: going to return the private filled
int n_Queens::getFilled() const{
	return filled;
}
//precondition: going to create the main menu
//postcondition: going to then get the input for the boardsize and the column as well
void n_Queens::placeFirstQueen(){
	//system("cls");
	BoardSpaces currentSpace;
	bool queenConflict = false;
	boardSize = inputInteger("\tEnter a number(1..100) of queens: ", 1, 100);
	int numQueens = 1;
	int column;
	column = inputInteger("\tEnter the column to place the first queen : ", 1, boardSize);
	placeQueen(numQueens, column);
	if (filledSpaces.size() != boardSize)
	{
		cout << "\tNo Solution Found";
	}

}
//precondition: going to pass in two parameters, one for the number of queens and the other one for the column
//postcondition: going to then use my setters to set the row and column and then do recursive
void n_Queens::placeQueen(int numQueens, int column) {
	//plan:
	BoardSpaces currentSpace;
	bool placed = false;
	currentSpace.setColumn(column);
	currentSpace.setRow(numQueens);
	bool conflict = checkIfConflict(boardSize, filledSpaces, currentSpace);
	if (numQueens == boardSize && conflict == false) // checks if board is complete
	{
		filledSpaces.push(currentSpace);
		displayBoard(filledSpaces);
		return;
	}
	else if (conflict == false) // checks if no conflict
	{
		filledSpaces.push(currentSpace);
		placeQueen(numQueens + 1, 1);
	}
	else if (conflict == true && column != boardSize) // checks if queen on current row is not on the last column
	{
		placeQueen(numQueens, column + 1);
	}
	else if (conflict == true && column == boardSize)
	{
		if (!filledSpaces.empty())
		{
			filledSpaces.pop();
		}
		return;
	}
}
//precondition: going to pass in a stack as a parameter
//postcondition: going to then return the board when it is filled up
void n_Queens::displayBoard(stack<BoardSpaces> filledSpaces) const{
	cout << endl << "\t" << boardSize << "-Queens Solution." << endl;
	cout << "\t" << std::string(1, char(201));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(187)) << endl;

	for (int index = 0; index < boardSize; index++)
	{
		cout << "\t" << string(1, char(186)) << " ";
		for (int j = 0; j < boardSize; j++)
		{
			if (filledSpaces.top().getColumn() == (j + 1))
			{
				cout << 'Q';
			}
			else
			{
				cout << '-';
			}
			if (j < boardSize - 1)
			{
				cout << string(1, char(179));
			}
		}
		cout << " " << string(1, char(186)) << endl;
		filledSpaces.pop();
	}

	cout << "\t" << std::string(1, char(200));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(188)) << endl;
}
//precondition: going to pass in one stacks as the parameters
//postcondition: going to then return a boolean checking if they are conflict, if not then keep looping through the loop
bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace){
	if (filledSpaces.size() > 0)
	{
		if (abs(filledSpaces.top().getColumn() - currentSpace.getColumn()) <= 1)
		{
			return true;
		}
		else
		{
			filledSpaces.pop();
			while (!filledSpaces.empty())
			{
				if (filledSpaces.top().getRow() == currentSpace.getRow())
				{
					return true;
				}
				if (filledSpaces.top().getColumn() == currentSpace.getColumn())
				{
					return true;
				}
				else if ((abs(filledSpaces.top().getRow() - currentSpace.getRow())) == (abs(currentSpace.getColumn() - filledSpaces.top().getColumn())))
				{
					return true;
				}
				filledSpaces.pop();
			}
		}
	}
	return false;
}
//precondition: going to print the information
//postcondition: going to create a menu that shows if the N-Queens board is filled
void n_Queens::n_QueensMenu() {
	system("cls");
	cout << "\n\t4> n_Queens Problem";
	cout << "\n\t" << string(82, char(205)) << "\n";
	placeFirstQueen();
}