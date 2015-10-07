// ch2proj2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double deadly_to_mouse, deadly_to_person, mw, pw;
	const double ONEPERTHOUSAND = 0.001;
	char loopcontrol;

	do
	{
		cout << "Enter the amount of soda deadly to a mouse (in ml):\n";
		cin >> deadly_to_mouse;
		cout << "Enter the weight of the mouse (in kg):\n";
		cin >> mw;
		cout << "Enter the target weight of the person in kg,\n"
			<< "(the weight at which the dieter will stop dieting):\n";
		cin >> pw;

		deadly_to_person = (deadly_to_mouse / mw) * pw;

		cout << "The amount of sweetener deadly to the person is:\n" << deadly_to_person << " ml\n"
			<< "( " << deadly_to_person * 1e-3 << " l )\n"
			<< "Assuming soda is 0.001% sweetener,\n"
			<< "the amount of soda deadly to the person is:\n" << deadly_to_person / ONEPERTHOUSAND << " ml\n"
			<< "( " << (deadly_to_person / ONEPERTHOUSAND) * 1e-3 << " l )\n";

		cout << "If you would like to repeat the calculation enter \'y\':\n";
		cin >> loopcontrol;
		cout << endl;
	} while (loopcontrol == 'y');

	return 0;
}

