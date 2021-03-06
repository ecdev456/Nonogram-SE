#pragma once
#include <iostream>
#include <string>

using namespace std;
static int actNum[5][5];	//checking active numbers
static int rulloGrid[5][5];	//these where the numbers will be
static int hAct[5] = { 0,0,0,0,0 };	// set to not finished horizontal
static int vAct[5] = { 0,0,0,0,0 };	// set to not finished vertical

class Model {
private:
	int game;	//1 will be Rullo , 2 will be Picross
	bool HCheck[5];	// Boolean array where each is assigned true or false if valid mathematics for pertaining row.
	bool VCheck[5]; // Boolean array where each is assigned true or false if valid mathematics for pertaining column.
public:
	Model() //initialize values to false.
	{
		game = 0;
		for (int i = 0; i < 5; i++)
		{
			HCheck[i] = false;
			VCheck[i] = false;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				actNum[i][j] = 1;
			}
		}

	}
	bool HPrint(int i)
	{
		return HCheck[i];
	}
	void CheckMath() //Needs vertical checking
	{
		//Horizontal math checking.  Seperate 2-d array checking active/non-active values
		//active values will be added and checked to the Final sum of that Row.
		//Non-active will not be added.
		int HSum; //This will be checking the neccessary sum with the current sum.(HSum gets only from active values)
		int j = 0; //in charge of the rows
		bool done = false;
		while (!done)
		{
			for (int i = 0; i < 5; i++)	//checking each spot on row, will later change row when 'j++' reached
			{
				if (actNum[j][i] == 1)
				{
					HSum += rulloGrid[i][j];
				}
			}
			if (HSum == hSum[j])	// If sum is correct then activates correct spot.
			{
				hAct[j] = 1;
			}
			if (HSum != hSum[j])	//resets it back to not active when not equal
			{
				hAct[j] = 0;
			}
			if (j == 4) { done = true; }	//exit the while loop
			else
				j++;
		}
	}
	bool CheckWin()	// All actives need to be set to '1' = true the are solved and win is permitted.
	{
		//check board for all appropriate active
		for (int i = 0; i < 5; i++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (actNum[i][j] != 1){ return false;}
			}
		}
		// Board has appropriate active, now needs to check the sides if ready.
		for (int i = 0; i < 5; i++)
		{
			if (hAct[i] != 1){ return false;}
			if (vAct[i] != 1){ return false;}
		}

		//if reached this point then all are good
		return true;
	}
};
