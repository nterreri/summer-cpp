// ch4proj2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double GALLONSINLITER = 0.264179;

double miles_pergallon(double, double);

int main()
{
	double gas_liters1, miles1, efficiency1, gas_liters2, miles2, efficiency2;
	char loopcontrol;

	do
	{
		cout << "This program calculates the numer of miles per gallon of gasoline\n"
			<< "delivered by two cars and confronts these values to decide which car\n"
			<< "is more efficient.\n"
			<< "It takes the number of miles driven and the amount of\n"
			<< "gasoline it took to drive them in liters for each car separately.\n\n";
		cout << "First car\n";
		cout << "Enter the amount of liters consumed by the first car: ";
		cin >> gas_liters1;
		cout << "Enter the amount of miles driven by the first car: ";
		cin >> miles1;
		efficiency1 = miles_pergallon(gas_liters1, miles1);

		cout << "Second car\n";
		cout << "Enter the amount of liters consumed by the second car: ";
		cin >> gas_liters2;
		cout << "Enter the amount of miles driven by the second car: ";
		cin >> miles2;
		efficiency2 = miles_pergallon(gas_liters2, miles2);

		
		cout << "The first car drove for: ";
		cout << efficiency1 << " miles per gallon\n";

		cout << "The second car drove for: ";
		cout << efficiency2 << " miles per gallon\n\n";

		if (efficiency1 > efficiency2)
			cout << "The first car is the most efficient.\n\n";
		else if (efficiency1 == efficiency2)
			cout << "Both cars are equally efficient.\n";
		else
			cout << "The second car is the most efficient.\n\n";

		cout << "If you would like to repeat the calculation enter \'y\',\n"
			<< "otherwise enter something else:";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');


	return 0;
}

double miles_pergallon(double liters, double miles)
{
	double gallons;

	gallons = liters * GALLONSINLITER;
	return miles / gallons;
}