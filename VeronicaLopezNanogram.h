#pragma once
#ifndef VERONICALOPEZNANOGRAM_H
#define VERONICALOPEZNANOGRAM_H

#include <iostream>

using namespace std;


int rCord, cCord;
char currentBoard[5][5];

/*int validCheck()
{
	cout << "Enter row coordinate (1-5): ";
	cin >> rCord;
	while (rCord < 1 || rCord >5)
	{
		validCheck();
	}
	return rCord;
}
*/
void printBoard()
{
	cout << " ___ ___ ___ ___ ___" << endl;
	for (int row = 0; row < 5; row++)
	{
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


void displayCurrentBoard()
{
	currentBoard[rCord][cCord] = 'X';
	printBoard();
}
void userInput()
{
	cout << "Enter row coordinate (0-4): ";
	cin >> rCord;
	if (rCord < 0 || rCord > 4)
	{
		cout << "Invalid Input" << endl;
		cout << "Enter row coordinate (0-4): ";
		cin >> rCord;
	}
	
	cout << "Enter column coordinate (0-4): ";
	cin >> cCord;
	if (cCord < 0 || cCord > 4)
	{
		cout << "Invalid Input" << endl;
		cout << "Enter column coordinate (0-4): ";
		cin >> cCord;
	}

	displayCurrentBoard();
}

void remove()
{
	cout << "Enter row coordinate (0-4): ";
	cin >> rCord;

	cout << "Enter column coordinate (0-4): ";
	cin >> cCord;

	currentBoard[rCord][cCord] = '_';
	printBoard();
}

#endif