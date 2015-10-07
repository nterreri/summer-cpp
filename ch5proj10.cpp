// ch5proj10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double GRAMS_IN_KG = 1000;
const double OUNCES_IN_GRAMS = 0.0352739619;

void input(double& kg, double& g);
//prec:uses iostream
//postc: kg and g are read

double in_grams(double kg, double g);
//prec: parameters are initialized
//returns total weight in ounces

double convert(double g);
//prec: parameter is initialized
//returns total weight in grams

void output(double ounces);
//prec: parameter is initialized, uses iostream
//postc: prints weight in kg - g format

int main()
{
	double kg, g, weight_ounces, weight_grams;
	char loopcontrol = 'y';

	cout << "This program converts weight in metric units\n"
		<< "to the imperial system.\n"
		<< endl;

	do
	{
		input(kg, g);
		weight_grams = in_grams(kg, g);
		weight_ounces = convert(weight_grams);
		output(weight_ounces);

		cout << endl
			<< "Enter \'y\' to repeat the calculations,\n"
			<< "or enter something else to quit the program:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');
	return 0;
}

void input(double& kg, double& g)
{
	bool input_correct = false;

	while (!input_correct)
	{
		std::cout << "Enter the weight in kgs and grams separately,\n"
			<< "Kgs: ";
		std::cin >> kg;
		if (kg < 0)
		{
			std::cout << "Input formatting error, try again.\n";
			continue;
		}
		std::cout << "Grams: ";
		std::cin >> g;
		if (g < 0)
		{
			std::cout << "Input formatting error, try again.\n";
			continue;
		}
		input_correct = true;
	}
}


double in_grams(double kg, double g)
{
	return g + kg * GRAMS_IN_KG;
}

double convert(double weight_grams)
{
	return weight_grams * OUNCES_IN_GRAMS;
}

void output(double ounces)
{
	int pounds = (static_cast<int>(ounces) / 16);

	ounces -= 16 * pounds;

	std::cout.setf(ios::fixed);
	std::cout.setf(ios::showpoint);
	std::cout.precision(2);

	std::cout << "The weight entered in metric units is,\n"
		<< pounds << " pound";
	if (pounds != 1)
		std::cout << "s";
	std::cout << " and " << ounces << " ounce";
	if (ounces != 1)
		std::cout << "s";
	std::cout << ".\n";
}