// ch2proj6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int maxc, people;
	do
	{
		cin >> maxc;
		cin >> people;
		
		if (maxc <= people)
		{
			cout << "The meeting is in agreement with fire regulations.\n"
				<< maxc - people << "more people can attend the meeting,\n"
				<< "before the number of people attending exceeds"
		}
	} while ()
	
	return 0;
}

