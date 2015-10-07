// ch6proj16.cpp : Defines the entry point for the console application.
//Program to output numnber of characters, non-whitespaces and letters in a file

#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

void initialize_fstreams(std::ifstream& is, std::ofstream& os);
//prec: streams not accessing files, uses fstream and iostream and cstdlib
//postc: streams are accessing files, does not closes streams

void count_symbols(std::ifstream& is, int& characters, int& nonwhitespaces, int& letters);
//prec: uses fstream
//postc: counts the symbols in the file, does not closes stream

int main()
{
	using namespace std;

	ifstream is;
	ofstream os;
	int characters = 0, nonwhitespaces = 0, letters = 0;

	cout << "This program counts the number of characters (including blank symbols)\n"
		<< "in a file, then the number of non-blank symbols, then the number of\n"
		<< "alphabetic characters, and outputs the result to both the screen and\n"
		<< "a file (\"output.txt\").\n"
		<< endl;

	initialize_fstreams(is, os);

	count_symbols(is, characters, nonwhitespaces, letters);

	cout << "Characters: " << characters << endl;
	os << "Characters: " << characters << endl;
	cout << "Non-whitespaces: " << nonwhitespaces << endl;
	os << "Non-whitespaces: " << nonwhitespaces << endl;
	cout << "Letters: " << letters << endl;
	os << "Letters: " << letters << endl;

	is.close();
	os.close();

	return 0;
}

void initialize_fstreams(std::ifstream& is, std::ofstream& os)
{
	using namespace std;

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
	}

	//don't forget to close them when done!
}

void count_symbols(std::ifstream& is, int& characters, int& nonwhitespaces, int& letters)
{
	char next;
	while (is.get(next))
	{
		characters++;

		if (next != ' ' && next != '\t' && next != '\n')
			nonwhitespaces++;

		if (isalpha(next))
			letters++;
	}
}