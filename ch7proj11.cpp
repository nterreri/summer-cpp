// ch7proj11.cpp : Defines the entry point for the console application.
//	Program to display and assign plane seats

#include "stdafx.h"
#include <iostream>

const int ROWS = 7;
const int COLUMNS = 4;

void initialize_seats(char seats[][COLUMNS]);

void input(int& index, int& label);

bool check_seat_availability(const char seats[][COLUMNS], int index, int label);

void book_seat(char seats[][COLUMNS], int index, int label);

void output(const char seats[][COLUMNS]);

int main()
{
	char seats[ROWS][COLUMNS];
	char loopcontrol;
	int index, label;

	initialize_seats(seats);

	std::cout << "This program allows you to book seats on a small\n"
		<< "airplane. These are the available seats:\n";
	output(seats);

	do
	{
		input(index, label);

		bool seat_available = check_seat_availability(seats, index, label);
		if (seat_available)
			book_seat(seats, index, label);
		else
			std::cout << "Seat already booked.\n";
		
		output(seats);
		
		std::cout << "If you would like to book another seat\n"
			<< "type \'y\' then press enter. Otherwise enter \'n\'"
			<< "to quit the program:\n";
		std::cin >> loopcontrol;
	} while (loopcontrol == 'y');

	

	return 0;
}

void initialize_seats(char seats[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}
}

void input(int& index, int& label_index)
{
	using namespace std;
	char label;

	bool input_correct = false;
	while (!input_correct)
	{
		cout << "Enter the number of the row, and the name of the seat\n"
			<< "you would like to book.\n";

		cin >> index;
		if (index < 1 || index > 7)
		{
			cout << "Row number must be between 1 and " << ROWS << ".\n";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		index--;

		cin >> label;
		switch (label)
		{
		case 'A':
		case 'a':
			label_index = 0;
			break;
		case 'B':
		case 'b':
			label_index = 1;
			break;
		case 'C':
		case 'c':
			label_index = 2;
			break;
		case 'D':
		case 'd':
			label_index = 3;
			break;
		default:
			cout << "Seat label must be one of these letters:"
				<< "A B C D \n";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		input_correct = true;
	}
	
}

bool check_seat_availability(const char seats[][COLUMNS], int index, int label)
{
	if (seats[index][label] != 'X')
		return true;
	else
		return false;
}

void book_seat(char seats[][COLUMNS], int index, int label)
{
	seats[index][label] = 'X';
}

void output(const char seats[][COLUMNS])
{
	using namespace std;

	for (int i = 0; i < ROWS; i++)
	{
		cout << i + 1 << " ";
		for (int i2 = 0; i2 < COLUMNS; i2++)
		{
			cout << seats[i][i2] << " ";
		}
		cout << endl;
	}
}