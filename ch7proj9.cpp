// ch7proj9.cpp : Defines the entry point for the console application.
//Program to score a hand of poker
//Flaws: does not provide accurate scores because for the most part it
//it neglects the relevance of the value of the cards to the score,
//but this is not, by project specification, required.

#include "stdafx.h"
#include <iostream>

const int HAND = 5;

void input(int value[], char house[]);
//Prec: uses iostream, calls convert_value_input_to_data
//and convert_house_input_to_data.
//Postc: arrays are initialized in the order
//with values representing the number and house of a card

int convert_value_input_to_data(char value_input);
//prec: uses iostream, parameter is initialized.
//called by input()
//if parameter corresponds to a possible way to
//indicate a card value, returns the appropriate card value.

char convert_house_input_to_data(char house_input);
//prec: uses iostream, parameter is initialized.
//Called by input().
//If parameter corresponds to the initial
//of the name of a house, returns the appropriate house value.

int compute_score(const int value[],const char house[]);
//Prec: paramters initialized.
//Returns a number between 1 and 14 indicative of the score
//of the hand (not counting highest card value)

int count_occurrences(const int value[], int i);
//Prec: array initialized, integer i is representative of
//the index of the array value whose occurrences are to be computed.
//Returns the number of occurrences of value[i] within value[].

bool flush(const char house[]);
//Prec: parameter initialized.
//Returns true if all cards in the hand belong to the
//same house.

bool straight(const int value[]);
//Prec: parameter initialized.
//Returns true if card values in array
//are adjecent numbers in ascending order.

void output(int score, int highest_card_value);
//Prec: score is a number between 1 and 10 and
//highest_card_value is the highest number between 1 and 14
//present within value[]. Uses iostream.
//Postc: the number score is interpreted to represent
//the score of a poker hand and the result is written on screen.

int get_highest_value(const int value[]);
//Prec: array initialized.
//Returns the highest number in value[].

void output_highest(int high);
//Prec: parameter initialized.
//Postc: prints on console the card name corresponding
//to high.

int main()
{
	int value[HAND];
	char house[HAND];
	int score;
	int high;

	std::cout << "This program computes the score of a five-card\n"
			<< "poker hand.\n" << std::endl;

	input(value, house);

	score = compute_score(value, house);
	high = get_highest_value(value);

	output(score, high);
	return 0;
}

void input(int value[], char house[])
{
	using namespace std;

	cout << "You can enter the card value and house by writing it out\n"
		<< "as normal; e.g. \"Three of Spades\". Alternatively, you can\n"
		<< "type in a number followed by the house (or the first letter\n"
		<< "of the house); e.g. \"10 hearts\".\n" << endl;

	cout << "Enter the value and house of each card in that order:\n";
	
	char v;
	char h;
	char next;
	for (int i = 0; i < HAND; i++)
	{
		cin >> v;
		value[i] = convert_value_input_to_data(v);
		
		cin.get(next);
		while (next == ' ' || next == '\t' || next == '\n')
			cin.get(next);
		cin.putback(next);

		if (next == 'o' || next == 'O')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
		}

		cin >> h;
		house[i] = convert_house_input_to_data(h);
		
		if (value[i] == -1 || house[i] == -1)
		{
			cout << "Input error. Try again.\n";
			input(value, house);
		}
	}
}

int convert_value_input_to_data(char value_input)
{
	using namespace std;
	
	char next;
	switch (value_input)
	{
		//numeric/standard input:
	case '0':
		return 10;
		break;
	case'1':
	{
		cin.get(next);
		if (next == '0')
		{
			return 10;
		}
		else
		{
			cin.putback(next);
			return 14;
		}
		break;
	}
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'j':
	case 'J':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 11;
		break;
	case 'q':
	case 'Q':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 12;
		break;
	case 'k':
	case 'K':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 13;
		break;
	case 'a':
	case 'A':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 14;
		break;

		//input is alphabetic/non-standard:
	case 't':
	case 'T':
		cin.get(next);
		if (next == 'w' || next == 'W')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 2;
		}
		else if (next == 'h' || next == 'H')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 3;
		}
		else if (next == 'e' || next == 'E')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 10;
		}
		else
		{
			cout << "Value input not recognized.\n";
			return -1;
		}
		break;
	case'o':
	case 'O':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 14;
		break;
	case 'f':
	case 'F':
		cin.get(next);
		if (next == 'o' || next == 'O')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 4;
		}
		else if (next == 'i' || next == 'I')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 5;
		}
		else
		{
			cout << "Value input not recognized.\n";
			return -1;
		}
		break;
	case 's':
	case 'S':
		cin.get(next);
		if (next == 'i' || next == 'I')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 6;
		}
		else if (next == 'e' || next == 'E')
		{
			while (next != ' ' && next != '\t' && next != '\n')
				cin.get(next);
			return 7;
		}
		else
		{
			cout << "Value input not recognized.\n";
			return -1;
		}
		break;
	case 'e':
	case 'E':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 8;
		break;
	case 'n':
	case 'N':
		cin.get(next);
		while (next != ' ' && next != '\t' && next != '\n')
			cin.get(next);
		return 9;
		break;
	
	default:
		cout << "Value input not recognized.\n";
		return -1;
	}
}

char convert_house_input_to_data(char house_input)
{
	char next = '0';

	switch (house_input)
	{
	case 's':
	case 'S':
		while (next != ' ' && next != '\t' && next != '\n')
			std::cin.get(next);
		return 's';
		break;
	case 'h':
	case 'H':
		while (next != ' ' && next != '\t' && next != '\n')
			std::cin.get(next);
		return 'h';
		break;
	case 'd':
	case 'D':
		while (next != ' ' && next != '\t' && next != '\n')
			std::cin.get(next);
		return 'd';
		break;
	case 'c':
	case 'C':
		while (next != ' ' && next != '\t' && next != '\n')
			std::cin.get(next);
		return 'c';
		break;

	default:
		std::cout << "House input not recognized.\n";
		return -1;
	}
}

int compute_score(const int value[],const char house[])
{
	if (straight(value) && flush(house) && value[0] == 10)
		return 10;
	else if (straight(value) && flush(house))
		return 9;
	else if (flush(house))
		return 6;
	else if (straight(value))
		return 5;
	else
	{
		int occurrences[HAND];

		for (int i = 0; i < HAND; i++)
			occurrences[i] = count_occurrences(value, i);
		for (int i = 0; i < HAND; i++)
		{
			if (occurrences[i] == 4) // Four of a kind
				return 8;
			else if (occurrences[i] == 3)
				for (int i2 = 0; i2 < HAND; i2++)
				{
					if (i2 == i)
						;
					else
					{
						occurrences[i2] = count_occurrences(value, i2);
						if (occurrences[i2] == 2)
							return 7;	// Full house
						else
							return 4;	// Three of a kind
					}
				}
			else if (occurrences[i] == 2)
				for (int i2 = 0; i2 < HAND; i2++)
				{
					if (i == i2 || value[i2] == value[i])
						;
					else
					{
						occurrences[i2] = count_occurrences(value, i2);
						if (occurrences[i2] == 2)
							return 3;	// Two pairs
						else
							return 2;	// One pair
					}
				}
			else
				return 1; // Card high
		}
	}
}

int count_occurrences(const int value[], int i)
{
	int count = 1;

	for (int i2 = 0; i2 < HAND; i2++)
	{
		if (i2 == i)
			;
		else if (value[i] == value[i2])
			count++;
	}

	return count;
}

bool flush(const char house[])
{
	int count = 1;

	while (house[count - 1] == house[count] && count < HAND)
		count++;
	if (count == HAND)
		return true;
	else
		return false;
}

bool straight(const int value[])
{
	int i = 1;
	while (value[i - 1] + 1 == value[i] && i < HAND)
		i++;
	if (i == HAND)
		return true;
	else
		return false;
}

void output(int score, int high)
{
	using namespace std;

	cout << endl;
	cout << "The hand scores:\n";
	switch (score)
	{
	case 1:
		output_highest(high);
		cout << " High";
		break;
	case 2:
		cout << "One pair.\n";
		break;
	case 3:
		cout << "Two pairs.\n";
		break;
	case 4:
		cout << "Three of a kind.\n";
		break;
	case 5:
		cout << "Straight.\n";
		break;
	case 6:
		cout << "Flush.\n";
		break;
	case 7:
		cout << "Full House.\n";
		break;
	case 8:
		cout << "Four of a kind.\n";
		break;
	case 9:
		cout << "Straight Flush.\n";
		break;
	case 10:
		cout << "Royal Flush.\n";
		break;
	default:
		cout << "Hand score not recognized.\n";
	}
}

int get_highest_value(const int value[])
{
	int highest = value[0];
	for (int i = 1; i < HAND; i++)
	{
		if (value[i] > highest)
			highest = value[i];
	}

	return highest;
}

void output_highest(int high)
{
	using namespace std;

	switch (high)
	{
	case 2:
		cout << "Two";
		break;
	case 3:
		cout << "Three";
		break;
	case 4:
		cout << "Four";
		break;
	case 5:
		cout << "Five";
		break;
	case 6:
		cout << "Six";
		break;
	case 7:
		cout << "Seven";
		break;
	case 8:
		cout << "Eight";
		break;
	case 9:
		cout << "Nine";
		break;
	case 10:
		cout << "Ten";
		break;
	case 11:
		cout << "Jack";
		break;
	case 12:
		cout << "Queen";
		break;
	case 13:
		cout << "King";
		break;
	case 14:
		cout << "Ace";
		break;
	default:
		cout << "Card value not recognized\n.";
	}
}