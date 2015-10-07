// ch6proj10.cpp : Defines the entry point for the console application.
//Expansion of previous project:
//Program to reformat student score sheet by adding averages

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>


void add_averages(std::ifstream& is, std::ofstream& os);
//prec: is, os are accessing files, uses fstream
//posc: the file accessed by is is copied by os and averages of scores are added
//does not closes streams

void format_output(std::ofstream& os);
//prec: fstream is accessing a file, uses fstream
//postc: sets left and width flags so output is more legible,
//does not closes stream

void overwrite_inputf(std::ifstream& is, std::ofstream& os);
//prec: is, os are NOT accessing files already, uses fstream
//postc: original program input file is overwritted with the content of
//the newly created output.txt, closes streams once done

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

	cout << "This program takes a file containing nothing but a list of names and\n"
		<< "scores formatted as follows: * name second name 10 integer score values *,\n"
		<< "for each line and copies the content of the list adding the average\n"
		<< "of the scores to the end of each line to \"output.txt\";\n" 
		<< "then, it overwrites the original input file with the content\n"
		<< "of output.txt.\n" << endl;
	
	format_output(os);
	add_averages(is, os);

	is.close();
	os.close();

	overwrite_inputf(is, os);

	cout << "Done\n" << endl;

	return 0;
}

void add_averages(std::ifstream& is, std::ofstream& os)
{
	using namespace std;
	string firstn, secondn;
	while (is >> firstn)
	{
		int sum = 0;
		int next;
		char is_endline = ' ';

		os << setw(16) << firstn << " ";
		is >> secondn;
		os << setw(16) << secondn << " ";
		
		for(int i = 0; i < 10; i++)
		{
			if (is_endline == '\n')
				break;
			is >> next;
			os << setw(4) << next << " ";
			sum += next;
			is.get(is_endline);
		}

		os << setw(5) << static_cast<double>(sum / 10.0) << endl;
	}
}

void format_output(std::ofstream& os)
{
	using namespace std;
	os.setf(ios::fixed);
	os.setf(ios::showpoint);
	os.precision(1);
	os.setf(ios::left);
	os << "Format:\n"
		<< setw(16) << "First name" << setw(16) << "second name "
		<< setw(32) << "ten numbers or less, then the average\n" << endl;
}

void overwrite_inputf(std::ifstream& is, std::ofstream& os)
{
	using namespace std;
	is.open("output.txt");
	if (is.fail())
	{
		cout << "Failed to open output file.\n" << endl;
		exit(1);
	}
	os.open("input.txt");
	if (os.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}

	char next_char;
	while (is.get(next_char))
	{
		os.put(next_char);
	}
}