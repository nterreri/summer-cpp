// ch6proj1.cpp : Defines the entry point for the console application.
//Program searching a file of integers and outputting the largest and smallest to screen

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream input_stream;

	input_stream.open("c:\\Users\\salpo\\documents\\visual studio 2013\\Projects\\ch6proj1\\ch6proj1\\ch6proj1 input test file.txt");
	if (input_stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}
	
	int next, smallest, largest;

	input_stream >> next;
	if (input_stream.eof())
	{
		cout << "File is empty.\n" << endl;
		exit(0);
	}
	if (input_stream.fail())
	{
		cout << "Input file is not correctly formatted.\n" << endl;
		exit(1);
	}

	smallest = next;
	largest = next;

	while (input_stream >> next)
	{
		if (next <= smallest)
			smallest = next;
		if (next >= largest)
			largest = next;
	}
	input_stream.close();

	cout << "The smallest number in the file is: " << smallest << endl;
	cout << "The largest number in the file is: " << largest << endl;

	cout << endl;

	return 0;
}

