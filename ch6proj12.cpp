// ch6proj12.cpp : Defines the entry point for the console application.
//Program to read a c++ source file and replace the wrong occurrences of 
//the insertion and extractor operators following either a cin or a cout

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

void correct_cin_cout(std::ifstream& is, std::ofstream& os);
//prec: is, os already accessing files, uses fstream
//postc: replaces occurrences of the wrong operator with the correct operator
//in the output file

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
	os.open("output.cpp");
	if (os.fail())
	{
		cout << "Failed to open output file.\n" << endl;
		exit(1);
	}

	cout << "This program corrects a c++ source file where some\n"
		<< "occurrences of the >> operator have been substituted\n"
		<< "by the << operator after either a cin or a cout, and\n"
		<< "viceversa.\n" << endl;

	correct_cin_cout(is, os);

	is.close();
	os.close();
	cout << "Done\n" << endl;
	return 0;
}

//would be easier to read if sub if-else clauses were
//sub routines of "correct_cin_cout"
void correct_cin_cout(std::ifstream& is, std::ofstream& os)
{
	using namespace std;

	char next;
	string rest_of_string_beggining_with_c;

	is.get(next);
	while (!is.eof())
	{
		if (next == 'c')
		{
			is >> rest_of_string_beggining_with_c;
			if (rest_of_string_beggining_with_c == "in")
			{
				os << "cin";
				is.get(next);
				while (next == ' ')
				{
					os.put(next);
					is.get(next);
				}

				if (next == '<')
				{
					is.get(next);
					if (next == '<')
						os << ">>";
					else
						os << "<" << next;
				}
				else
					os << next;
			}
			else if (rest_of_string_beggining_with_c == "in>>" ||
				rest_of_string_beggining_with_c == "in<<")
			{
				os << "cin >>";
			}
		
			else if (rest_of_string_beggining_with_c == "out")
			{
				os << "cout";
				is.get(next);
				while (next == ' ')
				{
					os.put(next);
					is.get(next);
				}

				if (next == '>')
				{
					is.get(next);
					if (next == '>')
						os << "<<";
					else
						os << ">" << next;
				}
				else
					os << next;
			}
			else if (rest_of_string_beggining_with_c == "out>>" ||
				rest_of_string_beggining_with_c == "out<<")
			{
				os << "cout <<";
			}
			else
				os << next << rest_of_string_beggining_with_c;
		}
		else
			os.put(next);

		is.get(next);
	}
}