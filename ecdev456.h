#ifndef ecdev456_H
#define ecdev456_H

#include <iostream>
#include <fstream>
using namespace std;

static char NonoArray[5][5];
void DefaultArray()
{


	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			NonoArray[i][x] = '_';
			
		}
	}
	cout << "Done with initializing" << endl;
}
void ReadSpecialFile()
{
	ifstream MyFile;
	char input;
	int XCoord = 0;
	int YCoord = 0;
	MyFile.open("Special File.txt");
	{
		while (!MyFile.eof())
		{
			MyFile >> input;//noskipws >> input;
			if (YCoord == 5)	//reset the Y back to 0
			{
				YCoord = 0;
				XCoord++;
			}
			NonoArray[XCoord][YCoord] = input;
			YCoord++;

		}
		MyFile.close();
	}
	cout << "End Special File" << endl;
}
void SaveToSpecialFile()
{
	ofstream eFile;

	eFile.open("Special File.txt");
	{
	for (int i = 0; i < 5; i++)
			{
				for (int x = 0; x < 5; x++)
				{
					eFile << NonoArray[i][x];
				}
			}
	}
	eFile.close();
	cout << "Successfully written to the Special file" << endl;
}



void PrintArray()	//TO be deleted, this is self checking
{
	cout << "Printing the Array" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << NonoArray[i][x] << " ";
		}
		cout << endl;
	}
}
#endif // 
