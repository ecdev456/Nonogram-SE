#include <iostream>
#include "viewTest.h"
#include "model.h"

using namespace std;

int main()
{
	view v;

	//I will test to make sure what the user inputs is actually what is being printed
	char a[5][5] = {
		{ '_','_','_','_','_' },
		{ '_','_','_','_','_' },
		{ '_','_','_','_','_' },
		{ '_','_','_','_','_' },
		{ '_','_','_','_','_' }
	};
	v.setPicross(5, 5,a);
	cout << "Test 1, expected for it to respond in false (didn't win)" << endl;
	if (v.checkWinPicross() == 0)
	{
		cout << "Test was a success\n" << endl;
	}
	else
	{
		cout << "Test failed\n" << endl;
	}
	
	char b[5][5] = {
		{ 'X','X','X','X','X' },
		{ 'X','X','X','X','X' },
		{ 'X','X','X','X','X' },
		{ 'X','X','X','X','X' },
		{ 'X','X','X','X','X' }
	};
	v.setPicross(5, 5, b);
	cout << "Test 2, Expected for it to respond in false (didn't win)" << endl;
	if (v.checkWinPicross() == 0)
	{
		cout << "Test was a success\n" << endl;
	}
	else
	{
		cout << "Test failed\n" << endl;
	}

	char c[5][5] = {
		{ 'X','_','_','_','X' },
		{ 'X','X','_','X','X' },
		{ 'X','_','X','_','X' },
		{ 'X','_','_','_','X' },
		{ 'X','_','_','_','X' }
	};
	v.setPicross(5, 5, c);
	cout << "Test 3, Expected for it to respond in true (user won)" << endl;
	if (v.checkWinPicross() == 1)
	{
		cout << "Test was a success\n" << endl;
	}
	else
	{
		cout << "Test failed\n" << endl;
	}
	
}