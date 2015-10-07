// ch2selftest3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n1, n2;

	cout << "Type two integers:\n";
	cin >> n1 >> n2;

	cout << "n1 = " << n1 << endl
		<< "n2 = " << n2 << endl
		<< "n1/n2 = " << (n1 / n2) << endl
		<< "with a rest of: " << (n1%n2) << endl;

	return 0;
}

