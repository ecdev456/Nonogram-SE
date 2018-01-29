#pragma once
#ifndef view_h
#define view_h
#include <iostream>
#include <Windows.h>
#include "model.h"

using namespace std;
extern int actNum[5][5] =
{
	{ 1,1,1,1,1 },
	{ 1,1,1,1,1 },
	{ 1,1,1,1,1 },
	{ 1,1,1,1,1 },
	{ 1,1,1,1,1 }
};
extern int rulloGrid[5][5] =
{
	{ 3,2,6,5,2 },
	{ 3,7,1,1,7 },
	{ 5,1,5,2,6 },
	{ 2,9,6,6,7 },
	{ 2,6,5,2,4 }
};//rullo grid

class view {
	friend class model;
	static const int size = 5;

private:
	
	char picrossGrid[size][size];//stores information of picross grid

	int vValues[size] = { 13,16,12,23,02 };
	int hValues[size] = { 9,17,13,12,15 };
	int rowP, columnP; //picross coordinate selection
	int rowRullo, columnRullo; //rullo coordinate selection

	//winRow and winCol stores the coordinates for winning the puzzle
	int winRow[13] = { 0,1,2,3,4,1,2,1,0,1,2,3,4 };
	int winCol[13] = { 0,0,0,0,0,1,2,3,4,4,4,4,4 };

	//emptyRow and emptyCol are the coordinates for the grid that are supposed ot be empty
	int emptyRow[12] = { 0,2,3,4,0,1,3,4,0,2,3,4 };
	int emptyCol[12] = { 1,1,1,1,2,2,2,2,3,3,3,3 };

public:
	view()
	{
		//initiallize picross grid info 
		for (int row = 0; row < 5; row++)
		{
			for (int column = 0; column < 5; column++)
			{
				picrossGrid[row][column] = '_';
			}
		}
	}

	~view()
	{

	}

	void picrossInput()
	{
		cout << "Enter row coordinate (0-4): ";
		cin >> rowP;
		while (rowP < 0 || rowP > 4) //checks to see if you have entered a valid input for row coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter row coordinate (0-4): ";
			cin >> rowP;
		}

		cout << "Enter column coordinate (0-4): ";
		cin >> columnP;
		while (columnP < 0 || columnP > 4) //checks to see if you have entered a valid input for column coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter column coordinate (0-4): ";
			cin >> columnP;
		}

		addCoordBoard();
	}

	void rulloInput()
	{
		cout << "Enter row coordinate (0-4): ";
		cin >> rowRullo;
		while (rowRullo < 0 || rowRullo > 4) //checks to see if you have entered a valid input for row coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter row coordinate (0-4): ";
			cin >> rowRullo;
		}

		cout << "Enter column coordinate (0-4): ";
		cin >> columnRullo;
		while (columnRullo < 0 || columnRullo > 4) //checks to see if you have entered a valid input for column coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter column coordinate (0-4): ";
			cin >> columnRullo;
		}
		actNum[rowRullo][columnRullo] = 0;
	}

	//prints Picross Grid
	void printPicross()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
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
			if (row == 0 || row == 3 || row == 4)
			{
				cout << "  1 1";
			}
			for (int column = 0; column < 5; column++)
			{

				cout << "|_";
				if (picrossGrid[row][column] == 'X')
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << picrossGrid[row][column];
					SetConsoleTextAttribute(hConsole, 14);
				}
				else {
					SetConsoleTextAttribute(hConsole, 14);
					cout << picrossGrid[row][column];
				}

				cout << "_";
			}
			cout << "|";
			cout << endl;
		}
	}

	void addCoordBoard()
	{

		picrossGrid[rowP][columnP] = 'X';
		printPicross();
	}

	void printRullo()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		cout << "    ";
		for (int i = 0; i < size; i++)
		{
			if (vAct[i] == 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << hValues[i] << "  ";
				SetConsoleTextAttribute(hConsole, 14);
			}
			else
			{
				cout << hValues[i] << "  ";
			}
		}
		cout << endl;

		for (int row = 0; row < 5; row++)
		{
			if (hAct[row] == 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << vValues[row];
				SetConsoleTextAttribute(hConsole, 14);
			}
			else
			{
				cout << vValues[row];
			}
			
			if (row == 4)
			{
				cout << " ";
			}
			for (int column = 0; column < 5; column++)
			{

				cout << "|_";

				if (actNum[row][column] == 0)
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << rulloGrid[row][column];
					SetConsoleTextAttribute(hConsole, 14);
				}
				else {
					SetConsoleTextAttribute(hConsole, 14);
					cout << rulloGrid[row][column];
				}

				cout << "_";
			}
			cout << "|";
			cout << endl;
		}
	}
	void removePicross() //takes in new coordinates for row and column and removed the X value
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "Enter row coordinate (0-4): ";
		cin >> rowP;
		while (rowP < 0 || rowP > 4) //checks to see if you have entered a valid input for row coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter row coordinate (0-4): ";
			cin >> rowP;
		}

		cout << "Enter column coordinate (0-4): ";
		cin >> columnP;
		while (columnP < 0 || columnP > 4) //checks to see if you have entered a valid input for column coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter column coordinate (0-4): ";
			cin >> columnP;
		}
		SetConsoleTextAttribute(hConsole, 14);
		picrossGrid[rowP][columnP] = '_'; //replace any value to underscore
		printPicross();
		
		//checkM.CheckMath();
	}

	void removeRullo() //takes in new coordinates for row and column and removed the X value
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "Enter row coordinate (0-4): ";
		cin >> rowRullo;
		while (rowRullo < 0 || rowRullo > 4) //checks to see if you have entered a valid input for row coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter row coordinate (0-4): ";
			cin >> rowRullo;
		}

		cout << "Enter column coordinate (0-4): ";
		cin >> columnRullo;
		while (columnRullo < 0 || columnRullo > 4) //checks to see if you have entered a valid input for column coordinate
		{
			cout << "Invalid Input" << endl;
			cout << "Enter column coordinate (0-4): ";
			cin >> columnRullo;
		}
		SetConsoleTextAttribute(hConsole, 14);
		actNum[rowRullo][columnRullo] = 1;
		rulloGrid[rowRullo][columnRullo];// = '_'; //replace any value to underscore
		//printRullo();
	}
	bool checkWinPicross()
	{
		int count = 0;//at the end there should be 13 X's, so this keeps track of them
		bool win;
		for (int i = 0; i < 13; i++)
		{
			if (picrossGrid[winRow[i]][winCol[i]] == 'X')
			{
				count++;
			}
		}
		if (count == 13) //if the user reaches to 13 X's check to see if they didn't have any extra X's
		{
			for (int j = 0; j < 12; j++)
			{
				if (picrossGrid[emptyRow[j]][emptyCol[j]] == 'X')
				{
					win = false; //if you see an X where is shouldn't be return false;
					return win;
				}
			}
			win = true;//else return true
			cout << "Congradulations, you won!!! " << endl;
			return win;
		}
		else
		{
			win = false; //returns false if count didn't reach to 13
			return win;
		}
	}
};
#endif