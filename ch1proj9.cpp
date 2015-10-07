// ch1proj9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int time, product, distance;

	cout << "Enter time-span of free fall in seconds:\n";
	cin >> time;
	
	product = 32 * time * time;
	distance = product / 2;

	cout << "The object is falling for a distance of ";
	cout << distance;
	cout << " feet.\n";

	return 0;
}

