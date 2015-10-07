// ch7proj17.cpp : Defines the entry point for the console application.
//	Program to manipulate swim instructors hours
// Could be made more flexible by making the number of instructors variable:
// instructors schedule informations could be stored inside a three-dimensional
// array, e.g. char instructors[INSTRUCTOR_INITIAL][DAYS][HOUR_SLOTS]

#include "stdafx.h"
#include <iostream>

const int DAYS = 4;
const int HOUR_SLOTS = 4;

void initialize(char hours[][HOUR_SLOTS]);
//prec: the first set of arrays has been given a size
//postc: initializes all array values with ' '

void jeff_hours(char hours[][HOUR_SLOTS]);
void anna_hours(char hours[][HOUR_SLOTS]);
//prec: arrays are initialized with ' ' in all positions
//post: an 'X' has been placed where specified in the project description

void display(const char jeff[][HOUR_SLOTS], const char anna[][HOUR_SLOTS]);
//prec: arrays are initialized with either a ' ' or an 'X' in
//every position
//Called by main_menu().
//postc: a table is printed to screen as per project description

void display_hours(const char hours[][HOUR_SLOTS]);
//Prec: array initialized with either ' ' or 'X' in every position.
//Called by display().
//Postc: displays a table with hours and the content of the arrays.

void change_hours_menu(char jeff[][HOUR_SLOTS], char anna[][HOUR_SLOTS]);
//Prec: arrays initialized with either ' ' or 'X' in every position.
//Called by main_menu().
//Postc: Prompts the user to choose an instructor, reads input
//the calls change_hours().

void change_hours(char hours[][HOUR_SLOTS]);
//Prec: array has been selected between available instructor schedules.
//Called by change_hours_menu().
//Postc: prompts user for input and reads coordinates to be changed, then
//calls modify_hour().

void modify_hour(char hours[][HOUR_SLOTS], int day_i, int hour_i);
//Prec: parameters initialized.
//Called by change_hours().
//Postc: hours[day_i][hour_i] is modified.

void get_available(const char jeff[][HOUR_SLOTS], 
	const char anna[][HOUR_SLOTS]);
//Prec: arrays initialized with either an ' ' or an 'X'.
//Called by main_menu().
//Postc: prints to screen hour slots with ' '.

void get_both_available(const char jeff[][HOUR_SLOTS],
	const char anna[][HOUR_SLOTS]);
//Prec: arrays initialized with either an ' ' or an 'X'.
//Called by main_menu().
//Postc: prints to screen hour slots when both instructors arrays
//contain ' '.

void main_menu(char jeff[][HOUR_SLOTS], char anna[][HOUR_SLOTS]);
//Prec: arrays initialized with either ' ' or 'X' in every position
//Postc: executes user commands after presenting a menu.

int main()
{
	char jeff[DAYS][HOUR_SLOTS];
	char anna[DAYS][HOUR_SLOTS];

	initialize(jeff);
	initialize(anna);
	jeff_hours(jeff);
	anna_hours(anna);

	main_menu(jeff, anna);

	return 0;
}

void initialize(char hours[][HOUR_SLOTS])
{
	for (int i = 0; i < DAYS; i++)
	{
		for (int i2 = 0; i2 < HOUR_SLOTS; i2++)
			hours[i][i2] = ' ';
	}
}

void jeff_hours(char hours[][HOUR_SLOTS])
{
	hours[0][0] = 'X';
	hours[0][3] = 'X';
	hours[1][0] = hours[1][1] = hours[1][2] = hours[1][3] = 'X';
	hours[2][1] = hours[2][2] = hours[2][3] = 'X';
	hours[3][1] = 'X';
}

void anna_hours(char hours[][HOUR_SLOTS])
{
	hours[0][0] = hours[0][2] = hours[0][3] = 'X';
	hours[1][1] = hours[1][2] = hours[1][3] = 'X';
	hours[2][3] = 'X';
	hours[3][0] = hours[3][1] = hours[3][3] = 'X';
}

void display(const char jeff[][HOUR_SLOTS], const char anna[][HOUR_SLOTS])
{
	using namespace std;

	cout << "Jeff" << "\t"
		<< "Mon" << "\t" << "Tues" << "\t" << "Wedn" << "\t" << "Thurs" << "\t" << endl;
	
	display_hours(jeff);

	cout << "Anna" << "\t"
		<< "Mon" << "\t" << "Tues" << "\t" << "Wedn" << "\t" << "Thurs" << "\t" << endl;

	display_hours(anna);
}

void display_hours(const char hours[][HOUR_SLOTS])
{
	using namespace std;

	cout << "11-12";
	for (int i = 0; i < DAYS; i++)
		cout << "\t" << hours[i][0];
	cout << endl;

	cout << "12-1";
	for (int i = 0; i < DAYS; i++)
		cout << "\t" << hours[i][1];
	cout << endl;

	cout << "1-2";
	for (int i = 0; i < DAYS; i++)
		cout << "\t" << hours[i][2];
	cout << endl;

	cout << "2-3";
	for (int i = 0; i < DAYS; i++)
		cout << "\t" << hours[i][3];
	cout << endl;

}

void change_hours_menu(char jeff[][HOUR_SLOTS], char anna[][HOUR_SLOTS])
{
	using namespace std;
	bool input_correct = true;
	char initial;

	do
	{
		cout << "Enter the name of the instructor you would like\n"
			<< "to change the schedule of:\n";
		cin >> initial;

		if (initial == 'j' || initial == 'J')
		{
			//ignore everything until newline
			while (initial != '\n')
				cin.get(initial);

			change_hours(jeff);
			input_correct = true;
		}
		else if (initial == 'a' || initial == 'A')
		{
			//ignore everything until newline
			while (initial != '\n')
				cin.get(initial);

			change_hours(anna);
			input_correct = true;
		}
		else
		{
			//ignore everything until newline
			while (initial != '\n')
				cin.get(initial);

			cout << "Name not recognized. Try again.\n" << endl;
			input_correct = false;
		}

		
	} while (!input_correct);

}

void change_hours(char hours[][HOUR_SLOTS])
{
	using namespace std;

	char day_read;
	int hour_read;
	int day_i;
	int hour_i;

	bool input_correct;
	

	do
	{
		input_correct = true;

		cout << "Enter the day you would like to change:\n";
		cin >> day_read;

		char next;
		switch (day_read)
		{
			//simple cases
		case 'm':
		case 'M':
		case '1':
			day_i = 0;
			break;
		case '2':
			day_i = 1;
			break;
		case 'w':
		case 'W':
		case '3':
			day_i = 2;
			break;
		case '4':
			day_i = 3;
			break;
			//problematic case:
		case 't':
		case 'T':
			cin.get(next);
			if (next == 'u' || next == 'U')
				day_i = 1;
			else if (next == 'h' || next == 'h')
				day_i = 3;
			else
			{
				cout << "Day not recognized.\n";
				input_correct = false;
			}
			break;
		default:
			cout << "Day not recognized.\n";
			input_correct = false;
		}

		//ignore rest of input until newline
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		
		if (input_correct)
		{
			cout << "Enter the hour slot you would like to change:\n";
			cin >> hour_read;

			switch (hour_read)
			{
			case 11:
				hour_i = 0;
				break;
			case 12:
				hour_i = 1;
				break;
			case 1:
				hour_i = 2;
				break;
			case 2:
				hour_i = 3;
				break;
			default:
				cout << "Hour not recognized.\n";
				input_correct = false;
			}

			//ignore rest of input until newline
			cin.get(next);
			while (next != '\n')
				cin.get(next);
		}
		

	} while (!input_correct);

	modify_hour(hours, day_i, hour_i);

	cout << "The new schedule is:\n";
	
}

void modify_hour(char hours[][HOUR_SLOTS], int day_i, int hour_i)
{
	if (hours[day_i][hour_i] == 'X')
		hours[day_i][hour_i] = ' ';
	else if (hours[day_i][hour_i] == ' ')
		hours[day_i][hour_i] = 'X';
}

void get_available(const char jeff[][HOUR_SLOTS], const char anna[][HOUR_SLOTS])
{
	using namespace std;

	for (int i1 = 0; i1 < DAYS; i1++)
		for (int i2 = 0; i2 < HOUR_SLOTS; i2++)
			if (jeff[i1][i2] == ' ' || anna[i1][i2] == ' ')
			{
				switch (i1)
				{
				case 0:
					cout << "Monday";
					break;
				case 1:
					cout << "Tuesday";
					break;
				case 2:
					cout << "Wednesday";
					break;
				case 3:
					cout << "Thursday";
					break;
				}
				
				cout << ", hours ";

				switch (i2)
				{
				case 0:
					cout << "11-12";
					break;
				case 1:
					cout << "12-1";
					break;
				case 2:
					cout << "1-2";
					break;
				case 3:
					cout << "2-3";
					break;
				}
				cout << endl;

			}
	cout << endl;
}

void get_both_available(const char jeff[][HOUR_SLOTS], const char anna[][HOUR_SLOTS])
{
	using namespace std;

	for (int i1 = 0; i1 < DAYS; i1++)
		for (int i2 = 0; i2 < HOUR_SLOTS; i2++)
			if (jeff[i1][i2] == ' ' && anna[i1][i2] == ' ')
			{
				switch (i1)
				{
				case 0:
					cout << "Monday";
					break;
				case 1:
					cout << "Tuesday";
					break;
				case 2:
					cout << "Wednesday";
					break;
				case 3:
					cout << "Thursday";
					break;
				}

				cout << ", hours ";

				switch (i2)
				{
				case 0:
					cout << "11-12";
					break;
				case 1:
					cout << "12-1";
					break;
				case 2:
					cout << "1-2";
					break;
				case 3:
					cout << "2-3";
					break;
				}
				cout << endl;

			}
	cout << endl;
}

void main_menu(char jeff[][HOUR_SLOTS], char anna[][HOUR_SLOTS])
{
	char choice;
	do
	{


		std::cout << "Enter 1 to view schedule, 2 to modify the schedule,\n"
			<< "3 to get the hour slots where at least one instructor is\n"
			<< "available, 4 to get the hour slots when both instructors\n"
			<< "are available or \'q\' to quit:\n";
		std::cin >> choice;

		switch (choice)
		{
		case '1':
			display(jeff, anna);
			break;
		case '2':
			change_hours_menu(jeff, anna);
			display(jeff, anna);
			break;
		case '3':
			get_available(jeff, anna);
			break;
		case '4':
			get_both_available(jeff, anna);
			break;
		case 'q':
			break;
		default:
			std::cout << "Option not recognized, try again.\n" << std::endl;
		}

	} while (choice != 'q');
}
