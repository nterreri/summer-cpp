// ch5proj14.cpp : Defines the entry point for the console application.
//Returns windchill index under appropriate input

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

double compute_w(double t, double v);
//Prec: parameters are initialized, and t <= 10; uses cmath
//returns windchill factor

int main()
{
	double t, v, w;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "This program calculates the windchill index.\n"
		<< endl;

	bool input_correct = false;
	do
	{
		cout << "Enter the speed of wind (m/s): ";
		cin >> v;
		cout << "Enter the temperature (Celsius): ";
		cin >> t;
		if (t > 10)
			cout << "Input error, temperature must be lower than 10 °C\n";
		else
			input_correct = true;
	} while (!input_correct);

	w = compute_w(t, v);
	cout << "The windchill factor is: " << w << " degrees Celsius.\n" << endl;
	
	return 0;
}


double compute_w(double t, double v)
{
	return 13.12 + 0.6215 * t - 11.37 * pow(v, 0.16) + 0.3965 * t * pow(v, 0.016);
}