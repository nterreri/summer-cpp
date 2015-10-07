// ch5proj16.cpp : Defines the entry point for the console application.
//Program that outputs the day of the week

#include "stdafx.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

void getInput(int&, int&, int&);
//prec: uses iostream
//postc: by-reference parameters are read from keyboard

bool isLeapYear(int year);
//prec: variable initialized
//returns true if year is a leap year, false otherwise

int getCenturyValue(int year);
//prec: variable initialized
//postc: the first two digits of the year are divided by 4 and the remained is stored
//the remainder is subtracted from 3 and the function returns this value multiplied by 2

int getYearValue(int year);
//prec: variable initialized
//postc: divides the last two digits of the year by 4 and discards the remainder
//returns the value of the last two digits added to this result

int getMonthValue(int month, int year);
//prec: variables initialized
//returns a predecided value for the month (sensititve to whether year is a leap year)

void output(int weekday);
//prec: parameter initialized, uses iostream and string
//postc: weekday is printed to screen in string format

int main()
{
	int day, month, year;
	int sum_of_values;
	int weekday;

	getInput(day, month, year);
	
	sum_of_values = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	weekday = sum_of_values % 7;

	output(weekday);
	
	return 0;
}

void getInput(int& day, int& month, int& year)
{
	bool input_correct = false; //assume input is incorrect
	char punctuation;

	while (!input_correct)
	{
		std::cout << "Enter the date in \'day/month/year\' format. Example: \'13/4/2008\'\n";
		
		std::cin >> day;
		if (day < 0 || day > 31)//check for illegal values
		{
			std::cout << "Input error: illegal day value.\n" << endl;
			continue;
		}
		
		std::cin >> punctuation;//read and check punctuation
		if (punctuation != '/')
		{
			std::cout << "Input error: numbers must be separated by the \'/\' character.\n"
				<< endl;
			continue;
		}

		std::cin >> month;
		if (month < 0 || month > 12)
		{
			std::cout << "Input error: illegal month value.\n" << endl;
			continue;
		}

		std::cin >> punctuation;
		if (punctuation != '/')
		{
			std::cout << "Input error: numbers must be separated by the \'/\' character.\n"
				<< endl;
			continue;
		}
		
		if (	(day > 30 && (month == 11 || month == 4 || month == 6 || month == 9))
			|| (day > 28 && month == 2)		) //check for illegal month - day combinations
		{
			std::cout << "Input error: illegal day - month combination.\n" << endl;
			continue;
		}

		std::cin >> year;
		if (year < 0)
		{
			cout << "Input error: illegal year value.\n" << endl;
			continue;
		}

		input_correct = true;//if the rest of the body of the loop is ran in order,
		//the input was correct
	}	
}

bool isLeapYear(int year)
{
	if (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0)))
		return true;
	else
		return false;
}

int getCenturyValue(int year)
{
	int first_digits = year / 100;
	//int division = first_digits / 4;
	int remainder = first_digits % 4;
	
	return (3 - remainder) * 2;
}

int getYearValue(int year)
{
	int last_digits = year % 100;
	int division = last_digits / 4;
	//int remainder = last_digits % 4;

	return last_digits + division;
}

int getMonthValue(int month, int year)
{
	switch (month)
	{
	case 1:
		if (isLeapYear(year))
			return 6;
		else
			return 0;
		break;
	case 2:
		if (isLeapYear(year))
			return 2;
		else
			return 3;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 1;
		break;
	case 6:
		return 4;
		break;
	case 7:
		return 6;
			break;
	case 8:
		return 2;
		break;
	case 9:
		return 5;
		break;
	case 10:
		return 0;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return 5;
		break;
	default:
		std::cout << "This should not happen.\n" << endl;
		std::exit(1);
	}
}

void output(int weekday)
{
	switch (weekday)
	{
	case 0:
		std::cout << "Sunday" << endl;
		break;
	case 1:
		std::cout << "Monday" << endl;
		break;
	case 2:
		std::cout << "Tuesday" << endl;
		break;
	case 3:
		std::cout << "Wednesday" << endl;
		break;
	case 4:
		std::cout << "Thursday" << endl;
		break;
	case 5:
		std::cout << "Friday" << endl;
		break;
	case 6:
		std::cout << "Saturday" << endl;
		break;
	default:
		std::cout << "This should not happen (2).\n" << endl;
		std::exit(1);
	}
}