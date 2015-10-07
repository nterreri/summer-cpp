// ch4proj7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double const G = 6.673e-8;
double gforce(double, double, double);

int main()
{
	/*cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);*/
	double mass1, mass2, distance;

	cout << "This program calculates the gravitational force between two objects\n"
		<< "in unit measure \'dynes\'.\n\n";
	while (true)
	{
		cout << "Enter the mass of one object (in grams): ";
		cin >> mass1;
		if (mass1 <= 0)
			exit(0);
		cout << "Enter the mass of the other objects (in grams): ";
		cin >> mass2;
		if (mass2 <= 0)
			exit(0);
		cout << "Enter the distance between the objects (in cm): ";
		cin >> distance;
		if (distance <= 0)
			exit(0);
		
		cout << "The gravitational force between the objects amounts to: ";
		cout << gforce(mass1, mass2, distance) << " dynes\n\n";
		
		cout << "Enter a negative number at any point to quit the program.\n";
	}
	
	return 0;
}

double gforce(double mass1, double mass2, double distance)
{
	return (G * mass1 * mass2) / (distance*distance);
}

