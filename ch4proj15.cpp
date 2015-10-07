// ch4proj15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double coin_sum(char, double);
double count_change(double);

int main()
{
	char coin;
	double total = 0;


	cout << "This program works as a vending machine for deep fried twinkies,\n"
		<< "priced at 3.50 each.\n";

	while (total < 3.50)
	{
		cout << "Insert coins: $ (for whole dollars), Q (for a quarter),\n"
			<< "D (for dimes), N (for nickles): ";
		cin >> coin;
		total = coin_sum(coin, total);
		cout << "Credit: " << total << "$" << endl;

		//cout << total;
	}

	cout << endl;

	cout << "Chage due: " << count_change(total) << "$" << endl;

	cout << "Enjoy your deep-fried twinkie.\n";
	return 0;
}

double coin_sum(char coin, double total)
{
	switch (coin)
	{
	case '$':
		total += 1;
		break;
	case 'Q':
	case 'q':
		total += 0.15;
		break;
	case 'D':
	case 'd':
		total += 0.10;
		break;
	case 'N':
	case 'n':
		total += 0.05;
		break;
	default:
		cout << "Input error.\n";
	}
	return total;
}

double count_change(double total)
{
	double change = 0;
	if (total > 3.50)
		change = total - 3.50;

	return change;
}