// ch6proj20.cpp : Defines the entry point for the console application.
//Program to count number of words in any file in the system

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

void initialize_fstreams(std::ifstream& is, std::string full_file_path);
//prec: streams not accessing files, uses fstream and iostream and cstdlib and string
//postc: stream is accessing the file at full_file_path (if any exists), does not closes streams

int count_words(std::ifstream& is);
//prec: is is accessing a file, uses ifstream and iostream and string 
//returns number of words (strings) in file

int main()
{
	using namespace std;

	ifstream is;
	string file_path;

	cout << "Enter the full file path:\n";
	cin >> file_path;

	initialize_fstreams(is, file_path);

	int result	= count_words(is);

	cout << "The specified file contains " << result << " words.\n" << endl;

	return 0;
}

void initialize_fstreams(std::ifstream& is, std::string file_path)
{
	using namespace std;

	is.open(file_path);
	if (is.fail())
	{
		cout << "Failed to open file specified.\n" << endl;
		exit(1);
	}

	//don't forget to close them when done!
}

int count_words(std::ifstream& is)
{
	using namespace std;
	
	int result = 0;
	string next;
	while (is >> next && !is.eof())
	{
		result++;
	}

	return result;
}