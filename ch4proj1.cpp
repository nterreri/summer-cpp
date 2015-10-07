// ch4proj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double GALLONSINLITER = 0.264179;

double miles_pergallon(double, double);

int main()
{
	double gas_liters, gas_gallons, miles;
	char loopcontrol;

	do
	{
		cout << "This program calculates the numer of miles per gallon of gasoline\n"
			<< "delivered by a car, from a number of miles driven and the amount of\n"
			<< "gasoline it took to drive them in liters.\n";
		cout << "Enter the amount of liters consumed: ";
		cin >> gas_liters;
		cout << "Enter the amount of miles driven: ";
		cin >> miles;

		gas_gallons = gas_liters * GALLONSINLITER;
		cout << "The car drove for: ";
		cout << miles_pergallon(gas_gallons, miles) << " miles per gallon\n";

		cout << "If you would like to repeat the calculation enter \'y\',\n"
			<< "otherwise enter something else:";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');
	

	return 0;
}

double miles_pergallon(double gallons, double miles)
{
	return miles / gallons;
}