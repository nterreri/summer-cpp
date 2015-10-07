// ch4selftest4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
						# include <iostream>
#define _USE_MATH_DEFINES//to use a predefined PI constant, it is necessary to include this definition
#include <math.h>//and this file (not cmath)
using namespace std;


int main()
{
	cout << sqrt(M_PI) << endl; //the name of the constant is not PI but M_PI
	return 0;
}

