// ch4proj9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double hat(double weight, double height);
double chest(double height, double weight, int age);
double waist(double weight, int age);


int main()
{
	double h, w; //height, weight
	int a;//age
	char loopcontrol;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "This program calculates clothing size based on height, weight and age.\n\n";

	do
	{
		cout << "Enter the subject's height (in inches): ";
		cin >> h;
		cout << "Enter the subject's weight (in pounds): ";
		cin >> w;
		cout << "Enter the subject's age (whole years only): ";
		cin >> a;

		cout << "The size of the hat should be: ";
		cout << hat(w, h) << " inches" << endl;
		cout << "The size of the jacket (chest size) is: ";
		cout << chest(h, w, a) << " inches" << endl;
		cout << "The waist size is: ";
		cout << waist(w, a) << " inches" << endl << endl;

		cout << "If you would like to repeat the calculation enter \'y\',\n"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');

	return 0;
}

double hat(double w, double h)
{
	return (w / h) * 2.9;
}

double chest(double h, double w, int a)
{
	double result = (h*w) / 288.0;

	for (; a > 39; a -= 10)
		result += (1.0 / 8.0);

	return result;
}

double waist(double w, int a)
{
	double result = (w / 5.7);

	for (; a > 29; a -= 2)
		result += (1.0 / 10.0);

	return result;
}