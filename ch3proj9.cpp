// ch3proj9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	double doublemonths, loan, monthly, balance, rateint, monthint, difference, totint = 0, annint, years, intpaidpercent;
	int integermonths = 0;
	char loopcontrol;
	unsigned const char pounds = 156;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do
	{
		cout << "Enter the loaned amount:\n" << pounds;
		cin >> loan;
		cout << "Enter the interest rate for the loan:\n" << '%';
		cin >> rateint;

		monthly = loan / 20;
		cout << "Repayments are fixed as 1/20th of the loaned amount: "
			<< pounds << monthly << " each month.\n"
			<< "The difference between the monthly interest and the monthly repayment,\n"
			<< "is subtracted from the balance month per month.\n\n";

		for (balance = loan; balance > 0;)
		{
			monthint = (balance * (rateint / 100 )) / 12;
			difference = monthly - monthint;
			balance -= difference;
			totint += monthint;
			integermonths++;

			cout << "After " << integermonths << " month";
			if (integermonths != 1)
				cout << "s";
			cout << " of a monthly repayment of: "
				<< pounds << monthly << endl;
			cout << "a total of " <<  pounds << monthint << " is spent on interest.\n";
			cout << "The remaining balance amounts to " << pounds << balance << endl;
		}
		if (balance < 0)
			cout << "(With a credit of: " << pounds << balance * -1 << ")" << endl << endl;
		
		doublemonths = static_cast<double>(integermonths);

		years = doublemonths / 12;
		annint = totint / years;

		//cout << years << endl;

		cout << "The loan takes " << integermonths << " month";
		if (integermonths != 1)
			cout << "s";
		cout << " to repay.\n";
		cout << "The total interest paid amounts to: ";
		cout << pounds << totint << endl;

		cout << "The simple annualized percentage of the loan paid in interest amounts to: ";
		cout << pounds << annint << endl;

		intpaidpercent = (annint / loan) * 100;

		cout << "Which is ";
		cout << intpaidpercent << "% of the original loan.\n\n";

		cout << "If you would like to repeat the calculation enter \'y\',\n"
			<< "otherwise, enter something else:\n";
		cin >> loopcontrol;

	} while (loopcontrol == 'y');


	return 0;
}

