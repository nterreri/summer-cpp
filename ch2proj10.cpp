// ch2proj10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const int TEN = 10;
	int number, negativesum = 0, positivesum = 0, totalsum, count = 0;

	while (count < 10)
	{
		count++;
		cout << "Enter one whole number:\n";
		cin >> number;
		if (number <= 0)
			negativesum += number;
		else
			positivesum += number;
	}

	totalsum = positivesum + negativesum;

	cout << "The sum of all positive numbers entered is:\n"
		<< positivesum << endl
		<< "The sum of all negative sumbers entered is:\n"
		<< negativesum << endl
		<< "The total sum of all numbers entered is:\n"
		<< totalsum;

	return 0;
}

