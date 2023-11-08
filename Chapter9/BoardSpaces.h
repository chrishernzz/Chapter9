#pragma once

//precondition: going to create a class that has the board 
//postcondition: going to have two privates that are row and column, default constructor, and setters and getters
class BoardSpaces{
private:
	int row;
	int column;

public:
	BoardSpaces();
	void setRow(int newRow);
	void setColumn(int newColumn);
	int getRow() const;
	int getColumn() const;
};