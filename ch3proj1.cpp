// ch3proj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



int main()
{
	char p1, p2;


	while (true)
	{
		cout << "Enter 'd' for 'done playing' at any point to quit the program.\n"
			<< "User one, enter your input (R, P, S):\n";
		cin >> p1;
		if (p1 == 'd')
			exit(0);

		cout << "User two, enter your input (R, P, S):\n";
		cin >> p2;
		if (p2 == 'd')
			exit(0);

		if (p1 == p2)
		{
			cout << "Nobody wins.\n";
			continue;
		}

		switch (p1)
		{

		case 'P':
		case 'p':
			switch (p2)
			{
			case 'R':
			case 'r':
				cout << "Paper covers rock.\n"
					<< "User one wins!\n";
				break;
			case 'S':
			case 's':
				cout << "Scissors cut paper.\n"
					<< "User two wins!\n";
				break;
			default:
				cout << "Input not valid.\n";
			}
			break; //breaks case 'P' for switch(p1)


		case 'R':
		case 'r':
			switch (p2)
			{
			case 'P':
			case 'p':
				cout << "Paper covers rock.\n"
					<< "User two wins!\n";
				break;
			case 'S':
			case 's':
				cout << "Rock breaks scissors.\n"
					<< "User one wins!\n";
				break;
			default:
				cout << "Input not valid.\n";
			}
			break; //breaks case 'R' for switch(p1)


		case 'S':
		case 's':
			switch (p2)
			{
			case 'P':
			case 'p':
				cout << "Scissors cut paper.\n"
					<< "User one wins!\n";
				break;
			case 'R':
			case 'r':
				cout << "Rock breaks scissors.\n"
					<< "User two wins!\n";
				break;
			default:
				cout << "Input not valid.\n";
			}
			break; // breaks case 'S' for switch(p1)

		default:
			cout << "Input not valid.\n";


		}
	}
	 
	
	return 0;
}

