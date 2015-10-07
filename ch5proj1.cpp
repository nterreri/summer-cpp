// ch5proj1.cpp : Defines the entry point for the console application.
//This program reads time in 24 hours format and outputs it converted to 12 hours

#include "stdafx.h"
#include <iostream>
using namespace std;

void input(int& hours, int& minutes);
//Prec: loop is iterating
//postc: 24 hours time variables are read from keyboard

void convert(int hours, int minutes, int& h12, int& m12, char& meridiem);
//prec: input was correct and successful
//postc: converted time variables are initialized correctly

void output(int hours, int minutes, char meridiem);
//prec: variables have been converted
//post: outputs time converted to 12 hours format

int main()
{
	int h24, m24, h12, m12;
	char meridiem, loopcontrol = 'y'; //pre-initialized for testing purposes

	cout << "This program reads a time in 24-hours format and outputs it converted\n"
		<< "to 12-hours format.\n";

	cout << endl;

	do
	{
		input(h24, m24);
		convert(h24, m24, h12, m12, meridiem);
		output(h12, m12, meridiem);
		//cout << h12 << " " << m12 << endl; //for testing purposes
		cout << "If you would like to repeat the calculation enter \'y\',\n"
			<< "otherwise enter something else:\n";

		cout << endl;
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');
	return 0;
}

void input(int& hours, int& minutes)
{
	char semicolon = ':';
	bool formatting_correct = false;

	while (!formatting_correct)
	{
		std::cout << "Enter the time in 24-hours format (e.g. 14:30): ";
		std::cin >> hours >> semicolon >> minutes;
		if (hours < 0 || hours > 24 || minutes < 0 || minutes > 59 || semicolon != ':')
		{
			std::cout << "Input formatting error.\n";
			continue;
		}
		else
			formatting_correct = true;
	}
}

//stub
/*void convert(int hours, int minutes, int& h12, int& m12, char& meridiem)
{
	h12 = 2;
	m12 = 5;
	meridiem = 'A';
}*/

void convert(int hours, int minutes, int& h12, int& m12, char& meridiem)
{
	if (hours < 12)
	{
		h12 = hours;
		meridiem = 'A';
	}
	else
	{
		h12 = hours - 12;
		meridiem = 'P';
	}
	m12 = minutes;
}

void output(int hours, int minutes, char meridiem)
{
	if (hours < 10)
		std::cout << 0;
	std::cout << hours << ':';
	if (minutes < 10)
		std::cout << 0;
	std::cout << minutes << ' ' << meridiem << 'M' << endl;
}