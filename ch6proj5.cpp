// ch6proj5.cpp : Defines the entry point for the console application.
//Program giving advice from a file, then reading and printing another piece of advice to the same file.

#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

const char DATAFILE[14] = "InOutfile.txt";


int main()
{
	ifstream isadvice;
	ofstream osadvice;
	char next;

	cout << "This program gives the user some advice, then prompts the user to write some other advice.\n"
		<< "The next person to use the program will read the previous user's advice.\n"
		<< endl;

	isadvice.open(DATAFILE);
	if (isadvice.fail())
	{
		cout << "Failed to access file.\n" << endl;
		exit(1);
	}
	
	cout << "Here is the adivce to you:\n";
	while (isadvice.get(next))//write to screen
		cout.put(next);
	isadvice.close();


	cout << endl;


	osadvice.open(DATAFILE);
	if (osadvice.fail())
	{
		cout << "Failed to access file.\n" << endl;
		exit(1);
	}
	cout << "Enter your advice, press enter twice when you are finished:\n";

	while (true)//read from screen, quits on user input
	{
		cin.get(next);
		osadvice.put(next);
		if (next == '\n')
		{
			cin.get(next);
			if (next == '\n')
			{
				cout << "Your advice has been writted down for the next user.\n" << endl;
				break;
			}
		}
	}
	return 0;
}

