// ch4proj13CORRECTED.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*void output_firstpos(int count, int buffer_secondpos);
void output_secondpos(int count);*/

string digit_to_english(int);
string ones_to_english(int, int);

int main()
{
	int count;

	while (true)
	{
		cin >> count;
		if (count < 0 || count > 99)
			continue;


		for (; count >= 0; count--)
		{
			cout << digit_to_english(count);
			cout << " bottle";
			if (count != 1)
				cout << "s";
			cout << " of beer on the wall,\n"; //first line

			if (count != 0)
			{
				cout << digit_to_english(count);
				cout << " bottle";
				if (count != 1)
					cout << "s";
				cout << " of beer,\n";
				cout << "Take one down, pass it around,\n";//second line
			}
		}
	}
	return 0;
}

/*void output_secondpos(int count)
{
	int buffer_secondpos = count / 10;
	switch (buffer_secondpos)
	{
	case 9:
		cout << "Ninety";
		output_firstpos(count, buffer_secondpos);
		break;
	case 8:
		cout << "Eighty";
		output_firstpos(count, buffer_secondpos);
		break;
	case 7:
		cout << "Seventy";
		output_firstpos(count, buffer_secondpos);
		break;
	case 6:
		cout << "Sixty";
		output_firstpos(count, buffer_secondpos);
		break;
	case 5:
		cout << "Fifty";
		output_firstpos(count, buffer_secondpos);
		break;
	case 4:
		cout << "Fourty";
		output_firstpos(count, buffer_secondpos);
		break;
	case 3:
		cout << "Thirty";
		output_firstpos(count, buffer_secondpos);
		break;
	case 2:
		cout << "Twenty";
		output_firstpos(count, buffer_secondpos);
		break;
	case 1:
		//case 1 first the "nine" etc are printed, then "teen" is appehended,
		// except in special cases (11, 12)
		if (count == 12)
			cout << "Twelve";
		else if (count == 11)
			cout << "Eleven";
		else if (count == 10)
			cout << "Ten";
		else
		{
			output_firstpos(count, buffer_secondpos);
			cout << "-Teen";
		}
		break;
	default:
		output_firstpos(count, buffer_secondpos);
		break;
	}
}


void output_firstpos(int count, int buffer_secondpos)
{
	int buffer_firstpos = count - buffer_secondpos * 10;

	if (count % 10 != 0 && count > 19)
		cout << "-";
	switch (buffer_firstpos)
	{
	case 9:
		cout << "Nine";
		break;
	case 8:
		cout << "Eight";
		break;
	case 7:
		cout << "Seven";
		break;
	case 6:
		cout << "Six";
		break;
	case 5:
		cout << "Five";
		break;
	case 4:
		cout << "Four";
		break;
	case 3:
		cout << "Three";
		break;
	case 2:
		cout << "Two";
		break;
	case 1:
		cout << "One";
		break;
	case 0:
		break;
	}

}*/

string digit_to_english(int number)
{
	int tens_buffer = number / 10;
	string result;

	switch (tens_buffer)
	{
	case 9:
		return "Ninety" + ones_to_english(number, tens_buffer);
		break;	//break clauses are redundant here because the function already
	case 8:		//returned a value
		return "Eighty" + ones_to_english(number, tens_buffer);
		break;
	case 7:
		return "Seventy" +	ones_to_english(number, tens_buffer);
		break;
	case 6:
		return "Sixty" + ones_to_english(number, tens_buffer);
		break;
	case 5:
		return "Fifty" + ones_to_english(number, tens_buffer);
		break;
	case 4:
		return "Fourty" + ones_to_english(number, tens_buffer);
		break;
	case 3:
		return "Thirty" + ones_to_english(number, tens_buffer);
		break;
	case 2:
		return "Twenty" + ones_to_english(number, tens_buffer);
		break;
	case 1:
		//case 1 first the "nine" etc are printed, then "teen" is appehended,
		// except in special cases (11, 12, 13, 15)
		if (number == 13)
			return "Thirteen";
		else if (number == 15)
			return "Fifteen";
		else if (number == 12)
			return "Twelve";
		else if (number == 11)
			return "Eleven";
		else if (number == 10)
			return "Ten";
		else
			return ones_to_english(number, tens_buffer) + "-Teen";
		break;
	default:
		return ones_to_english(number, tens_buffer);
		break;
	}
}

string ones_to_english(int number, int tens_buffer)
{
	int ones_buffer = number - tens_buffer * 10;
	string result = "";

	if (number % 10 != 0 && number > 19)
		result += "-";
	switch (ones_buffer)
	{
	case 9:
		return result += "Nine";
		break;	//break clause here not redundant
	case 8:
		return result += "Eight";
		break;
	case 7:
		return result += "Seven";
		break;
	case 6:
		return result += "Six";
		break;
	case 5:
		return result += "Five";
		break;
	case 4:
		return result += "Four";
		break;
	case 3:
		return result += "Three";
		break;
	case 2:
		return result += "Two";
		break;
	case 1:
		return result += "One";
		break;
	case 0:
		if (number == 0)
			return "Zero";
		else
			return "";
		break;
	default:
		return result; //should not happen, but avoids a warning (not all paths returning a value)
	}
}