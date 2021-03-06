// ch2proj3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const double BONUSPERCENT = 7.6;
	double bonusannual, pannual, nannual;
	const unsigned char pounds = 156;
	char loopcontrol;

	do
	{
		cout << endl << "Enter the previous annual salary:\n";
		cout << pounds << ' ';
		cin >> pannual;

		bonusannual = (pannual) * (BONUSPERCENT / 100);
		nannual = pannual + bonusannual;

		cout << endl << "Since the 7,6% bonus is retroactive for six months,\n"
			<< "The employees who have won the bonus are due: " << pounds << ' ' << bonusannual / 2 << endl
			<< "The new annual salary amounts to:\n"
			<< pounds << ' ' << nannual << endl
			<< "The new monthly salary amounts to:\n"
			<< pounds << ' ' << nannual / 12 << endl;
		cout << "If you would like to repeat the calculation enter 'y',\n"
			<< "(lowercase):\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');

	return 0;
}

