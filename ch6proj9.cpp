// ch6proj9.cpp : Defines the entry point for the console application.
//Program to reformat student score sheet by adding averages

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>


void add_averages(std::ifstream& is, std::ofstream& os);
//prec: is, os are accessing files, uses fstream
//posc: the file accessed by is is copied by os and averages of scores are added
//does not closes streams

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

	cout << "This program takes a file containing nothing but a list of names and\n"
		<< "scores formatted as follows: * name second name 10 integer score values *,\n"
		<< "for each line and copies the content of the list adding the average\n" 
		<< "of the scores to the end of each line to \"output.txt\"" << endl;

	add_averages(is, os);

	cout << "Done\n" << endl;

	is.close();
	os.close();
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
		os << firstn << " ";
		is >> secondn;
		os << secondn << " ";
		for (int i = 0; i < 10; i++)
		{
			is >> next;
			os << next << " ";
			sum += next;
		}

		os << static_cast<double>(sum / 10.0) << endl;
	}
}