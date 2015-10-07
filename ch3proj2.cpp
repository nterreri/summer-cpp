// ch3proj2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const double LOWRATE = 0.015, HIGHRATE = 0.01, INTERESTTHRESHOLD = 1000.0, MINIMUMPAYM = 10.0, MINIMUMPERCENT = 0.10;
	double balance = 0, interestlow, interesthigh, due, minimump;
	unsigned char pounds = 156;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (true)
	{
		cout << "Enter a negative value when you want to exit the program.\n";
		cout << "Type the credit account balance, then press enter:\n" << pounds;
		cin >> balance;
		
		if (balance < 0)
			break;
		
		if (balance <= INTERESTTHRESHOLD)
			due = balance * LOWRATE;
		else if (balance > INTERESTTHRESHOLD)
		{
			interestlow = INTERESTTHRESHOLD * LOWRATE;
			interesthigh = (balance - INTERESTTHRESHOLD) * HIGHRATE;
			due = interestlow + interesthigh;
		}

		if (due <= MINIMUMPAYM)
		{
			minimump = due;
			//cout << "due <= 10\n";
		}
		else
		{
			//cout << "due > 10\n";

				if ((due * MINIMUMPERCENT) > MINIMUMPAYM)
				{
					minimump = due * MINIMUMPERCENT;
					//cout << "due * 0.10 > 10\n";
				}
				else
				{
					minimump = MINIMUMPAYM;
					//cout << "due * 0.10 <= 10\n";
				}
		}
			
		

		cout << "The interest due on the balance is: " << pounds << due << endl
			<< "The minimum repayment of the amount due is: " << pounds << minimump << endl;
	}
		
	
	return 0;
}

