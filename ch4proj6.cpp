// ch4proj6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double compute_interest(double balance, double monthlyrate, int nmonths);

int main()
{
	double monthlyinterest_rate, balance, interestdue;
	int nmonths;
	const unsigned char pounds = 156;

	cout << "This program calculates the total interest on a credit (debit)\n"
		<< "card account.\n\n";

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (true)
	{
		cout << "Enter a negative number at any point to quit.\n";
		cout << "Enter the monthly interest rate (e.g. \'5\' for 5%): ";
		cin >> monthlyinterest_rate;
		if (monthlyinterest_rate < 0)
			exit(0);
		cout << "Enter the balance borrowed: " << pounds;
		cin >> balance;
		if (balance < 0)
			exit(0);
		cout << "Enter the number of months for which interest must be paid: ";
		cin >> nmonths;
		if (nmonths < 0)
			exit(0);

		monthlyinterest_rate = monthlyinterest_rate / 100; //converting from 100% to 1.0 format for calculation

		interestdue = compute_interest(balance, monthlyinterest_rate, nmonths);

		cout << "The interest due after " << nmonths << " month";
		if (nmonths != 1)
			cout << "s";
		cout << " with a borrowed balance of " << pounds << balance << " and\n"
			<< "an interest rate of " << monthlyinterest_rate * 100 << "%,\n"
			<< "amounts to: " << pounds << interestdue << endl << endl;
	}
	return 0;
}


double compute_interest(double balance, double monthlyrate_interest, int nmonths)
{
	double total_interest = 0;
	for (; nmonths > 0; nmonths--)
		total_interest += balance*monthlyrate_interest;

	return total_interest; //returns total amount due
}