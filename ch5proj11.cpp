// ch5proj11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double OUNCES_IN_POUND = 16;
const double GRAMS_IN_OUNCE = 28.3495231;
const double GRAMS_IN_KG = 1000;
const double OUNCES_IN_GRAMS = 0.0352739619;

void input(double& larger, double& smaller, bool metric_flag);
//prec:uses iostream, metric_flag when true activates the part of the
//function taking in metric input
//postc: larger and smaller unit measure variables are read

double in_ounces(double pounds, double ounces);
//prec: parameters are initialized
//returns total weight in ounces

double in_grams(double kgs, double g);
//prec: parameters are initialized
//returns total weight in smaller unit measure

double convert(double grams);
//prec: parameter is initialized
//returns total weight in grams converted to ounces

double convert(double ounces, bool flag);
//prec: parameter is initialized, flag is a dummy value for overloading
//the "convert()" function name
//returns total weight in ounces converted to grams

void output(double smaller_converted, bool metric_flag);
//prec: parameter is initialized, uses iostream
//"metric_flag" when true activates the part of the function formatting
//metric units output
//postc: prints weight in larger - smaller format

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

void input(double& larger_unit, double& smaller_unit, bool metric_flag)
{
	bool input_correct = false;

	if (metric_flag)
	{
		while (!input_correct)
		{
			std::cout << "Enter the weight in kgs and grams separately,\n"
				<< "Kgs: ";
			std::cin >> larger_unit;
			if (larger_unit < 0)
			{
				std::cout << "Input formatting error, try again.\n";
				continue;
			}
			std::cout << "Grams: ";
			std::cin >> smaller_unit;
			if (smaller_unit < 0)
			{
				std::cout << "Input formatting error, try again.\n";
				continue;
			}
			input_correct = true;
		}
	}
	
	else
	{
		while (!input_correct)
		{
			std::cout << "Enter the weight in pounds and ounces separately,\n"
				<< "Pounds: ";
			std::cin >> larger_unit;
			if (larger_unit < 0)
			{
				std::cout << "Input formatting error, try again.\n";
				continue;
			}
			std::cout << "Ounces: ";
			std::cin >> smaller_unit;
			if (smaller_unit < 0)
			{
				std::cout << "Input formatting error, try again.\n";
				continue;
			}
			input_correct = true;
		}
	}
}

double in_ounces(double pounds, double ounces)
{
	return ounces + pounds * OUNCES_IN_POUND;
}

double in_grams(double kg, double g)
{
	return g + kg * GRAMS_IN_KG;
}

double convert(double weight_ounces, bool flag)
{
	return weight_ounces * GRAMS_IN_OUNCE;
}

double convert(double weight_grams)
{
	return weight_grams * OUNCES_IN_GRAMS;
}

void output(double smaller_unit, bool metric_flag)
{
	if (metric_flag)
	{
		double grams = smaller_unit;
		int kilos = (static_cast<int>(grams) / 1000);

		grams -= 1000 * kilos;

		std::cout.setf(ios::fixed);
		std::cout.setf(ios::showpoint);
		std::cout.precision(2);

		std::cout << "The weight entered in metric units is,\n"
			<< kilos << " kilograms and " << grams << " grams.\n";
	}
	else
	{
		double ounces = smaller_unit;
		int pounds = (static_cast<int>(ounces) / 16);

		ounces -= 16 * pounds;

		std::cout.setf(ios::fixed);
		std::cout.setf(ios::showpoint);
		std::cout.precision(2);

		std::cout << "The weight entered in imperial units is,\n"
			<< pounds << " pound";
		if (pounds != 1)
			std::cout << "s";
		std::cout << " and " << ounces << " ounce";
		if (ounces != 1)
			std::cout << "s";
		std::cout << ".\n";
	}
}

void imperial_to_metric()
{
	double pounds, ounces, weight_ounces, weight_grams;
	bool metric_flag = false, imperial_to_metric_conversion = true;

		input(pounds, ounces, metric_flag);
		weight_ounces = in_ounces(pounds, ounces);
		weight_grams = convert(weight_ounces, imperial_to_metric_conversion);
		output(weight_grams, !metric_flag);
}

void metric_to_imperial()
{
	double kg, g, weight_ounces, weight_grams;
	bool metric_flag = true;

		input(kg, g, metric_flag);
		weight_grams = in_grams(kg, g);
		weight_ounces = convert(weight_grams);
		output(weight_ounces, !metric_flag);
}