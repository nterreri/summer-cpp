// ch1proj8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int quarters, dimes, nickles, total;

	cout << "Enter the number of quarters:\n";
	cin >> quarters;
	cout << "Enter the number of dimes:\n";
	cin >> dimes;
	cout << "Enter the number of nickles:\n";
	cin >> nickles;

	total = quarters * 25 + dimes * 10 + nickles * 5;

	cout << "You have ";
	cout << total;
	cout << " cents.\n";
	return 0;
}

