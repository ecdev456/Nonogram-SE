#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class view {
private:
	static const int size = 5;
	int actNum[size][size];
	char picrossGrid[size][size];//stores information of picross grid
	int rulloGrid[size][size];//rullo grid
	int vSum[size];
	int hSum[size];
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
		int picrossGrid[size][size] =
		{
			{2,6,6,9,4},
			{4,2,2,1,2},
			{8,7,2,2,3},
			{3,9,7,3,8},
			{6,7,4,9,4}
		};

	}

	~view()
	{

	}

	void createGrid()
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

		//displayCurrentP();
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
};