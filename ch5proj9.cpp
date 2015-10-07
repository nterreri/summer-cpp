// ch5proj9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double OUNCES_IN_POUND = 16;
const double GRAMS_IN_OUNCE = 28.3495231;

void input(double& pounds, double& ounces);
//prec:uses iostream
//postc: pounds and ounces are read

double in_ounces(double pounds, double ounces);
//prec: parameters are initialized
//returns total weight in ounces

double convert(double ounces);
//prec: parameter is initialized
//returns total weight in grams

void output(double grams);
//prec: parameter is initialized, uses iostream
//postc: prints weight in kg - g format

int main()
{
	double pounds, ounces, weight_ounces, weight_grams;
	char loopcontrol = 'y';

	cout << "This program converts weight in imperial units\n"
		<< "to the metric system.\n"
		<< endl;

	do
	{
		input(pounds, ounces);
		weight_ounces = in_ounces(pounds, ounces);
		weight_grams = convert(weight_ounces);
		output(weight_grams);

		cout << endl
			<< "Enter \'y\' to repeat the calculations,\n"
			<< "or enter something else to quit the program:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');
	return 0;
}

void input(double& pounds, double& ounces)
{
	bool input_correct = false;

	while (!input_correct)
	{
		std::cout << "Enter the weight in pounds and ounces separately,\n"
			<< "Pounds: ";
		std::cin >> pounds;
		if (pounds < 0)
		{
			std::cout << "Input formatting error, try again.\n";
			continue;
		}
		std::cout << "Ounces: ";
		std::cin >> ounces;
		if (ounces < 0)
		{
			std::cout << "Input formatting error, try again.\n";
			continue;
		}
		input_correct = true;
	}
}


double in_ounces(double pounds, double ounces)
{
	return ounces + pounds * OUNCES_IN_POUND;
}

double convert(double weight_ounces)
{
	return weight_ounces * GRAMS_IN_OUNCE;
}

void output(double grams)
{
	int kilos = (static_cast<int>(grams) / 1000);

	grams -= 1000 * kilos;

	std::cout.setf(ios::fixed);
	std::cout.setf(ios::showpoint);
	std::cout.precision(2);

	std::cout << "The weight entered in metric units is,\n"
		<< kilos << " kilograms and " << grams << " grams.\n";
}