// ch4proj16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int compute_difference(int, bool, int, int, bool, int);
int convert_to_minutes(int, bool, int);

int main()
{
	int pminutes, phours, fminutes, fhours;
	bool isAMp, isAMf;
	char loopcontrol, punctuation, pa_char, fa_char;

	cout << "This program calculates the difference between an initial and a final time\n"
		<< "taking input in the following format: hours:minutes AM/PM\n";

	cout << endl;

	do
	{
		cout << "Enter the start date: ";

		cin >> phours >> punctuation >> pminutes >> pa_char;
		cin.ignore();

		if (pminutes > 60 || pminutes < 0 || phours > 12 || phours < 0 || punctuation != ':')
		{
			cout << "Input error.\n";
			continue;
		}

		cout << endl;

		cout << "Enter the end date: ";

		cin >> fhours >> punctuation >> fminutes >> fa_char;
		cin.ignore();

		if (fminutes > 60 || fminutes < 0 || fhours > 12 || fhours < 0 || punctuation != ':')
		{
			cout << "Input error.\n";
			continue;
		}

		cout << endl;

		isAMp = (pa_char == 'a' || pa_char == 'A');
		isAMf = (fa_char == 'a' || fa_char == 'A');

		cout << "If this was a time machine you would have went "
			<< compute_difference(phours, isAMp, pminutes, fhours, isAMf, fminutes)
			<< " minutes forward in time.\n"
			<< endl;

		cout << "Enter \'y\' to input new values, or something else to quit the program:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');
	return 0;
}

int compute_difference(int phours, bool isAMp, int pminutes, int fhours, bool isAMf, int fminutes)
{
	int past_time = convert_to_minutes(phours, isAMp, pminutes);
	int future_time = convert_to_minutes(fhours, isAMf, fminutes);

	if (future_time < past_time)
		future_time += 1440;

	if (future_time == past_time)
		return 1440;

	return future_time - past_time;
}

int convert_to_minutes(int hours, bool isAM, int minutes)
{
	int time_minutes = 0;

	if (isAM)
	{
		if (hours == 12)
			time_minutes = minutes;
		else
			time_minutes = minutes + hours * 60;
	}
	else if (isAM == false)
	{
		if (hours == 12)
			time_minutes = minutes + 720; //60*12 minutes or 12 hours
		else
			time_minutes = minutes + hours * 60 + 720;
	}

	return time_minutes;
}