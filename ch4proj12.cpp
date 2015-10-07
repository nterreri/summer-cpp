// ch4proj12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double max(double, double);
double max(double, double, double);

int main()
{
	double number1, number2, number3;

	cin >> number1;
	cin >> number2;
	cin >> number3;
	
	cout << endl;

	cout << max(number1, number2) << endl;
	cout << max(number1, number2, number3) << endl;

	cout << endl;

	return 0;
}

double max(double n1, double n2)
{
	if (n1 >= n2)
		return n1;
	else
		return n2;
}

double max(double n1, double n2, double n3)
{
	double buffer = max(n1, n2);
	return max(buffer, n3);
}