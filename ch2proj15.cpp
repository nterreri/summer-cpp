// ch2proj15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double velocity;
	int t1, t2, count;
	
	cout << "Enter two whole numbers representing the initial and\n"
		<< "the final temperature in Celsius:\n";
	cin >> t1 >> t2;

	if (t1 < t2)
		count = t1;
	else 
	{
		count = t2;
		t2 = t1;
	}
		

	while (count <= t2)
	{ 
		cout << "The velocity of sound in dry air at a temperature of " << count << "° Celsius is:\n"
			<< 331.3 + 0.61*count << " m/s\n";
		count++;
	}

	return 0;
}

