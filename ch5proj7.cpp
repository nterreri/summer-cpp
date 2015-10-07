// ch5proj7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const double INCHES_IN_METER = 39.3700;
//const double INCHES_IN_CM = 2.54;

void input(double& meters);
//Prec: none
//Postc: by-reference parameter is read

void output(double inches);
//Prec: parameter is initialized
//Postc: parameter is printed in feet - inches format

double convert(double meters);
//Prec: parameter is initialized
//Returns length in inches

int main()
{
	double meters, inches;
	char loopcontrol;

	cout << "This program converts a lenght given in the metric system\n"
		<< "to the imperial system.\n"
		<< endl;

	do
	{
		input(meters);
		inches = convert(meters);
		output(inches);

		cout << "If you would like to repeat the calculation enter \'y\'\n"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');

	return 0;
}

void input (double& meters) //void input(double& cms)
{
	//double meters_input_buffer/*, cms_input_buffer*/;
	bool correct_input = false;

	while (!correct_input)
	{
		std::cout << "Enter the length:\n";
				//<<"entering one integer for the\n"
				//<< "meters, and another for the centimeters;\n";
		std::cout << "Meters: ";
		std::cin >> meters;// ::cin >> meters_input_buffer;
		if (meters < 0)
		{
			std::cout << "Input formatting error.\n";
			continue;
		}

		/*std::cout << "Centimeters: ";
		std::cin >> cms_input_buffer;
		if (cms_input_buffer < 0)
		{
			std::cout << "Input formatting error.\n";
			continue;
		}*/
		correct_input = true;
	}
	
	//cms = (/*cms_input_buffer+*/ meters_input_buffer * 100.0);
}

void output(double inches)
{
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

double convert(double meters)
{
	return (meters * INCHES_IN_METER);
}