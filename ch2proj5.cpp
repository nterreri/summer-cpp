// ch2proj5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double gross_value, desired_value, interestrate, absolute_interest,/* actual_interest,*/ durationys;
	int durationms;
	const unsigned char pounds = 156; // £ sign to display
	char loopcontrol;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);	// output precision is put here outside of the body of the "do"
						// because it is specified at the end of the body as well

	do
	{
		cout << "Please type the the required amount for the loan:\n"
			<< pounds << ' '; // prompt: "£ _"
		cin >> desired_value;
		cout << "Please enter the interest rate (where 1.0 stands for 100% -"
			<< " for example 0.15 for 15%):\n";
		cin >> interestrate;
		cout << "Please enter the duration of the loan in months:\n";
		cin >> durationms;

		durationys = (durationms / 12.0);	// duration in years is type double
											// in months type int
		
		gross_value = desired_value / (1 - interestrate * durationys);	// gross (or face) value is here
		absolute_interest = gross_value * interestrate;					// calculated as a function on 
		//actual_interest = absolute_interest * durationys;				// interest rate and duration
																		// of loan in years

		cout << "The gross (or face) value of a desired-value loan of:\n"
			<< pounds << ' ' << desired_value << endl
			<< "with an interest rate of:\n"
			<< interestrate << endl
			<< "throughout a period of:\n"
			<< durationms << " months, or ";

		cout.setf(ios::fixed);	// precision is here set to 1 so that the amount of years is not
		cout.setf(ios::showpoint);// displayed as, say, "1.50 years"
		cout.precision(1);

		cout << durationys << " years,\n"
			<< "is:\n";

		cout.setf(ios::fixed); // precision is then reset to 2
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << pounds << ' ' << gross_value << endl
			<< "The monthly repayment, spread across "
			<< durationms << " months,\n"
			<< "amounts to:\n"
			<< pounds << ' ' << gross_value / durationms << endl
			<< "(For the whole loan including interest)\n";

		cout << "If you would like to calculate the face value and monthly payment\n"
			<< "for another loan type 'y' (lowercase), otherwise type anything else:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');
	return 0;
}

