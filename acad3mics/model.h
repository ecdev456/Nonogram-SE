//
//  model.h
//  rulo
//
//  Created by faraz ismail on 1/25/18.
//  Copyright © 2018 acad3mics. All rights reserved.
// adapting edwin cano's code to take care of vertical rows on board corresponding to the horizontal

#ifndef model_h
#define model_h
#pragma once
#include <iostream>
#include <string>
#include "view.h"

using namespace std;
 int actNum[5][5];	//checking active numbers
 int rulloGrid[5][5];	//these where the numbers will be
extern int hAct[5] = { 0,0,0,0,0 };	// set to not finished horizontal
extern int vAct[5] = { 0,0,0,0,0 };	// set to not finished vertical
int hSum[5] = { 13,16,12,23,02  };
int vSum[5] = { 9,17,13,12,15 };

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

	}
	bool HPrint(int i)
	{
		return HCheck[i];
	}
	bool VPrint(int i) {
		return VCheck[i];
	}
	void CheckMath() //Needs vertical checking
	{
		//Horizontal math checking.  Seperate 2-d array checking active/non-active values
		//active values will be added and checked to the Final sum of that Row.
		//Non-active will not be added.
		int HSum = 0;
		int JSum= 0; //This will be checking the neccessary sum with the current sum.(HSum gets only from active values)
		int j = 0, col = 0; //in charge of the rows
		bool done = false;
		while (!done)
		{
			for (int i = 0; i < 5; i++)	//checking each spot on row, will later change row when 'j++' reached
			{
				if (actNum[j][i] == 1)
				{
					//cout << "Before: " << HSum << endl;
					HSum += rulloGrid[j][i];
				//	cout << "HSum = " << HSum << " rulloGrid[i][j]: " << rulloGrid[j][i] << endl;
				}
				if (actNum[i][j] == 1) // check vertically by indexing through columns for ON value
				{
					JSum += rulloGrid[i][j];
				}
				/*if (i == 5)
				{
					//HSum = 0;
					return;
				}*/
			}
			//cout << "HSum value is: " << HSum << " hSum[j]: " << hSum[j] << endl;
			// Question to edwin Where is hSum[] declared? I dont see it declared anywhere but I will use vSum to follow your logic AND I declared it up top just below int to avoid any errors.
			if (HSum == hSum[j])	// If sum is correct then activates correct spot.
			{
				hAct[j] = 1;
			}
			if (JSum == vSum[j]) {
				vAct[col] = 1;
			}
			if (HSum != hSum[j])	//resets it back to not active when not equal
			{
				hAct[j] = 0;
			}
			if (JSum != vSum[j]) {
				vAct[col] = 0;
			}
			// This will have to be modified for vertical checking to work so i doubled the increment variables to j and col.
			if (j == 4 && col == 4) { done = true; }	//exit the while loop
			else
				HSum = 0;
				JSum = 0;
			j++;
			col++;
		}
	}

	bool CheckWin()	// All actives need to be set to '1' = true the are solved and win is permitted.
	{
	
		// Board has appropriate active, now needs to check the sides if ready.
		for (int i = 0; i < 5; i++)
		{
			if (hAct[i] != 1) { return false; }
			if (vAct[i] != 1) { return false; }
		}

		//if reached this point then all are good
		cout << "Congradulations! You won the game!!" << endl;
		return true;
	}

	
};

#endif /* model_h */