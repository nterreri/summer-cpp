// ch4proj8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double const TAXRATE = 0.35, LOANREPAYRATE = 0.03, LOANINTERESTRATE = 0.06;
const unsigned char pounds = 156;

double loan_calculator(double, double);
double cost_calculator(double);


int main()
{
	double yearone_cost, houseprice, downpayment, initial_loan;
	char loopcontrol;

	cout << "This program calculates the cost of a house for the first year of ownership,\n"
		<< "from the total price of the house, minus the down payment.\n\n";

	do
	{
		cout << "Enter the total cost of the house: " << pounds;
		cin >> houseprice;
		cout << "Enter the down payment: " << pounds;
		cin >> downpayment;

		initial_loan = loan_calculator(houseprice, downpayment);
		yearone_cost = cost_calculator(initial_loan);

		cout << "The cost of the house for the first year after tax saving amounts to:\n"
			<< pounds << yearone_cost << endl;
		cout << "Assuming " << TAXRATE * 100 << "% marginal tax rate, and\n"
			<< LOANREPAYRATE * 100 << "% of the initial loan as first-year\n"
			<< "repayment, and " << LOANINTERESTRATE * 100 << "% of the initial loan as\n"
			<< "interest for the first year.\n\n";

		cout << "If you would like to repeat the calculation enter \'y\',\n"
			<< "otherwise enter something else:\n";
		cin >> loopcontrol;

	}while (loopcontrol == 'y');

	return 0;
}

double loan_calculator(double houseprice, double downpayment)
{
	return houseprice - downpayment;
}

double cost_calculator(double loan)
{
	double mortgage, taxsave;
	
	mortgage = LOANREPAYRATE * loan + LOANINTERESTRATE * loan;
	taxsave = TAXRATE * LOANINTERESTRATE * loan;

	return mortgage - taxsave;
}
