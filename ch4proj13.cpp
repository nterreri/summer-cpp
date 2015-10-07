// ch4proj13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void output_firstpos(int count, int buffer_secondpos);
void output_secondpos(int count);

int main()
{
	int count;
	
	while (true)
	{
		cin >> count;
		if (count < 0 || count > 99)
			continue;


		for (; count > 0; count--)
		{
			output_secondpos(count);
			cout << " bottle";
			if (count != 1)
				cout << "s";
			cout << " of beer on the wall,\n"; //first line

			output_secondpos(count);
			cout << " bottle";
			if (count != 1)
				cout << "s";
			cout << " of beer,\n";
			cout << "Take one down, pass it around,\n";//second line
		}

		cout << "Zero bottles of beer on the wall.\n";
	}
	return 0;
}

void output_secondpos(int count)
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

}