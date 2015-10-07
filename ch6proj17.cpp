// ch6proj17.cpp : Defines the entry point for the console application.
//Program to read a baby name from keyboard and output its popularity rank

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

void initialize_fstreams(std::ifstream& is);
//prec: streams not accessing files, uses fstream and iostream and cstdlib
//postc: streams are accessing files, does not closes streams

void search_name(std::string name_to_search_for, std::ifstream& is, bool& name_is_in_list, bool& isboy, int& rank);
//prec: uses ifstream and string
//postc: searches for name_to_search_for inside the file opened by is,
//looks for a rank number first, then compares the name to the ones occurring in each rank
//the first name occurring is male, the second female at that rank
//initializes bool flags for output appropriately

void output(std::string name_typed, bool name_in_list, bool isboy, int rank);
//prec: parameters initialized, uses iostream
//postc: outputs search result in good format

int main()
{
	using namespace std;

	string name_typed;
	ifstream is;
	bool name_in_list;
	bool isboy;
	int rank;

	cout << "This program reads a baby name from the keyboard and\n"
		<< "ouputs its rank within a top 50 popularity ranking.\n" << endl;

	while (name_typed != "quit" && name_typed != "Quit") //main loop
	{

		initialize_fstreams(is);

		cout << "Enter the name to search for, or type \"quit\" to exit:\n";
		cin >> name_typed;

		search_name(name_typed, is, name_in_list, isboy, rank);

		output(name_typed, name_in_list, isboy, rank);

		is.close();
	}
	
	return 0;
}

void initialize_fstreams(std::ifstream& is)
{
	using namespace std;

	is.open("list.txt");
	if (is.fail())
	{
		cout << "Failed to open list file.\n" << endl;
		exit(1);
	}
	
	//don't forget to close it when done!
}

void search_name(std::string name_to_search_for, std::ifstream& is, bool& name_is_in_list, bool& isboy, int& rank)
{
	using namespace std;

	char next = 'a';
	string name_at_rank;
	name_is_in_list = false;
	while (!is.eof())
	{
		while (!isdigit(next))
			is.get(next);
		is.putback(next);
		is >> rank;
		is >> name_at_rank;
		if (name_at_rank == name_to_search_for)
		{
			isboy = true;
			name_is_in_list = true;
			break;
		}
		is >> name_at_rank;
		if (name_at_rank == name_to_search_for)
		{
			isboy = false;
			name_is_in_list = true;
			break;
		}
		
		while (next != '\n' && !is.eof())
			is.get(next);
	}
}

void output(std::string name_typed, bool name_in_list, bool isboy, int rank)
{
	using namespace std;

	if (!name_in_list)
	{
		cout << name_typed << " is not ranked among the top 50.\n" << endl;
	}
	else
	{
		cout << name_typed << " is ranked " << rank << " in popularity among";
		if (isboy)
			cout << " boys.\n" << endl;
		else if (!isboy)
			cout << " girls.\n" << endl;
	}
}