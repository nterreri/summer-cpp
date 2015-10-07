// ch5proj2.cpp : Defines the entry point for the console application.
//This program reads an initial time and a time interval then outputs the time after the interval from the initial time

#include "stdafx.h"
#include <iostream>
using namespace std;

void input(int& hours, int& minutes, int& nhours, int& nminutes);
//Prec: none
//postc: 24 hours initial time variables are read from keyboard
//and the number of hours and minutes to be added are read from keyboard

void time_forward(int initial_hour, int initial_minute, int nhours_forward, int nminutes_forward, int& final_hour, int& final_minute);
//Prec: initial time and time to be waited have been initialized
//postc: added nhours and nminutes to initial time to initialize final_hour and final_time

void output(int hours, int minutes);
//prec: parameters are initialized
//post: outputs time in good format



int main()
{
	int initial_hour, initial_minute, final_hour, final_minute, nhours_forward, nminutes_forward;
	char loopcontrol;
	cout << "This program reads an initial time and a time span in hours and minutes (entered separately)\n"
		<< "and outputs what the time is waiting for the time span from the initial time.\n";

	do
	{
		cout << endl;

		input(initial_hour, initial_minute, nhours_forward, nminutes_forward);
		time_forward(initial_hour, initial_minute, nhours_forward, nminutes_forward, final_hour, final_minute);
		output(final_hour, final_minute);

		cout << endl;

		cout << "Enter \'y\' to run again, or something else to quit:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');

	return 0;
}

void input(int& hours, int& minutes, int& nhours, int& nminutes)
{
	char semicolon = ':';
	bool formatting_correct = false;

	while (!formatting_correct)
	{
		std::cout << "Enter the time in 24-hours format (e.g. 14:30): ";
		std::cin >> hours >> semicolon >> minutes;
		if (hours < 0 || hours > 24 || minutes < 0 || minutes > 59 || semicolon != ':')
			std::cout << "Input formatting error.\n";
		else
			formatting_correct = true;
	}

	if (hours == 24)
		hours = 0;

	formatting_correct = false;
	while (!formatting_correct)
	{
		std::cout << "Enter the number of hours to count forward: ";
		std::cin >> nhours;
		std::cout << "Enter the number of minutes to count forward: ";
		std::cin >> nminutes;
		if (nhours < 0 || nminutes < 0)
			std::cout << "Input formatting error.\n";
		else
			formatting_correct = true;
	}

}

//stub:
/*void time_forward(int inital_hour, int initial_minute, int nhours_forward, int nminutes_forward, int& final_hour, int& final_minute)
{
	final_hour = 13;
	final_minute = 0;
}*/

void time_forward(int initial_hour, int initial_minute, int nhours_forward, int nminutes_forward, int& final_hour, int& final_minute)
{
	int buffer;

	//minutes to go forward first:
	buffer = initial_minute + nminutes_forward;
	if (buffer == 60)
	{
		nhours_forward += 1;
		final_minute = 0;
	}
	else if (buffer > 60)
	{
		int integer = buffer / 60; //number of hours to go forward in minutes, because of this final_minute has to be computed before final_hour
									//since final_hour is set to 0 if initial_hour + nhours_forward == 24
		//double decimal = buffer / 60.0 - integer;
		//final_minute = decimal * 60;
		final_minute = buffer - (60 * integer);

		nhours_forward += integer; // see previous comment
	}
	else
		final_minute = initial_minute + nminutes_forward; // == buffer


	//hours forward (accounting for hours forward in minutes previously computed):
	buffer = initial_hour + nhours_forward;

	for (int days = 0; buffer > 24; days++) //day counter unusued, but for loop reduced nhours_forward until it's less or equal to 24
	{										//so that the next else if can decide the appropriate value of final_hour
		nhours_forward -= 24;
		buffer = initial_hour + nhours_forward;
	}

	if (buffer == 24)
		final_hour = 0; //final hour is midnight
	/*else if (buffer > 24)
	{
		int integer = buffer / 24; //n of 24 hours cycles in initial_hour + nhours_forward
		 
		double decimal = buffer / 24.0 - integer; //% of 24 hours to move forward from initial hour "integer" days later
		nhours_forward = static_cast<int>(decimal * 24); //a number < 24 is cast to int to the number of hours forward from initial_hour

		final_hour = initial_hour + nhours_forward; //final hour is some hour before midnight, "integer" days after the initial day
	}*/
	else
		final_hour = initial_hour + nhours_forward; // == buffer

}



void output(int hours, int minutes)
{
	if (hours < 10)
		std::cout << 0;
	std::cout << hours << ':';
	if (minutes < 10)
		std::cout << 0;
	std::cout << minutes;
}