// ch3proj8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char v1, v2, v3, v4, v5;
	int handsize,  score, acecounter;
	
	//int cyclecounter = 0;

	while (true)
	{
		score =  acecounter = 0;
		v1 = v2 = v3 = v4 = v5 = '0';

		//cout << "Cycle: " << ++cyclecounter << endl;

		cout << "This program calculates the score of a blackjack hand.\n"
			<< "Enter the number of cards in the hand,\n"
			<< "Or enter 0 to quit:\n";

		cin >> handsize;

		if (handsize <= 0)
			exit(0);

		if (handsize > 5)
		{
			cout << "Input invalid: A blackjack hand is between 1 to 5 cards.\n"
				<< "Try again.\n";
			continue;
		}

		cout << "Now, enter the values of the " << handsize << " cards,\n"
			<< "or type \'e\' to exit the program.\n"
			<< "Enter a number the cards 2 to 9, \'t\' for 10,\n"
			<< "and either \'k\', \'q\' or \'j\' for the face cards\n"
			<< "(the King, Queen and Jack), enter \'a\' for aces:\n";

		for (int i = 0; i < handsize; i++)
		{
			if (i == 0)
			{
				cin >> v1;
				if (v1 == 'e')
					exit(0);
			}
			else if (i == 1)
			{
				cin >> v2;
				if (v2 == 'e')
					exit(0);
			}
			else if (i == 2)
			{
				cin >> v3;
				if (v3 == 'e')
					exit(0);
			}
			else if (i == 3)
			{
				cin >> v4;
				if (v4 == 'e')
					exit(0);
			}
			else if (i == 4)
			{
				cin >> v5;
				if (v5 == 'e')
					exit(0);
			}
		}

		switch (v1)
		{
		case '0':
			score += 0;
			break;
		case '1':
			cout << "Input invalid.\n"
				<< "Enter \'t\' for a card of value 10.\n";
			cin.ignore();
			continue;
		case '2':
			//cout << "Entering first switch.\n";
			score += 2;
			break;
		case '3':
			score += 3;
			break;
		case '4':
			score += 4;
			break;
		case '5':
			score += 5;
			break;
		case '6':
			score += 6;
			break;
		case '7':
			score += 7;
			break;
		case '8':
			score += 8;
			break;
		case '9':
			score += 9;
			break;
		case 'K':
		case 'k':
		case 'Q':
		case 'q':
		case 'J':
		case 'j':
		case 'T':
		case 't':
			score += 10;
			break;
		case 'a':
			acecounter++;
			break;
		default:
			cout << "Input invalid: not a possible card value.\n";
			continue;
		}

		switch (v2)
		{
		case '0':
			score += 0;
			break;
		case '1':
			cout << "Input invalid.\n"
				<< "Enter \'t\' for a card of value 10.\n";
			//for (int i = 0; i < 8; i++)
			cin.ignore();
			continue;
		case '2':
			//cout << "Entering second switch.\n";
			score += 2;
			break;
		case '3':
			score += 3;
			break;
		case '4':
			score += 4;
			break;
		case '5':
			score += 5;
			break;
		case '6':
			score += 6;
			break;
		case '7':
			score += 7;
			break;
		case '8':
			score += 8;
			break;
		case '9':
			score += 9;
			break;
		case 'K':
		case 'k':
		case 'Q':
		case 'q':
		case 'J':
		case 'j':
		case 'T':
		case 't':
			score += 10;
			break;
		case 'a':
			acecounter++;
			break;
		default:
			cout << "Input invalid: not a possible card value.\n";
			continue;
		}

		switch (v3)
		{
		case '0':
			score += 0;
			break;
		case '1':
			cout << "Input invalid.\n"
				<< "Enter \'t\' for a card of value 10.\n";
			cin.ignore();
			continue;
		case '2':
			//cout << "Entering third switch.\n";
			score += 2;
			break;
		case '3':
			score += 3;
			break;
		case '4':
			score += 4;
			break;
		case '5':
			score += 5;
			break;
		case '6':
			score += 6;
			break;
		case '7':
			score += 7;
			break;
		case '8':
			score += 8;
			break;
		case '9':
			score += 9;
			break;
		case 'K':
		case 'k':
		case 'Q':
		case 'q':
		case 'J':
		case 'j':
		case 'T':
		case 't':
			score += 10;
			break;
		case 'a':
			acecounter++;
			break;
		default:
			cout << "Input invalid: not a possible card value.\n";
			continue;
		}

		switch (v4)
		{
		case '0':
			score += 0;
			break;
		case '1':
			cout << "Input invalid.\n"
				<< "Enter \'t\' for a card of value 10.\n";
			cin.ignore();
			continue;
		case '2':
			//cout << "Entering fourth switch.\n";
			score += 2;
			break;
		case '3':
			score += 3;
			break;
		case '4':
			score += 4;
			break;
		case '5':
			score += 5;
			break;
		case '6':
			score += 6;
			break;
		case '7':
			score += 7;
			break;
		case '8':
			score += 8;
			break;
		case '9':
			score += 9;
			break;
		case 'K':
		case 'k':
		case 'Q':
		case 'q':
		case 'J':
		case 'j':
		case 'T':
		case 't':
			score += 10;
			break;
		case 'a':
			acecounter++;
			break;
		default:
			cout << "Input invalid: not a possible card value.\n";
			continue;
		}
			
		switch (v5)
		{
		case '0':
			score += 0;
			break;
		case '1':
			cout << "Input invalid.\n"
				<< "Enter \'t\' for a card of value 10.\n";
			cin.ignore();
			continue;
		case '2':
			//cout << "Entering fifth switch.\n";
			score += 2;
			break;
		case '3':
			score += 3;
			break;
		case '4':
			score += 4;
			break;
		case '5':
			score += 5;
			break;
		case '6':
			score += 6;
			break;
		case '7':
			score += 7;
			break;
		case '8':
			score += 8;
			break;
		case '9':
			score += 9;
			break;
		case 'K':
		case 'k':
		case 'Q':
		case 'q':
		case 'J':
		case 'j':
		case 'T':
		case 't':
			score += 10;
			break;
		case 'a':
			acecounter++;
			break;
		default:
			cout << "Input invalid: not a possible card value.\n";
			continue;
		}

		for (; acecounter > 0; acecounter--)
		{
			if (score + 10 > 21)
				score += 1;
			else (score += 10);
		}

		cout << "The score is: ";
		if (score <= 21)
			cout << score << endl;
		else cout << score << " busted! (over 21 points)\n";

		



		
	}
	return 0;
}

