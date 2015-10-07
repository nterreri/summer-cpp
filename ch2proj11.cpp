// ch2proj11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const int TEN = 10;
	int number, negativesum = 0, positivesum = 0, totalsum, count = 0, positivecount = 0, negativecount = 0;

	while (count < TEN)
	{
		count++;
		cout << "Enter one whole number:\n";
		cin >> number;
		if (number <= 0)
		{
			negativesum += number;
			negativecount++;
		}
		else
		{
			positivesum += number;
			positivecount++;
		}
	}

	totalsum = positivesum + negativesum;

	cout << "The sum of all positive numbers entered is:\n"
		<< positivesum << endl
		<< "The average of all positive numbers entered is:\n"
		<< positivesum / positivecount << endl
		<< "The sum of all non-positive numbers entered is:\n"
		<< negativesum << endl
		<< "The average of all non-positive numbers entered is:\n"
		<< negativesum / negativecount << endl
		<< "The total sum of all numbers entered is:\n"
		<< totalsum << endl
		<< "The total average is:\n"
		<< totalsum / TEN << endl;

	return 0;
}

