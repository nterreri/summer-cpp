// ch2selftest2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//cout << "The answer to the question of\nLife, the Universe, and Everything is 42.\n"; //Q8
	
	//int the_number; //Q9
	//cout << "Enter an integer, then press enter:\n"; //Q9
	//cin >> the_number; //Q9

	//cout << "Hello world\n"; //Q11

	//int n1, n2; //Q12

	//cout << "Write two whole numbers\nthen press enter:\n";
	//cin >> n1 >> n2;

	//cout << "The numbers entered are: " << n1 << " and " << n2 << endl;
	//cout << "Their sum is: " << (n1 + n2) << endl; //Q12

	double one = 1.000, two = 1.414, three = 1.732, four = 2.000, five = 2.236;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	cout << "N\tSquare Root\n\n"
		<< "1\t" << one << endl << endl
		<< "2\t" << two << endl << endl
		<< "3\t" << three << endl << endl
		<< "4\t" << four << endl << endl
		<< "5\t" << five << endl;

	return 0;
}

