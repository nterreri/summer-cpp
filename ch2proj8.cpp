// ch2proj8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int count = 0, years;
	double inflation_converted, inflation, item_cost;
	const unsigned char pounds = 156; // £ sign to display
	
	cout << "Enter the cost of the item:\n"
		<< pounds << " ";
	cin >> item_cost;
	cout << "Enter the inflation rate in %:\n"
		<< "% ";
	cin >> inflation;

	inflation_converted = inflation * 1e-2;

	cout << "Enter the number of years,\n"
		<< "for which the future price of the item is to be estimated:\n";
	cin >> years;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (count < years)
	{
		count++;
		item_cost += item_cost * inflation_converted;

		cout << "The cost of the item after " << count << " year";
		if (count > 1)
			cout << 's';
		cout << " is:\n"
			<< pounds << ' '<< item_cost << endl;
	}
	return 0;
}

