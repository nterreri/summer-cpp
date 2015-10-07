// ch4proj3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double costdouble(int, int, int);

int main()
{
	int nshares, whole, num, denom;
	double costone, costtotal;
	char loopcontrol, punctuation;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do
	{
		cout << "This program takes the number of shares, the price of one share\n"
			<< "divided between the whole part (in dollars) and a fraction of one\n"
			<< "eighth of a dollar.\n\n";

		cout << "Enter the number of shares:\n";
		cin >> nshares;
		cout << "Enter the price, format input as follows: 29 7/8\n"
			<< "Enter the whole part, followed by a fraction:\n";
		cin >> whole;
		cin >> num;
		cin >> punctuation;
		cin >> denom;

		if (punctuation != '/')
		{
			cout << "Input formatting error. Try again.\n\n";
			continue;
		}
		if (nshares <= 0 || whole < 0 || num < 0 || denom < 0)
		{
			cout << "The number of shares must be a positive integer.\n"
				<< "The value of the whole part of the price, numerator\n"
				<< "and denominator must be whole non-zero positive integers.\n\n";
			continue;
		}
		if (denom > 8)
		{
			cout << "The fractional part must be a multiple of one eighth\n"
				<< "of a dollar.\n\n";
			continue;
		}

		costone = costdouble(whole, num, denom);

		costtotal = costone * nshares;
		
		cout << "The total price of the shares is: $\n";
		cout << costtotal << endl << endl;

		cout << "If you would like to repeat the calculation enter \'y\',"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');

	

	return 0;
}

double costdouble(int whole, int num, int denom)
{
	return whole + static_cast<double>(num) / denom;
}