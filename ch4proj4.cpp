// ch4proj4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double compute_inflation(double, double);
double futureprice_estimate(double, double);

int main()
{
	double pricely, pricenow, pricefy, pricef2y, inflationr;
	char loopcontrol;
	const unsigned char pounds = 156;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	cout << "This program estimates the rate of inflation based on the change\n"
		<< "in the price of an item across a year.\n\n";

	do
	{
		cout << "Enter the price of the item a year ago:\n" << pounds;
		cin >> pricely;
		cout << "Enter the price of the item now (a year later):\n" << pounds;
		cin >> pricenow;

		inflationr = compute_inflation(pricely, pricenow);
		
		cout << "The estimated rate of inflation is: ";
		cout << inflationr << "%\n\n";

		pricefy = futureprice_estimate(pricenow, inflationr);
		pricef2y = futureprice_estimate(pricefy, inflationr);

		

		cout << "Enter \'y\' to do another calculation,\n"
			<< "or enter something else to quit:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');
	
	cout << endl;
	return 0;
}

double compute_inflation(double pricely, double pricenow)
{
	return ((fabs(pricely - pricenow)) / pricely) * 100;
}

double futureprice_estimate(double current_price, double inflationrate)
{
	//double price_increase = current_price * inflationrate;
	return current_price + (current_price * inflationrate);
}