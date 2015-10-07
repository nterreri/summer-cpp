// ch5proj4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

void standard_deviation(double s1, double s2, double s3, double s4, double& average, double& stdeviation);
//prec: s1-4 are initialized
//post: average and stdeviation are computed
//note: calls a function using cmath

double compute_average(double s1, double s2, double s3, double s4);
//prec: s1-4 are initialized
//returns average of fours
//notes: can be called (or even left as an expression)
//to initialize "average" in the call of "standard_deviation"
//ex:
//standard_deviation(s1, s2, s3, s4, (s1+s2+s3+s4)/4, stdeviation);

double compute_deviation(double s1, double s2, double s3, double s4, double a);
//prec: s1-4 and a are initialized
//returns standard deviation
//note: uses cmath

void input(double& s1, double& s2, double& s3, double& s4);
//prec:
//postc: s1-4 are read from keyboard
//note: uses iostream

void output(double average, double stdeviation);
//prec: parameters are initialized
//postc: prints values to shell with explanation
//note: uses iostream

int main()
{
	double s1, s2, s3, s4;
	double average, stdeviation;
	char loopcontrol;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);

	cout << "This program outputs the average and the standard deviation of four\n"
		<< "scores.\n";

	cout << endl;

	do
	{
		input(s1, s2, s3, s4);
		standard_deviation(s1, s2, s3, s4, average, stdeviation);
		output(average, stdeviation);

		cout << "If you would like to repeat the calculation enter \'y\'\n"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');

	return 0;
}

void standard_deviation(double s1, double s2, double s3, double s4, double& average, double& stdeviation)
{
	average = compute_average(s1, s2, s3, s4);
	stdeviation = compute_deviation(s1, s2, s3, s4, average);
}

//stub
/*double compute_average(double s1, double s2, double s3, double s4)
{
	return 5.0;
}*/
double compute_average(double s1, double s2, double s3, double s4)
{
	return (s1 + s2 + s3 + s4)/4.0;
}


double compute_deviation(double s1, double s2, double s3, double s4, double a)
{
	return sqrt(((s1 - a) * (s1 - a) + (s2 - a) * (s2 - a) + (s3 - a) * (s3 - a) 
		+ (s4 - a) * (s4 - a)) / 4);
}

void input(double& s1, double& s2, double& s3, double& s4)
{
	std::cout << "Enter four numerical values:\n";
	std::cin >> s1 >> s2 >> s3 >> s4;
}

void output(double average, double stdeviation)
{
	std::cout << "The average is: ";
	std::cout << average;

	std::cout << endl;

	std::cout << "The standard deviation is: ";
	std::cout << stdeviation;

	std::cout << endl;
}