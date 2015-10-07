// ch7proj3.cpp : Defines the entry point for the console application.
// Driver program for a function that deletes every repeated occurrence of
// a character in a partially filled char array

#include "stdafx.h"
#include <iostream>

const int SIZE = 10;

void input(char original[], int& size_used);
//prec: usesiostream
//postc: up to SIZE values for the array are read from keyboard

void delete_repeats(char original[], int& size_used);
//prec: array is partially filled, size represents the number of
//array positions filled
//postc: repetitions of the same char in the array are deleted,
//and values are shifted so that the unused char-size addresses all
//lie towards the end of the array. size_used is modified accordingly

void output(const char modified[], int modified_size);
//prec: uses iostream
//postc: array is printed to screen

int main()
{
	char a[SIZE];
	int size_used;

	input(a, size_used);
	delete_repeats(a, size_used);
	output(a, size_used);

	return 0;
}

void input(char original[], int& size_used)
{
	using namespace std;

	cout << "Enter up to " << SIZE << " characters:\n";
	int i = 0;
	char next;
	cin.get(next);
	while (i < SIZE && next != '\n')
	{
		original[i] = next;
		cin.get(next);
		i++;
	}

	size_used = i;
}

void delete_repeats(char original[], int& used_size)
{
	char copy[SIZE];

	for (int i1 = 0; i1 < SIZE; i1++)
		copy[i1] = original[i1];

	//Two for loops are used to skip evaluating if the value
	//at the current address is the same as the value at the
	//current address
	for (int i1 = 0; i1 < used_size; i1++)
	{
		for (int i2 = 0; i2 < used_size; i2++)
			if (i2 == i1)
				;//do nothing
			else
				if (copy[i1] == copy[i2])
				{
					copy[i2] = 0;
					/*for (int i3 = i2 + 1; i3 < used_size; i3++)
						copy[i3 - 1] = copy[i3];
					used_size--;*/
				}
				
	}

	int position1, position2;
	for (int i = 0; i < SIZE; i++)
	{
		if (copy[i + 1] == 0)
		{
			position1 = i + 1;
			int i2 = position1;
			while (copy[i2] == 0)
				i2++;
			position2 = i2;
		
			//copy a size between position1 and position2
			//from position2 onwards onto from position1 onwards:

			int i3 = position1;
			int i4 = position2;
			while (i3 < position2 && i4 < SIZE)
			{
				copy[i3] = copy[i4];
				i3++;
				i4++;
				used_size--;
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
		original[i] = copy[i];
}

void output(const char modified[], int modified_size)
{
	using namespace std;

	cout << "Modified:\n";
	for (int i = 0; i < modified_size; i++)
		cout << modified[i];
	cout << endl << "End of output.\n";
}
