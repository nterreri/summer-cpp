// ch3proj16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int c, f = 0;

	cout << "This program calculates a temperature whose value in Celsius\n"
		<< "is the same as the value in Fahrenheit:\n";
	for (c = 100; f != c; c--)
	{
		f = ((9 * c) / 5) + 32;
	}
	cout << "Going down from 100 degrees Celsius, "
		<< f << " is a temperature whose value\n"
		<< "in Fahrenheit is the same as in Celsius.\n";


	return 0;
}

