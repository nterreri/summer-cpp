// ch8proj13.cpp : Defines the entry point for the console application.
//	Program to conver time to military time.

#include "stdafx.h"
#include <iostream>
#include <string>

const int DIGIT_ARRAY_LIMIT = 2;

void input(std::string& time);
//	Uses iostream and string.
//	Reads a 12h time from keyboard, iterates until input has been correctly
//	formatted.

void check_input_for_errors(std::string input, bool& input_correct);
//	Called by input(), uses iostream and string.
//	Checks for formatting errors in input and modifies input_incorrect
//	accordingly.

void read_numbers(std::string time, int& hour, int& minute);
//	Uses string and iostream. Called by convert_to_military_format()
//	Extracts integers from the string inputted.

bool is_am(std::string time);
//	Uses iostream and string.
//	Returns true if there is a "AM" substring in time, returns false if there
//	is a "PM" substring in time. Exits the program if neither is present.

std::string convert_time_to_24h(int& hour, int& minute, bool isam);
//	Uses string and iostream. Called by conver_to_miliary_format().
//	Returns a concatenation of the values in hour and minute, properly formatted.
//	The boolean value is used to decide whether to add 12 to hours.

void output(std::string result);
//	Uses string and iostream.
//	Prints result to console.

void general_format_check(std::string input, bool& input_correct);
//	Uses string and iostream. Called by input.
//	Modifies input_correct accordingly.

void check_integrity_of_numerical_input(std::string input, bool& input_correct);
//	Uses string and iostream. Called by input().
//	Modifies input_correct accordingly.

std::string convert_to_military_format(std::string time);
//	Uses string and iostream.
//	Returns a string containing the time in 24h military format, time must be
//	in 12h format: "11:30 PM".

int main()
{
	std::string time, result;

	
	std::cout << "This program converts a time in 12h format to military format.\n";

	input(time);

	result = convert_to_military_format(time);
	
	output(result);

	return 0;
}

void input(std::string& time)
{
	using namespace std;

	bool input_correct;
	do
	{
		cout << "Enter the time in 12h format: e.g. \"11:30 PM\".\n";
		getline(cin, time);
		check_input_for_errors(time, input_correct);	// Input correctness
	} while (!input_correct);							// bool is passed by
														// reference.
}

void check_input_for_errors(std::string input, bool& input_correct)
{
	using namespace std;

	input_correct = true;	// Assume the input format is correct, if errors
							// are found, this value is changed.


	//	First counter: looking for disordered input, missing punctuation etc.
	general_format_check(input, input_correct);
	
	
	//	Second counter: checking for invalid numerical input.
	check_integrity_of_numerical_input(input, input_correct);
	

	if (!input_correct)
		cout << "Input format incorrect. Try again.\n" << endl;
}

void read_numbers(std::string time, int& hour, int& minute)
{
	char hour_cstring[DIGIT_ARRAY_LIMIT],
		minute_cstring[DIGIT_ARRAY_LIMIT];

	int i = 0;
	while (!isdigit(time.at(i)) && i < static_cast<int>(time.length()))
		i++;

	hour_cstring[0] = time.at(i);
	if (i + 1 < static_cast<int>(time.length()) && isdigit(time.at(i + 1)))
		hour_cstring[1] = time.at(i + 1);

	while (time.at(i) != ':' && i < static_cast<int>(time.length()))
		i++;

	while (!isdigit(time.at(i)) && i < static_cast<int>(time.length()))
		i++;
	
	minute_cstring[0] = time.at(i);
	if (i + 1 < static_cast<int>(time.length()) && isdigit(time.at(i + 1)))
		minute_cstring[1] = time.at(i + 1);

	hour = atoi(hour_cstring);
	minute = atoi(minute_cstring);

	if (hour < 0 || hour > 12)
	{					//	It would make more sense to pass a boolean value
		std::cout << "Hour input invalid.\n";//	to main here and ask for input
		exit(1);		//	 again. But, given the project specification to build
	}					//	a function taking only a single string parameter,
						//  there is no straightforward way to accomplish that.
						//	check_input_for_errors() however, should prevent
	if (minute < 0 || minute > 60) //	these instructions from ever being
	{					//	executed.
		std::cout << "Minutes input invalid.\n";
		exit(1);
	}

}

bool is_am(std::string time)
{
	char target;

	for (int i = 0; i < static_cast<int>(time.length()); i++)
	{
		if ((time.at(i) == 'm' || time.at(i) == 'M') &&
			(i > 0))
			target = time.at(i - 1);	//	Looking for the character preceding
	}									//	an 'm' character.

	if (target == 'a' || target == 'A')
		return true;
	else if (target == 'p' || target == 'P')
		return false;
	else
	{
		std::cout << "Input format incorrect: no \"AM\" or \"PM\" string found.\n"
			<< std::endl;
		exit(1);		// It would make more sense to ask for input again here,
		return false;	// however, check_input_for_errors() should prevent these
	}					// instructions to ever being run.
}

std::string convert_time_to_24h(int& hour, int& minute, bool isam)
{
	using namespace std;

	string result;
	if (!isam)
		hour += 12;

	if (hour < 10)
		result = '0' + to_string(hour);
	else
		result = to_string(hour);

	if (minute < 10)
		result += '0' + to_string(minute);
	else
		result += to_string(minute);

	return result;
}

void output(std::string result)
{
	using namespace std;

	cout << result << " hours\n" << endl;
}

void general_format_check(std::string input, bool& input_correct)
{
	using namespace std;


	bool semicolon_present = false;	//	Proper punctuation is absent until found.
	bool antepostmeridiem_present = false;

	int i = 0;

	while ((input.at(i) == ' ' || input.at(i) == '\t') &&	// Instruction to
		i < static_cast<int>(input.length()))				// skip blanks.
		i++;

	if (!isdigit(input.at(i)))	// If the first non-blank is not a digit,
		input_correct = false;	// the input format is incorrect.

	for (; i < static_cast<int>(input.length()); i++)
	{
		if (input.at(i) == ':')	// If there is no semicolon, the input format
		{						// is incorrect.
			semicolon_present = true;
			while ((input.at(i) == ':' || // Move forward by at least 1 after
				input.at(i) == ' ' || input.at(i) == '\t') && // the ':'.
				i < static_cast<int>(input.length()))
				i++;

			if (!isdigit(input.at(i)))	// The next non-blank after the
				input_correct = false;	// semicolon must be a digit.
		}
		else if (input.at(i) == 'a' || input.at(i) == 'A' ||
			input.at(i) == 'p' || input.at(i) == 'P')
		{
			if (input.at(i + 1) == 'm' || input.at(i + 1) == 'M')
				antepostmeridiem_present = true;	// "AM" or "PM" must appear.
			else
			{
				cout << "Please specify whether the time provided is\n"
					<< "\"AM\" or \"PM\".\n" << endl;
				antepostmeridiem_present = false;	// This instruction is left
			}										// intentionally although
													// redundant.
		}
	}

	if (!semicolon_present || !antepostmeridiem_present)
		input_correct = false;
}

void check_integrity_of_numerical_input(std::string input, bool& input_correct)
{
	using namespace std;

	int i = 0;
	while (!isdigit(input.at(i)) && i < static_cast<int>(input.length()))
		i++;
	if (isdigit(input.at(i + 1)))
	{
		switch (input.at(i))	//	First digit must be either 0 or 1 (i.e.
		{						//	"20:00 AM" is not valid input).
		case '0':
			break;
		case '1':
			switch (input.at(i + 1))	//	If the first digit is a 1, then the
			{							//	second one must be either 0, 1 or 2
			case '0':					//	(i.e. "13:00 AM" is not valid input).
			case '1':
			case '2':
				break;
			default:
				cout << "Impossible hour value.\n" << endl;
				input_correct = false;
			}
			break;
		default:
			cout << "Impossible hour value.\n" << endl;
			input_correct = false;
		}
	}

	while (input.at(i) != ':' && i < static_cast<int>(input.length()))
		i++;		// Skip to the ':'

	while (!isdigit(input.at(i)) && i < static_cast<int>(input.length()))
		i++;
	if (isdigit(input.at(i + 1)))
	{
		switch (input.at(i))	//	First digit must be between 0 and 6 (i.e.
		{						//	"12:70 AM" is not valid input).
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			break;
		case '6':
			switch (input.at(i + 1))	//	If first digit is a 6, the second one
			{							//	can only be 0 (i.e. "12:61 AM" is not
			case '0':					//	valid input).
				break;
			default:
				cout << "Impossible minute value.\n" << endl;
				input_correct = false;
			}
			break;
		default:
			cout << "Impossible minute value.\n" << endl;
			input_correct = false;
		}
	}
}

std::string convert_to_military_format(std::string time)
{
	std::string result;
	int hour, minute;

	read_numbers(time, hour, minute);
	result = convert_time_to_24h(hour, minute, is_am(time));

	return result;
}
