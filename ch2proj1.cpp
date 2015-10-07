// ch2proj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double packageounces;
	const double OUNCESINMT = 35273.92;
	char loopcontrol;

	do
	{

		cout << "Enter the weight of a single package of cereal in ounces:\n";

		cin >> packageounces;
		
		cout << "The weight of a package in ounces is: " << packageounces << endl
			<< "The weight of one package in metric tons is: " << packageounces / OUNCESINMT << endl
			<< "It takes " << OUNCESINMT / packageounces << " packages of cereal to make one metric ton of cereal.\n\n";

		cout << "Enter the character \'y\' (lowercase),\n"
		<< "if you would like to do the same calculations again:\n";
		cin >> loopcontrol;

	} while (loopcontrol == 'y');

	return 0;
}

