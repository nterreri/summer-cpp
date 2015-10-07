// ch5proj8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double METERS_IN_FOOT = 0.3048;
const double METERS_IN_INCH = 0.0254;
const double INCHES_IN_METER = 39.37;

void input(double& feet, double& inches);
//Prec: none
//Postc: by-reference parameters are read in feet - inch format

void input(double& meters);
//Prec: none
//Postc: by-reference parameter is read in meters

void output(double measure, bool flag);
//Prec: parameter is initialized, flag parameter is initialized to activate different
//sections of the function, accounting for different output formats
//Postc: parameter is printed

double convert(double feet, double inches);
//Prec: lenght in imperial system is initialized
//Returns length in metric system

double convert(double meters);
//Prec: length in meters is initialized
//Returns length in inches

void imperial_to_metric();
//prec: none
//postc: prompts user for input in imperial unit and converts
//it to metric units, then prints the result

void metric_to_imperial();
//prec: none
//postc: prompts user for input in metric units,
//converts the input to imperial units,
//then prints this result

int main()
{
	char choice, loopcontrol = 'y';

	cout << "This program converts length unit measures from the imperial system\n"
		<< "to the metric system OR viceversa.\n"
		<< endl;

	do
	{
		cout << "Enter 1 to convert from imperial to metric,\n"
			<< "or 2 to convert from metric to imperial:\n";

		cin >> choice;
		if (choice == '1')
			imperial_to_metric();
		else if (choice == '2')
			metric_to_imperial();
		else
		{
			cout << "Input formatting error.\n"
				<< "Please try again.\n";
			continue;
		}

		cout << "If you would like to run through the program again enter \'y\'\n"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');
	return 0;
}

void imperial_to_metric()
{
	double feet, inches, metric;
	bool flag = true; //these flags activate different sections of output(double)
	//to account for the different output formats

	input(feet, inches);
	metric = convert(feet, inches);
	output(metric, flag);
}

void metric_to_imperial()
{
	double meters, inches;
	bool flag = false; //see previous comment

	input(meters);
	inches = convert(meters);
	output(inches, flag);
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

void input(double& meters)
{
	bool correct_input = false;

	while (!correct_input)
	{
		std::cout << "Enter the length:\n";
		std::cout << "Meters: ";
		std::cin >> meters;
		if (meters < 0)
		{
			std::cout << "Input formatting error.\n";
			continue;
		}
		correct_input = true;
	}
}


void output(double length, bool flag)
{
	if (flag)
	{
		double metric = length;
		std::cout.setf(ios::fixed);
		std::cout.setf(ios::showpoint);
		std::cout.precision(3);

		int meters_buffer = static_cast<int>(metric);
		std::cout << "The length in the metric system measures "
			<< meters_buffer << " meters,\n"
			<< "and " << (metric - meters_buffer) * 100 << " centimeters.\n";
	}
	
	else
	{
		double inches = length;
		int feet = static_cast<int>(inches);

		feet /= 12;
		inches -= 12.0 * feet;

		std::cout.setf(ios::fixed);
		std::cout.setf(ios::showpoint);
		std::cout.precision(2);

		std::cout << "The length in the imperial system measures "
			<< feet;
		if (feet != 1)
			std::cout << " feet,\n";
		else
			std::cout << " foot,\n";

		std::cout << "and " << inches << " inch";
		if (inches != 1)
			std::cout << "es.\n";
		else
			std::cout << ".\n";
	}
}

double convert(double feet, double inches)
{
	return feet * METERS_IN_FOOT + inches * METERS_IN_INCH;
}

double convert(double meters)
{
	return (meters * INCHES_IN_METER);
}