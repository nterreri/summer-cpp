// ch3proj10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	int sample, piteration, ppiteration, initial, dinput;
	char loopcontrol;

	do
	{
	cout << "The grow rate of green crud population is a Fibonacci sequence,\n"
		<< "when a population has no deaths.\n";

	cout << "Enter the initial sample of green crud in pounds:\n";
	cin >> initial;
	cout << "Enter the number of days to be waited:\n";
	cin >> dinput;

	piteration = ppiteration = initial;
	for (int day = 0; day <= dinput; day += 5)
	{
		if (day < 10)
		{
			cout << "After " << day << " days, the sample still weights ";
			cout << initial << " pounds.\n";
		}
		else if (day >= 10)
		{
			sample = ppiteration + piteration;
			cout << "After " << day << " days, the sample weights ";
			cout << sample << " pounds.\n";
			ppiteration = piteration;
			piteration = sample;
		}
	}

	cout << "Enter \'y\' to repeat the calculation,\n"
		<< "otherwise enter something else:\n";
	cin >> loopcontrol;

	} while (loopcontrol == 'y');

	return 0;
}

