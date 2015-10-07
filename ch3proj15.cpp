// ch3proj15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double mass, radius, weight, fb, volume;
	const double GFEET = 32.09, PI = 3.1459, Y = 62.4;
	
	cout << "This program calculates whether a sphere floats or sinks in water,\n"
		<< "where the weight and radius of the sphere are user-input.\n";

	cout << "Enter the mass of the sphere in pounds:\n";
	cin >> mass;
	cout << "Enter the radius of the sphere in feet:\n";
	cin >> radius;

	weight = mass * GFEET;
	volume = (4 / 3)*PI*radius*radius*radius;
	fb = volume * Y;

	if (fb >= weight)
		cout << "It floats!\n";
	else
		cout << "It sinks!\n";

	return 0;
}

