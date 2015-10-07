// ch3proj14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	bool flag;
//	int n;
	char quit;

	cout << "This program writes out the first 2500 prime numbers.\n";//, where n is user-input.\n";

	/*while (true)
	{
		cout << "Enter the number of prime numbers you wish to see printed,\n"
			<< "or enter a negative number to quit:\n";
		cin >> n;
		if (n < 0)
			exit(0);*/

		for (int i = 3; i <= 2500; i++)
		{
			flag = true;
			for (int divident = 2; divident < i; divident++)
			{
				if (i % divident == 0)
				{
					flag = false;
					divident = i;
				}
			}
			if (flag)
			{
				if (i < 1000)
					cout << " ";
				if (i < 100)
					cout << " ";
				if (i < 10)
					cout << " ";
				cout << i;
				if (i % 50 == 0)
					cout << endl;
				else cout << " ";
			}
			
				
		}
	//}
		cout << "\n\nEnter \"quit\" to exit the program:\n";
		cin >> quit;
	return 0;
}

