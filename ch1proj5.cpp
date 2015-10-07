// ch1proj5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int integer1, integer2, sum;

	cout << "Type an integer, then press enter:\n";
	cin >> integer1;
	cout << "Type another integer, then press enter:\n";
	cin >> integer2;

	sum = integer1 + integer2;

	cout << "The sum of the integers entered is:\n";
	cout << sum;

	cout << "\nThe program terminates here.\n";
	return 0;
}

