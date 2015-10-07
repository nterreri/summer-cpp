// ch3proj12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n;
	double pi, iteration, store;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);
	
	cout << "This program approximates pi based on an iterating procedure.\n";

	while (true)	
	{
		
		store = 1.0;

		cout << "Enter the number of cycles for which the procedure is to be run,\n"
			<< "or enter a negative number to quit the program:\n";

		cin >> n;
		if (n < 0)
			exit(0);

		for (int i = 1; i <= n; i++)
		{
			//cout << "Cycle no: " << i << endl;
			if (i % 2 == 0)
			{
				//cout << i << " % 2 = 0\n";
				iteration = 1.0 / ((2.0 * i) + 1.0);
				//cout << 1.0 << endl;
				//cout << ((2.0 * i) + 1.0) << endl;
			}
			else if (i % 2 != 0)
			{
				//cout << i << " % 2 != 0\n";
				iteration = (-1.0) / ((2.0 * i) + 1.0);
			}
			//cout << "iteration = " << iteration << endl;

			store += iteration;
			//cout << "store = " << store << endl << "End cycle.\n\n";
		}

		cout << "For " << n << " cycle";
		if (n != 1)
			cout << "s";
		cout << " the estimated value of pi is:\n";
		pi = 4 * store;
		cout << pi << endl << endl;
	}
	

	return 0;
}

