// ch5proj13.cpp : Defines the entry point for the console application.
//Driver program testing a function calculating perimeter and area of a triangle

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

void triangle_area_perimeter(double a, double b, double c, double& p, double& area);
//prec: value parameters are initialized, uses iostream
//postc: reference parameters are initialized

bool is_triangle(double a, double b, double c);
//prec: value parameters are initialized
//returns true if the three sides can make a triangle, false otherwise

void triangle_area_perimeter(double a, double b, double c, double& perimeter, double& area)
{
	if (is_triangle(a, b, c))
	{
		double s = (a + b + c) / 2;
		perimeter = 2 * s;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
	}
	else
		perimeter = (a + b + c); //since the 3 sides cannot make a triangle, there is
	//no area they delimit, but there is a total sum of their length.
}

bool is_triangle(double a, double b, double c)
{
	if (a + b < c || a + c < b || b + c < a)
		return false;
	else
		return true;
}