// ch9proj3.cpp : Defines the entry point for the console application.
//	Program to display and assign plane seats, revision of ch7proj11

#include "stdafx.h"
#include <iostream>

const int COLUMNS = 4;

int read_rows_number();
//	Returns an integer read from console. Uses iostream.

char** initialize_seats(int rows);
//	Returns the address of rows place pointers to four place pointers
//	to char values; each of the latter is initialized with the values
//	'A', 'B', 'C', 'D'.

void input(int& index, int& label, int rows);
//	Reads index and label from keyboard, these values correspond to the 
//	two coordinates of one char value within char** seats (a 2-dimension
//	dynamic pointer). Rows is used to check index input for correctness.
//	Uses iostream.

bool check_seat_availability(char** seats, int index, int label);
//	Returns true if seats[index][label] is available, false otherwise.
//	Requires index and label to not exceed the space allotted to char** seats.

void book_seat(char** seats, int index, int label);
//	Writes an 'X' to seats[index][label], require these values to not exceed
//	the space allotted to the char** seats.

void output(char** seats, int rows);
//	Prints a display of the available seats on the airplane.
//	Uses iostream.

int main()
{
	char **seats;
	char loopcontrol;
	int index, label;

	std::cout << "This program allows you to book seats on a small\n"
		<< "airplane.\n" << std::endl;

	int rows = read_rows_number();
	
	seats =	initialize_seats(rows);

	std::cout << "These are the available seats :\n";
	output(seats, rows);
	
	
	do
	{
		input(index, label, rows);

		bool seat_available = check_seat_availability(seats, index, label);
		if (seat_available)
			book_seat(seats, index, label);
		else
			std::cout << "Seat already booked.\n";

		output(seats, rows);

		std::cout << "If you would like to book another seat\n"
			<< "type \'y\' then press enter. Otherwise enter \'n\'"
			<< "to quit the program:\n";
		std::cin >> loopcontrol;
	} while (loopcontrol == 'y');


	return 0;
}

int read_rows_number()
{
	using namespace std;

	int rows;
	
	bool input_correct;
	do
	{
		cout << "Enter the number of rows one the plane:\n";
		cin >> rows;

		if (cin.bad() || cin.fail())
		{
			cout << "Please enter a single number.\n";
			input_correct = false;
		}
		else
			input_correct = true;
	} while (!input_correct);

	return rows;
}

char** initialize_seats(int rows)
{
	char **seats;

	seats = new char*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		seats[i] = new char[COLUMNS];
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}

	return seats;
}

void output(char** seats, int rows)
{
	using namespace std;

	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << "\t";
		for (int i2 = 0; i2 < COLUMNS; i2++)
		{
			cout << seats[i][i2] << " ";
		}
		cout << endl;
	}
}

void input(int& index, int& label_index, int rows)
{
	using namespace std;
	
	char label;

	bool input_correct;
	do
	{
		input_correct = true;	//	Input is correct unless errors are detected.
		cout << "Enter the number of the row, and the name of the seat\n"
			<< "you would like to book.\n";

		cin >> index;
		if (index < 1 || index > rows)
		{
			cout << "Row number must be between 1 and " << rows << ".\n";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			input_correct = false;
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
			input_correct = false;
		}

	} while (!input_correct);
}

bool check_seat_availability(char** seats, int index, int label)
{
	if (seats[index][label] != 'X')
		return true;
	else
		return false;
}

void book_seat(char** seats, int index, int label)
{
	seats[index][label] = 'X';
}
