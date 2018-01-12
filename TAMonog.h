#ifndef Assignment1_H
#define Assignment1_H
#include <iostream>
using namespace std;

void Menu(char choice) {
	do {
		switch (choice) {

		case 'A':
			cout << " Where would you like to add your 'X'? ";
			//input Veronica's function 
			break;
		case 'a':
			cout << " Where would you like to add your 'X'? ";
			//input Veronica's function
			break;
		case 'R':
			cout << " Which 'X' would you like to remove? ";
			//input Veronica's function
			break;
		case 'r':
			cout << " Which 'X' would you like to remove? ";
			//input Veronica's function
			break;
		case 'Q':
			cout << " Would you like to save your game? ";
			//Edwin's Quit function
			break;
		case 'q':
			cout << " Would you like to save your game? ";
			//Edwin's Quit function
			break;
		}
	}
	
	while ((choice!= 'Q'||choice!='q')&& checkwins!=true)
		//Veronica please check and get back to me on this part.
	
}
