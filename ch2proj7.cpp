// ch2proj7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const double HOURLY_RATE = 16.78, OVERTIME_RATE = 1.5, SOCIAL_SEC_RATE = 0.06, FEDERAL_TAX_RATE = 0.14, STATE_TAX_RATE = 0.05;
	const int MAX_HOURS = 40, UNION = 10, EXTRA_HEALTH = 35;
	const unsigned char pounds = 156; // £ sign to display
	double net, gross, overtime, social_sec, federal_tax, state_tax;
	int hours, dependents;
	char loopcontrol;


	do
	{
		cout << "Please enter the number of hours worked, then press enter:\n";
		cin >> hours;
		cout << "Please enter the number of dependents the worker has (if none, enter 0),\n"
			<< "then press enter:\n";
		cin >> dependents;

		if (hours <= MAX_HOURS)
			gross = HOURLY_RATE * hours;
		else
		{
			overtime = hours - MAX_HOURS;
			gross = (HOURLY_RATE * MAX_HOURS) + (overtime * (HOURLY_RATE * OVERTIME_RATE));
		}

		social_sec = gross * SOCIAL_SEC_RATE;
		federal_tax = gross * FEDERAL_TAX_RATE;
		state_tax = gross * STATE_TAX_RATE;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "The amount subtracted from the gross weekly income\n"
			<< "for the social security tax is: " << pounds << " " << social_sec << endl
			<< "The amount subtracted for the federal income tax is: " << pounds << " " << federal_tax << endl
			<< "The amount subtracted for the state income tax is: " << pounds << " " << state_tax << endl
			<< "The amount subtracted in union fees is: " << pounds << " " << UNION << endl;

		net = gross - (social_sec + federal_tax + state_tax + UNION);

		if (dependents >= 3)
		{
			net -= EXTRA_HEALTH;
			cout << "Since the employee has 3 or more dependents,\n"
				<< "there is also an extra insurance cost of " << pounds << EXTRA_HEALTH << endl;

		}
		else
		{
			cout << "Since the employee has less than 3 dependents,\n"
				<< "there is no extra health insurance cost.\n";
		}

		cout << "The gross weekly pay amounts to: " << pounds << " " << gross << endl
			<< "The net weekly pay amounts to: " << pounds << " " << net << endl;
		
		cout << "If you would like to repeat the calculations with new input,\n"
			<< "type \'y\', then press enter; otherwise, press enter:\n";
		cin >> loopcontrol;
		cout << endl;

	} while (loopcontrol == 'y');
	
	return 0;
}

