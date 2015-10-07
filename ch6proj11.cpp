// ch6proj11.cpp : Defines the entry point for the console application.
//Program to compute average length of a word in a file

#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

double average_length(std::ifstream& is);
//prec: "is" is accessing a file, uses fstream
//returns average length of words in input file

void read_from_keyboard(std::ifstream& is);
//prec: "is" is not accessing a file, uses fstream
//postc: copies one line of keyboard input into "read from keyboard.txt"
//then accesses this file via "is", does not closes "is"

int main()
{
	using namespace std;

	char ans;
	double result;
	ifstream is;

	cout << "This program computes the average length of the words\n"
		<< "in a file, or read from a single input string read from\n"
		<< "keyboard.\n" << endl;

	cout << "Would you like to enter the line via keyboard or read from the\n"
		<< "pre-specified file (\'y\'/\'n\': \'y\' to read from keyboard)?\n" << endl;
	cin >> ans;

	if (ans == 'y' || ans == 'Y')
	{
		cout << "Press \'enter\' when finished:\n";
		read_from_keyboard(is);
	}

	else
	is.open("input.txt");
	if (is.fail())
	{
		cout << "Failed to access input file.\n" << endl;
		exit(1);
	}

	result = average_length(is);

	cout << "The result is: " << result << endl;
	return 0;
}

double average_length(std::ifstream& is)
{
	using namespace std;

	char next;
	double sum = 0;
	int wordcount = 0;

	while (!is.eof())
	{
			is.get(next);
			while (next != ' ' && next != ',' && next != '.' && next != '\n')
			{
				if (is.eof())
					break;
				sum++;
				is.get(next);
				if (next == ' ' || next == ',' || next == '.' || next == '\n')
					wordcount++;
			}
	}

	return sum / static_cast<double>(wordcount);
}

//a less convoluted solution would have been to create an argument-less overload
//for "average_length" such that it only read keyboard (cin.get() etc)
void read_from_keyboard(std::ifstream& is)
{
	using namespace std;

	char next;
	ofstream os;
	os.open("read from keyboard.txt");
	if (os.fail())
	{
		cout << "Failed to open file to wrtie keyboard input to.\n" << endl;
		exit(1);
	}

	cin >> next; // to skip endlines after entering 'y' in main function
	while (next != '\n')
	{
		os.put(next);
		cin.get(next);//to get the next endline or any space or character
	}
	os.close();

	is.open("read from keyboard.txt");
	if (is.fail())
	{
		cout << "Failed to open file containing keyboard input.\n" << endl;
		exit(1);
	}
} 