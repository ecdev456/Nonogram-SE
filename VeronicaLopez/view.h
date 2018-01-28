#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class view {
private:
	static const int size = 5;
	int actNum[size][size];
	char picrossGrid[size][size];//stores information of picross grid
	int rulloGrid[size][size] = 
	{
		{ 3,2,6,5,2 },
		{ 3,7,1,1,7 },
		{ 5,1,5,2,6 },
		{ 2,9,6,6,7 },
		{ 2,6,5,2,4 }
	};//rullo grid
	int hSum[size] = { 9,17,13,12,15 };
	int vSum[size] = { 13,16,12,23,02 };
	int rowP, columnP; //picross coordinate selection
	int rowRullo, columnRullo; //rullo coordinate selection
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

		//intiallize picross array info
	
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

		printRullo();
	}

	//prints Picross Grid
	void printPicross()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 2);
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
					SetConsoleTextAttribute(hConsole, 1);
					cout << picrossGrid[row][column];
					SetConsoleTextAttribute(hConsole, 2);
				}
				else {
					SetConsoleTextAttribute(hConsole, 2);
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
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    ";
		for (int i = 0; i < size; i++)
		{
			cout << hSum[i] << "  ";
		}
		cout << endl;

		for (int row = 0; row < 5; row++)
		{
			cout << vSum[row];
			if (row == 4)
			{
				cout << " ";
			}
			for (int column = 0; column < 5; column++)
			{
				
				cout << "|_";
				cout << rulloGrid[row][column];
				/*
				if (rulloGrid[row][column] == 'X')
				{
					SetConsoleTextAttribute(hConsole, 1);
					cout << picrossGrid[row][column];
					SetConsoleTextAttribute(hConsole, 2);
				}
				else {
					SetConsoleTextAttribute(hConsole, 2);
					cout << picrossGrid[row][column];
				}*/

				cout << "_";
			}
			cout << "|";
			cout << endl;
		}
	}
};