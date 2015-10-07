// ch6proj18.cpp : Defines the entry point for the console application.
//Program to write a svg file displaying columns on the basis of user inpu

#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

int get_highest(int keyboard_input[]);
//prec: parameter initialized
//returns highest value in array

void initialize_fstreams(std::ifstream& is, std::ofstream& os);
//prec: streams not accessing files, uses fstream and iostream and cstdlib
//postc: streams are accessing files, does not closes streams

void write_from_template(std::ifstream& is, std::ofstream& os, int maxvalue, int kinput[]);
//prec: is, os are accessing files, other parameters are initialized
//postc: directs the input stream through the template file and copies it
//fills in the blanks with previous user input in the output file (flagged by '#' and '$')
//does not closes streams

int main()
{
	using namespace std;

	cout << "This program writes a .svg file (which you should be able to open via your\n"
		<< "browser) and draws a bar chart based on user-input.\n"
		<< endl;
	
	//get input (should have been a subroutine, but arrays cannot be passed by-reference)
	int kinput[5];
	bool input_incorrect = false;//assume input is correct

	do
	{
		if (input_incorrect)//output complaint if input was incorrect at the last iteration
			cout << "Input incorrect.\n" << endl;

		input_incorrect = false;//assume input will be correct (this time)
		cout << "Enter " << 5 << " non-negative whole numbers:\n";
		for (int i = 0; i < 5; i++)
		{
			cin >> kinput[i];
			if (kinput[i] < 0)
				input_incorrect = true; //flag input for incorrectness if negative input detected
		}

	} while (input_incorrect);	//loop only if flagged for incorrectness

	

	//calculate greatest value in array (to set it at 400 pixels scale all values to it):
	int max = get_highest(kinput);

	ifstream is;
	ofstream os;

	initialize_fstreams(is, os);

	write_from_template(is, os, max, kinput);

	return 0;
}

int get_highest(int kinput[])
{
	int highest;
	highest = kinput[0];
	for (int i = 1; i <= 4; i++)
	{
		if (kinput[i] > highest)
			highest = kinput[i];
	}

	return highest;
}

void initialize_fstreams(std::ifstream& is, std::ofstream& os)
{
	using namespace std;

	is.open("basic.svg");
	if (is.fail())
	{
		cout << "Failed to open \"basic.svg\".\n" << endl;
		exit(1);
	}

	os.open("output.svg");
	if (os.fail())
	{
		cout << "Failed to open output file.\n" << endl;
	}

	//don't forget to close them when done!
}

void write_from_template(std::ifstream& is, std::ofstream& os, int maxvalue, int kinput[])
{
	using namespace std;

	//values to be read from template:
	char next;
	int digit;

	//values to be written to output file:
	int height;
	int drawpoint;
	while (is.get(next) && !is.eof())
	{
		if (next == '#')
		{
				is >> digit;
				height = static_cast<int>((static_cast<double>(kinput[digit]) / static_cast<double>(maxvalue)) * 400);
				drawpoint = 550 - height;
				
				os << drawpoint;
		}

		else if (next == '$')
		{
			os << height;
			is.get(next); //ignores the digit in the stream
		}

		else
			os.put(next);
	}
}