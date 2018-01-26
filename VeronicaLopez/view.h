#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class view {
private:
	static const int size = 5;
	int actNum[size][size];
	char picrossGrid[size][size];
	int rulloGrid[size][size];
	int vSum[size];
	int hSum[size];
public:
	view()
	{

	}

	~view()
	{

	}

	void createGrid()
	{


	}

	//creates one puzzle
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
};