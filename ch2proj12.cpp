// ch2proj12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double n, r, guess, pguess;

	cout << "Enter the number whose square root is to be guessed:\n";
	cin >> n;
	
	guess = n / 2;
	//cout << guess << endl;

	do
	{
		r = n / guess;
		pguess = guess;
		guess = (guess + r) / 2;
		//cout << guess << endl;
	} while ((pguess - guess) > (0.01 * pguess));
	
	cout << "A reasonable guess is:\n"
		<< guess << endl;

	return 0;
}

