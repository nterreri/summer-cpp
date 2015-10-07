// ch6proj8.cpp : Defines the entry point for the console application.
//Program to read a letter and generate personalized junk mail

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void personalize_letter(ifstream& is, ofstream& os, string first_name, string family_name);
//prec: both files streams are accessing files, uses fstream
//postc: every occurrence of "#N#" in the input stream is replaced by first_name ' ' family_name
//in the output stream

int main()
{
	ifstream is;
	ofstream os;
	string first_name, family_name;

	is.open("c:\\Users\\salpo\\documents\\visual studio 2013\\Projects\\ch6proj8\\ch6proj8\\letter.txt");
	if (is.fail())
	{
		cout << "Failed to open letter file.\n" << endl;
		exit(1);
	}

	os.open("c:\\Users\\salpo\\documents\\visual studio 2013\\Projects\\ch6proj8\\ch6proj8\\personalized_letter.txt");

	cout << "Please enter the first name and surname of the addressee: \n";
	cin >> first_name;
	cin >> family_name;
	cout << "The name entered is: " << first_name << " " << family_name << endl;

	personalize_letter(is, os, first_name, family_name);
	
	cout << "The letter has been personalized.\n" << endl;

	return 0;
}

void personalize_letter(ifstream& is, ofstream& os, string first_name, string family_name)
{
	char store1 = '0', store2 = '0', store3 = '0';
	string rest_of_string;
	char next;

	while (is.get(next))
	{
		if (next == '#')
		{
			is >> rest_of_string;
			if (rest_of_string == "N#")
			{
				os << first_name << ' ' << family_name;
				is.ignore();
			}
		}
		else
			os << next;
	}
}

//earlier version
/*void personalize_letter(ifstream& is, ofstream& os, string first_name, string family_name)
{
	char store1 = '0', store2 = '0', store3 = '0';
	char next;

	while (is.get(next))
	{
		if (next == '#' && store1 != '#')
			store1 = next;

		else if (store1 == '#' && next == 'N')
			store2 = next;

		else if (store1 == '#' && store2 == 'N' && next == '#')
			cout << first_name << ' ' << family_name;

		else if (store1 == '#' && next != 'N')
		{
			store1 = '0';
			cout << '#';
		}

		else if (store1 == '#' && store2 == 'N' && next != '#')
		{
			store1 = store2 = '0';
			cout << '#';
			cout << 'N';
		}

		else
			cout << next;
	}
}*/