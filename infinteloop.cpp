// infinteloop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int x = 1;

	while (x != 12)
	{
		cout << x << endl;
		x = x + 2;
	}

	return 0;
}

