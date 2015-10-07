// ch6proj15.cpp : Defines the entry point for the console application.
//Program to count the lines in a file

#include "stdafx.h"
#include <fstream>
#include <iostream>

void count_lines(std::ifstream& is, std::ofstream& os);
//prec: is, os are accessing files, uses fstreams
//postc: outputs each line in the file accessed by "is" preceded by a number
//also outputs to screen

int main()
{
	using namespace std;

	ifstream is;
	ofstream os;

	is.open("input.txt");
	if (is.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}

	os.open("output.txt");
	if (os.fail())
	{
		cout << "Failed to open output file.\n" << endl;
		exit(1);
	}

	cout << "This program counts the lines in a file, writes another file\n"
		<< "where each line of the input file is copied, preceded by its number\n"
		<< "in order.\n"
		<< endl;

	count_lines(is, os);

	cout << "Done.\n" << endl;
	return 0;
}

void count_lines(std::ifstream& is, std::ofstream& os)
{
	using namespace std;

	char next;

	for (int i = 0; !is.eof(); i++)
	{
		os.width(3);
		cout.width(3);
		os.setf(ios::right);
		cout.setf(ios::right);
		os << i;
		cout << i;
		os.setf(ios::left);
		cout.setf(ios::left);
		os.put(':');
		cout << ":   ";
		os.put(' ');
		os.put(' ');
		os.put(' ');
		is.get(next); //get the first character
		while (next == ' ' || next == '\t')//ignore initial spaces
			is.get(next);

		while (next != '\n' && !is.eof())//read and copy until the endline
		{
			os.put(next);
			cout.put(next);
			is.get(next);
		}
		os.put('\n');
		cout.put('\n');// outputs the endline
	}
}