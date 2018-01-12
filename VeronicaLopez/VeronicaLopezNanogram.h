#pragma once
#ifndef VERONICALOPEZNANOGRAM_H
#define VERONICALOPEZNANOGRAM_H

#include <iostream>

using namespace std;

int rCord, cCord;
char currentBoard[5][5];

//winRow and winCol stores the coordinates for winning the puzzle
int winRow[13] = { 0,1,2,3,4,1,2,1,0,1,2,3,4 };
int winCol[13] = { 0,0,0,0,0,1,2,3,4,4,4,4,4 };

//emptyRow and emptyCol are the coordinates for the grid that are supposed ot be empty
int emptyRow[12] = { 0,2,3,4,0,1,3,4,0,2,3,4 };
int emptyCol[12] = { 1,1,1,1,2,2,2,2,3,3,3,3 };


//creates one puzzle
void printBoard()
{
	cout << "      _5_ _1_ _1_ _1_ _5_" << endl;
	for (int row = 0; row < 5; row++)
	{
		if (row == 2)
		{
			cout << "1 1 1";
		}
		if (row == 1)
		{
			cout << "  2 2";
		}
		if (row == 0|| row == 3 || row == 4)
		{
			cout << "  1 1";
		}
		for (int column = 0; column < 5; column++)
		{
			
			cout << "|_";
			cout << currentBoard[row][column];
			cout << "_";
		}
		cout << "|";
		cout << endl;
	}
}

//creates an empty grid 
void freshBoard()
{
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			currentBoard[row][column] = '_';
		}
	}	
	printBoard();
}

//displays board with current X's
void displayCurrentBoard()
{
	currentBoard[rCord][cCord] = 'X';
	printBoard();
}

//takes in the coordinates that the user wants to add 
void userInput()
{
	cout << "Enter row coordinate (0-4): ";
	cin >> rCord;
	while (rCord < 0 || rCord > 4) //checks to see if you have entered a valid input for row coordinate
	{
		cout << "Invalid Input" << endl;
		cout << "Enter row coordinate (0-4): ";
		cin >> rCord;
	}
	
	cout << "Enter column coordinate (0-4): ";
	cin >> cCord;
	while (cCord < 0 || cCord > 4) //checks to see if you have entered a valid input for column coordinate
	{
		cout << "Invalid Input" << endl;
		cout << "Enter column coordinate (0-4): ";
		cin >> cCord;
	}

	displayCurrentBoard();
}

void remove() //takes in new coordinates for row and column and removed the X value
{
	cout << "Enter row coordinate (0-4): ";
	cin >> rCord;
	while (cCord < 0 || cCord > 4) //checks to see if you have entered a valid input for row coordinate
	{
		cout << "Invalid Input" << endl;
		cout << "Enter row coordinate (0-4): ";
		cin >> rCord;
	}

	cout << "Enter column coordinate (0-4): ";
	cin >> cCord;
	while (cCord < 0 || cCord > 4) //checks to see if you have entered a valid input for column coordinate
	{
		cout << "Invalid Input" << endl;
		cout << "Enter column coordinate (0-4): ";
		cin >> cCord;
	}

	currentBoard[rCord][cCord] = '_'; //replace any value to underscore
	printBoard(); 
}

//checks to see if the player won and will return true or false
bool checkWin()
{
	int count = 0;//at the end there should be 13 X's, so this keeps track of them
	bool win;
	for (int i = 0; i < 13; i++)
	{
		if (currentBoard[winRow[i]][winCol[i]] == 'X')
		{
			count++;
		}
	}
	if (count == 13) //if the user reaches to 13 X's check to see if they didn't have any extra X's
	{
		for (int j = 0; j < 12; j++)
		{
			if (currentBoard[emptyRow[j]][emptyCol[j]] == 'X')
			{
				win = false; //if you see an X where is shouldn't be return false;
				return win;
			}
		}
		win = true;//else return true
		return win;
	}
	else
	{
		win = false; //returns false if count didn't reach to 13
		return win;
	}	
}
#endif