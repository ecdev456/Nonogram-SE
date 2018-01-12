#ifndef ecdev456_H
#define ecdev456_H

#include <iostream>
#include <fstream>
#include "VeronicaLopezNanogram.h"
using namespace std;

void ReadSpecialFile()	//This will read txt file to load previous saved game. "Special File.txt"
{
	ifstream MyFile;
	char input;
	int XCoord = 0;
	int YCoord = 0;
	MyFile.open("Special File.txt");
	{
		while (!MyFile.eof())
		{
			MyFile >> input;
			if (YCoord == 5)	//reset the Y back to 0
			{
				YCoord = 0;
				XCoord++;
			}
			currentBoard[XCoord][YCoord] = input;
			YCoord++;

		}
		MyFile.close();
	}
	//cout << "End Special File" << endl;
}
void SaveToSpecialFile() //User will be writing to the "Special File.txt" in order to save progress.
{
	ofstream eFile;

	eFile.open("Special File.txt");
	{
	for (int i = 0; i < 5; i++)
			{
				for (int x = 0; x < 5; x++)
				{
					eFile << currentBoard[i][x];
				}
			}
	}
	eFile.close();
	cout << "Board Saved! \n" << endl;
}
#endif // 
