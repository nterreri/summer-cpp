// ch2proj13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double mph, mps, seconds_for_mile, minutes_to_mile_withrest, discarded_decimals, seconds_left_to_make_mile;
	int minutes_cast_to_int;
	

	cout << "Enter the speed in mph:\n";
	cin >> mph;

	//cout << mph << endl;

	mps = mph / 3600;
	//cout << mps << endl;
	seconds_for_mile = 1 / mps;
	//cout << seconds_for_mile << endl;
	minutes_to_mile_withrest = seconds_for_mile / 60;
	//cout << minutes_to_mile_withrest << endl;
	minutes_cast_to_int = static_cast<int>(minutes_to_mile_withrest);
	//cout << minutes_cast_to_int << endl;
	discarded_decimals = minutes_to_mile_withrest - minutes_cast_to_int;
	//cout << discarded_decimals << endl;
	seconds_left_to_make_mile = discarded_decimals * 60;
	//cout << seconds_left_to_make_mile << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	cout << "The pace is: " << minutes_cast_to_int << " minutes";
	cout << " and " << seconds_left_to_make_mile << " seconds";
	cout << " per mile.\n";
	
	return 0;
}

