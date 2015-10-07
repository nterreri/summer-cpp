// ch5proj6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double METERS_IN_FOOT = 0.3048;
const double METERS_IN_INCH = 0.0254;

void input(double& feet, double& inches);
//Prec: none
//Postc: by-reference parameters are read

void output(double metric);
//Prec: parameter is initialized
//Postc: parameter is printed

double convert(double feet, double inches);
//Prec: imperial is initialized
//Returns length in metric system

int main()
{
	double feet, inches, metric;
	char loopcontrol;

	cout << "This program converts a lenght given in the imperial system\n"
		<< "to the metric system.\n"
		<< endl;

	do
	{
		input(feet, inches);
		metric = convert(feet, inches);
		output(metric);

		cout << "If you would like to repeat the calculation enter \'y\'\n"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');

	return 0;
}

void input(double& feet, double& inches)
{	
	bool correct_input = false;

	while (!correct_input)
	{
		std::cout << "Enter the length\n";
		std::cout << "Feet: ";
		std::cin >> feet;
		if (feet < 0)
		{
			std::cout << "Input formatting error.\n";
			continue;
		}
			
		std::cout << "Inches: ";
		std::cin >> inches;
		if (inches < 0 || inches > 11)
		{
			std::cout << "Input formatting error.\n";
			continue;
		}
		correct_input = true;
	}
	
}

void output(double metric)
{
	std::cout.setf(ios::fixed);
	std::cout.setf(ios::showpoint);
	std::cout.precision(3);

	int meters_buffer = static_cast<int>(metric);
	std::cout << "The length in the metric system measures "
		<< meters_buffer << " meters,\n"
		<< "and " << (metric - meters_buffer) * 100 << " centimeters.\n";
}

double convert(double feet, double inches)
{ 
	return feet * METERS_IN_FOOT + inches * METERS_IN_INCH;
}