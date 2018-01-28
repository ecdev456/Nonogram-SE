#pragma once
#include <iostream>
#include <cstdlib>
#include "view.h"
using namespace std;

// valid choices for commands
// This is a C++11 feature, so you do need
// to set your project options accordingly

view View;

void handleDisplay()
{
	//Veronica's view function for displaying Grid
}
void handleQuit() {
	exit(0);
};

void handleGame() {

};

int main() {
	char choose;
	cout << "Menu: \n" << "Choose your game (Rullo or Picross) \n"
		<< " Enter 'P' or 'p' to play Picross or 'R' or 'r' to play Rullo. \n"
		<< " Enter 'D' or 'd' to display Picross Grid. \n"
		<< " Enter 'Q' or 'q' to quit game. \n";


	
	do
	{	
		cout << "What would you like to do? ";
		cin >> choose;
		switch (choose) {
		

		case 'R':
		case 'r':
			cout << "Getting Grid ready for Rullo..." << endl;
			View.printPicross(); //same grid so user see's it first and then adds their input
			View.rulloInput();  //rullo input second
			//Model check Math functions
			break;


		case 'P':
		case 'p':
			cout << "Getting Grid ready for Picross.."<< endl;
			View.printPicross(); //same picross grid so that the user see's int first and then adds 
								//their input
			View.picrossInput();  //Picross input second
			break;

		case 'D':
		case 'd':
			cout << "Pulling up Grid..." << endl;  //if  user just wants to see 
			View.printPicross();					//what the grid looks like


		case 'Q':
		case 'q':
			cout << "... Quitting game" << endl;

			//edwin's load function(?)
			break;
		default:
			cout << "Invalid Option" << endl;
		}
	} while (choose!= 'Q' || choose != 'q');

	if (choose != 'Q' || choose != 'q' || choose != 'P' || choose != 'p')
		cout << "Invalid Option";
	// continue code
	else if (choose != 'D' || choose != 'd' || choose!= 'Q' || choose!= 'q')
		cout << "Invalid Option ";
	//continue code.



};
