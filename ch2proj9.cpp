// ch2proj9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const double TOTAL = 1000, MIR = 0.015, MONTHLY = 50;
	double monthly_interest, monthly_paid, left = TOTAL, total_interest = 0, credit;
	int count = 0;
	unsigned const char pounds = 156;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "To repay a loan of " << pounds << TOTAL << endl
		<< "with an interest rate of ";
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1); 
	
	cout << MIR*1e2 << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << " % and monthly payments of " << pounds << MONTHLY << endl;

	while (left > 0)
	{
		
		monthly_interest = MIR * left;
		monthly_paid = MONTHLY - monthly_interest;
		left -= monthly_paid;
		total_interest += monthly_interest;
		count++;

		if (left < 0)
		{
			credit = left * -1;
			total_interest -= credit;
			left = 0.0;
		}

		cout << "After " << count << " month";
		if (count > 1)
			cout << "s";
		cout << ",\n\n";

		cout << "The interest paid for the month amounts to: " << pounds << " " << monthly_interest << endl
			<< "An amount of: " << pounds << " " << monthly_paid << " has been repaid off the loaned amount.\n"
			<< "The total interest paid so far amounts to: " << pounds << " " << total_interest << endl
			<< "The total loaned amount remaining to be paid is: " << pounds << " " << left << endl << endl;

	}

	cout << endl;

	cout << "The total interest to be repaid is: " << pounds << " " << total_interest << endl
		<< "It will take " << count << " months to repay the loan and interest.\n";

	return 0;
}

