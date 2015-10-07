// ch6proj2.cpp : Defines the entry point for the console application.
//Program reading doubles from a file and outputting their average to screen

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input_stream;
	input_stream.open("c:\\Users\\salpo\\documents\\visual studio 2013\\Projects\\ch6proj2\\ch6proj2\\ch6proj2 test input file.txt");
	if (input_stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}

	double next, sum, average;
	input_stream >> next;
	if (input_stream.fail())
	{
		cout << "File is empty.\n" << endl;
		exit(0);
	}

	sum = next;
	
	int count = 1;
	while (input_stream >> next)
	{
		sum += next;
		count++;
	}

	input_stream.close();
	average = sum / count;

	cout << "The average of the numbers in the file is: " << average << endl;
	
	
	return 0;
}

