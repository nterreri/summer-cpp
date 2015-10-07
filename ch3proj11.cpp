// ch3proj11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double approx = 0.0, bang, exponent, exponentitimes = 1.0, approxbuiltin;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);
	
	cout << "This program calculates e^x (where x is user-input) in two different ways.\n"
		<< "One is through an iterative approximation, the other through a prebuilt\n"
		<< "function.\n\n";
	while (true)
	{
		
		

		cout << "Enter the exponent:\n"
			<< "(Enter \'0\' to quit the program,\n"
			<< "obviously, e^0 is uninteresting)\n";
		cin >> exponent;

		if (exponent == 0)
			exit(0);


		cout << "This is the result of the iterative procedure repeated 100 times,\n"
			<< "iteration by iteration:\n";
		for (int i = 0; i <= 100; i++)
		{
			//cout << "Main loop, cycle: " << i << endl;
			exponentitimes = 1.0;
			for (int count = 1; count <= i; count++)
			{
				//cout << "Exponent times, cycle: " << count << endl;
				exponentitimes *= exponent;
				//cout << exponentitimes << endl;
			}

			bang = 1.0;
			for (int count = 2; count < (i + 1); count++)
			{
				//cout << "Bang value, cycle " << count - 1 << endl;
				bang *= count;
				//cout << bang << endl;
			}

			
			//cout << "Approx value, cycle " << i << endl;
			approx += exponentitimes / bang;
			
			if (i <= 7)
				cout << " ";
			if (i > 0)
			cout << approx;
			if (i % 7 == 0)
				cout << endl;
			else cout << " ";
			
			
		}

		cout << "\nThis is the output of the built-in function:\n";

		approxbuiltin = exp(exponent);
		cout << endl << approxbuiltin << endl << endl;
		approx = 0.0;
	}
	

	return 0;
}

