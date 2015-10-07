// ch4proj11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/*#include <cstdlib>
#include <cmath>*/
using namespace std;

float abs(float);
double abs(double);
long double abs(long double);

int abs(int);
long abs(long);
long long abs(long long);

int main()
{
	int integer = -10;
	long longinteger = -70000;
	long long longerinteger = -140000;
	float floatreal = -7.5;
	double real = -3.5;
	long double longreal = -11.5;

	/*cout << abs(integer) << endl;

	cout << labs(longinteger) << endl;

	cout << llabs(longerinteger) << endl;

	cout << fabs(real) << endl;

	cout << fabs(floatreal) << endl;*/


	cout << endl;


	cout << abs(integer) << endl;

	cout << abs(longinteger) << endl;

	cout << abs(longerinteger) << endl;

	cout << abs(floatreal) << endl;

	cout << abs(real) << endl;

	cout << abs(longreal) << endl;

	return 0;
}

float abs(float number)
{
	if (number < 0.0)
		return number * -1.0;
	else
		return number;
}
double abs(double number)
{
	if (number < 0.0)
		return number * -1.0;
	else
		return number;
}
long double abs(long double number)
{
	if (number < 0.0)
		return number * -1.0;
	else
		return number;
}

int abs(int number)
{
	if (number < 0)
		return number * -1;
	else
		return number;
}
long abs(long number)
{
	if (number < 0)
		return number * -1;
	else
		return number;
}
long long abs(long long number)
{
	if (number < 0)
		return number * -1;
	else
		return number;
}