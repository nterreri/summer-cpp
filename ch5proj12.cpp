// ch5proj12.cpp : Defines the entry point for the console application.
//Program to convert either a measure length or a measure of weight from
//the imperial system to the metric system

#include "stdafx.h"
#include <iostream>
using namespace std;

const double METERS_IN_FOOT = 0.3048;
const double METERS_IN_INCH = 0.0254;
const double INCHES_IN_METER = 39.37;

const double OUNCES_IN_POUND = 16;
const double GRAMS_IN_OUNCE = 28.3495231;
const double GRAMS_IN_KG = 1000;
const double OUNCES_IN_GRAMS = 0.0352739619;


//---------------------------------------------------------------------------
//function declarations for the length conversion portion of the program:

void length_unit_choice();
//prec: uses iostream
//postc: runs a subroutine for conversion of a measure of length from the
//imperial to the metric system, or viceversa at user's choice
//and prints the result to screen

void length_imperial_to_metric();
//prec: uses iostream
//postc: runs a subroutine for conversion a length in imperial units to metric units
//and prints the result to screen

void length_metric_to_imperial();
//prec: uses iostream
//postc: runs a subroutine for conversion a length in metric units to imperial units
//and prints the result to screen

void length_input(double& feet, double& inches);
//Prec: none
//Postc: by-reference parameters are read in feet - inch format

void length_input(double& meters);
//Prec: none
//Postc: by-reference parameter is read in meters

double length_convert(double feet, double inches);
//Prec: length in imperial system is initialized
//Returns length in metric system

double length_convert(double meters);
//Prec: length in meters is initialized
//Returns length in inches

void length_output(double length, bool flag);
//Prec: parameter is initialized, flag parameter is initialized to activate different
//sections of the function, accounting for different output formats
//Postc: parameter value is printed to console

//---------------------------------------------------------------------------
//function declarations for the weight conversion portion of the program:

void weight_unit_choice();
//prec: uses iostream
//postc: runs a subroutine for conversion of a measure of weight from
//the imperial to the metric system, or viceversa at user's choice
//and prints the result to screen

void weight_imperial_to_metric();
//prec: none
//postc: prompts user for input in imperial unit and converts
//it to metric units, then prints the result

void weight_metric_to_imperial();
//prec: none
//postc: prompts user for input in metric units,
//converts the input to imperial units,
//then prints this result

void weight_input(double& larger, double& smaller, bool metric_flag);
//prec:uses iostream, metric_flag when true activates the part of the
//function taking in metric input
//postc: larger and smaller unit measure variables are read

double weight_in_ounces(double pounds, double ounces);
//prec: parameters are initialized
//returns total weight in ounces

double weight_in_grams(double kgs, double g);
//prec: parameters are initialized
//returns total weight in smaller unit measure

double weight_convert(double grams);
//prec: parameter is initialized
//returns total weight in grams converted to ounces

double weight_convert(double ounces, bool flag);
//prec: parameter is initialized, flag is a dummy value for overloading
//the "convert()" function name
//returns total weight in ounces converted to grams

void weight_output(double smaller_converted, bool metric_flag);
//prec: parameter is initialized, uses iostream
//"metric_flag" when true activates the part of the function formatting
//metric units output
//postc: prints weight in larger - smaller format

//---------------------------------------------------------------------------
//program entry point:
int main()
{
	char choice, loopcontrol;
	
	cout << "This program converts a measure of length or weight from the\n"
		<< "imperial to the metric system or viceversa, at user's choice.\n"
		<< endl;

	do
	{
		cout << "Enter 1 to do a conversion of length, 2 for a conversion of weight:\n";
		cin >> choice;

		if (choice == '1')
			length_unit_choice();
		else if (choice == '2')
			weight_unit_choice();
		else
		{
			cout << "Input format incorrect. Please, try again.\n"
				<< endl;
			continue;
		}

		cout << "If you would like to run through the program again, enter \'y\',\n"
			<< "otherwise enter something else: ";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');

	return 0;
}

//---------------------------------------------------------------------------
//function definitions for the length conversion portion of the program:

void length_unit_choice()
{
	char choice;
	bool input_correct;
	
		do
		{
			std::cout << "Enter 1 to convert a length from imperial to metric units,\n"
				<< "or 2 to convert from metric to imperial units:\n";
			input_correct = true;

			std::cin >> choice;
			if (choice == '1')
				length_imperial_to_metric();
			else if (choice == '2')
				length_metric_to_imperial();
			else
			{
				std::cout << "Input formatting error.\n"
					<< "Please try again.\n";
				input_correct = false;
			}
		} while (!input_correct);
}

void length_imperial_to_metric()
{
	double feet, inches, metric;
	bool flag = true; //these flags activate different sections of output(double)
	//to account for the different output formats

	length_input(feet, inches);
	metric = length_convert(feet, inches);
	length_output(metric, flag);
}

void length_metric_to_imperial()
{
	double meters, inches;
	bool flag = false; //see previous comment

	length_input(meters);
	inches = length_convert(meters);
	length_output(inches, flag);
}

void length_input(double& feet, double& inches)
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

void length_input(double& meters)
{
	bool correct_input = false;

	while (!correct_input)
	{
		std::cout << "Enter the length:\n";
		std::cout << "Enter the centimeters as decimals,\n"
			<< "e.g. 1.500 meters is 1 meter, 500 centimeters.\n";
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

double length_convert(double feet, double inches)
{
	return feet * METERS_IN_FOOT + inches * METERS_IN_INCH;
}

double length_convert(double meters)
{
	return (meters * INCHES_IN_METER);
}

void length_output(double length, bool flag)
{
	if (flag)
	{
		double metric = length;
		std::cout.setf(ios::fixed);
		std::cout.setf(ios::showpoint);
		std::cout.precision(3);

		int meters_buffer = static_cast<int>(metric);
		std::cout << "The length in the metric system measures "
			<< meters_buffer << " meter";
		if (meters_buffer != 1)
			std::cout << "s,\n";
		else
			std::cout << ",\n";

		std::cout << "and " << (metric - meters_buffer) * 100 << " centimeters.\n";
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

//---------------------------------------------------------------------------
//function definitions for the weight conversion portion of the program:

void weight_unit_choice()
{
	char choice;
	bool input_correct;

	do
	{
		std::cout << "Enter 1 to convert a weight from imperial to metric units,\n"
			<< "or 2 to convert from metric to imperial units:\n";
		input_correct = true;

		std::cin >> choice;
		if (choice == '1')
			weight_imperial_to_metric();
		else if (choice == '2')
			weight_metric_to_imperial();
		else
		{
			std::cout << "Input formatting error.\n"
				<< "Please try again.\n";
			input_correct = false;
		}
	} while (!input_correct);
}

void weight_imperial_to_metric()
{
	double pounds, ounces, weight_ounces, weight_grams;
	bool metric_flag = false, imperial_to_metric_conversion = true;

	weight_input(pounds, ounces, metric_flag);
	weight_ounces = weight_in_ounces(pounds, ounces);
	weight_grams = weight_convert(weight_ounces, imperial_to_metric_conversion);
	weight_output(weight_grams, !metric_flag);
}

void weight_metric_to_imperial()
{
	double kg, g, weight_ounces, weight_grams;
	bool metric_flag = true;

	weight_input(kg, g, metric_flag);
	weight_grams = weight_in_grams(kg, g);
	weight_ounces = weight_convert(weight_grams);
	weight_output(weight_ounces, !metric_flag);
}

void weight_input(double& larger_unit, double& smaller_unit, bool metric_flag)
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

double weight_in_ounces(double pounds, double ounces)
{
	return ounces + pounds * OUNCES_IN_POUND;
}

double weight_in_grams(double kg, double g)
{
	return g + kg * GRAMS_IN_KG;
}

double weight_convert(double weight_ounces, bool flag)
{
	return weight_ounces * GRAMS_IN_OUNCE;
}

double weight_convert(double weight_grams)
{
	return weight_grams * OUNCES_IN_GRAMS;
}

void weight_output(double smaller_unit, bool metric_flag)
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