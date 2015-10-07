// ch3proj13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
using namespace std;



int main()
{
	int prize = 2, choice, secondchoice, reveal;
	double originalc = 1.0, changec = 1.0;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "This program displays the probabilities to win \n"
		<< "the grand prize in the following game: there are\n"
		<< "three choices, one leads to the grand prize, and\n"
		<< "the others lead to consolation prizes.\n\n"
		<< "After the player has chosen one of the three options,\n"
		<< "the position of a consolation prize in one of the\n"
		<< "two remaining options is revealed, then the player\n"
		<< "is asked whether they would like to change their\n"
		<< "choice.The program runs 10,000 simulations and\n"
		<< "accumulates statistical data to decide whether it is\n"
		<< "statistically more likely to win the grand prize\n"
		<< "if the player sticks with the original choice,\n"
		<< "or if it is more likely to win by changing their choice.\n\n";

	for (int i = 1; i <= 10000; i++)
	{
		random_device rd;
		mt19937_64 eng(rd());
		uniform_int_distribution<> distr(0, 2);
		
		choice = distr(eng);

		if (choice == prize)
		{
			uniform_int_distribution<> distr(0, 1);
			reveal = distr(eng);

			if (reveal == 0)
			{
				uniform_int_distribution<> distr(1, 2);
				secondchoice = distr(eng);
				if (secondchoice != choice)
					originalc++;
				else
					originalc++;
			}

			if (reveal == 1)
			{
				uniform_int_distribution<> distr(1, 2);
				secondchoice = distr(eng);
				if (secondchoice == 1)
				{
					secondchoice = 0;
					originalc++;
				}
				else
					originalc++;
			}

		}
		else
		{
			if (choice == 0)
			{
				reveal = 1;
				uniform_int_distribution<> distr(1, 2);
				secondchoice = distr(eng);
				if (secondchoice == 1)
					secondchoice = 0;
				if (secondchoice == 1);
				else
					changec++;
			}
			else if (choice == 1)
			{
				reveal = 0;
				uniform_int_distribution<> distr(1, 2);
				secondchoice = distr(eng);
				if (secondchoice == 2)
					changec++;
				else;
			}

		}
		
		/*if (choice == prize)
		{
			originalc++;
			//#define RAND_MAX 1;
			//reveal = rand();
		}
		else /*if (choice == 1)
			reveal = 0;
			else if (choice == 0)
			reveal = 1;
			changec++;*/
	}

	cout << "The probability to win by sticking to the original choice is:\n";
	cout << originalc / 100.0 << "%" << endl;
	cout << "The probability to win by reconsidering the choice after the reveal is:\n";
	cout << changec / 100.0 << "%" << endl;

	return 0;
}

