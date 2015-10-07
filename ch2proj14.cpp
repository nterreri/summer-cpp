// ch2proj14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string instructor, name, food, number, adjective, colour, animal;
	cout << "Please enter the first or last name of your instructor:\n";
	cin >> instructor;
	cout << "Please enter your name:\n";
	cin >> name;
	cout << "Please enter the name of a food:\n";
	cin >> food;
	cout << "Please enter the name of a colour:\n";
	cin >> colour;
	cout << "Please eneter a number between 100 - 120:\n";
	cin >> number;
	cout << "Please enter an adjective:\n";
	cin >> adjective;
	cout << "Please enter the name of an animal:\n";
	cin >> animal;
	cout << endl << endl;

	cout << "Dear Instructor " << instructor << endl << endl
		<< "I am sorry that I am unable to turn in my homework at this time.\n"
		<< "First, I ate a rotten " << food << " which made me turn " << colour << " and\n"
		<< "extremely ill. I came down with a fever of " << number << ".\n"
		<< "Next, my " << adjective << " pet " << animal << " must have smelled the remains\n"
		<< "of the " << food << " on my homework, because he ate it. I am currently\n"
		<< "rewriting my homework and hope you will accept it late.\n\n"
		<< "Sincerely,\n"
		<< name << endl;

	return 0;
}

