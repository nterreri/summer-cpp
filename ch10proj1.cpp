// ch10proj1.cpp : Defines the entry point for the console application.
//	Program to read and output student record

#include "stdafx.h"
#include <iostream>
#include <iomanip>

struct StudentRecord{
	char grade;
	int quiz1, quiz2;
	int exam1, exam2;
};

void read_scores(StudentRecord& record);
//	Reads numeric values into record
//	Uses iostream

void newline(std::istream& is = std::cin);
//	Skips to the next line in input
//	Uses istream

void output(StudentRecord record);
//	Ouputs the content of record
//	Uses iostream

char get_result(StudentRecord record);
//	Returns a letter between 'A' and 'F'
//	Calls compute_grade()

int compute_grade(StudentRecord record);
//	Returns a number between 0 and 100 based
//	on a weighted average of the numerical values in record

int main()
{
	StudentRecord record;

	read_scores(record);
	record.grade = get_result(record);

	output(record);

	return 0;
}

void read_scores(StudentRecord& record)
{
	using namespace std;
	bool input_valid;

	do
	{
		input_valid = true;

		cout << "Enter the mark for the first quiz:\n";
		cin >> record.quiz1;
		
		if (record.quiz1 < 0 || record.quiz1 > 10 || !cin)
		{
			input_valid = false;
			cout << "Input invalid: input must be a number between 0 and 10.\n";
			cin.clear();
			newline();
		}

		
	} while (!input_valid);

	do
	{
		
		input_valid = true;

		cout << "Enter the mark for the second quiz:\n";
		cin >> record.quiz2;
		
		if (record.quiz2 < 0 || record.quiz2 > 10 || !cin)
		{
			input_valid = false;
			cout << "Input invalid: input must be a number between 0 and 10.\n";
			cin.clear();
			newline();
		}

		
	} while (!input_valid);

	do
	{
		input_valid = true;

		cout << "Enter the mark for the midterm exam:\n";
		cin >> record.exam1;

		if (record.exam1 < 0 || record.exam1 > 100 || !cin)
		{
			input_valid = false;
			cout << "Input invalid: input must be a number between 0 and 100.\n";
			cin.clear();
			newline();
		}

		
	} while (!input_valid);

	do
	{
		input_valid = true;

		cout << "Enter the mark for the final exam:\n";
		cin >> record.exam2;

		if (record.exam2 < 0 || record.exam2 > 100 || !cin)
		{
			input_valid = false;
			cout << "Input invalid: input must be a number between 0 and 100.\n";
			cin.clear();
			newline();
		}

		
	} while (!input_valid);
}

void newline(std::istream& is)
{
	char symbol;

	do
	{
		is.get(symbol);
	} while (symbol != '\n');
}

void output(StudentRecord record)
{
	using namespace std;

	cout << "Overall grade: " << record.grade << endl
		<< "Quiz 1 result: " << record.quiz1 << endl
		<< "Quiz 2 result: " << record.quiz2 << endl
		<< "Midterm exam result: " << record.exam1 << endl
		<< "Final exam result: " << record.exam2 << endl;

}

char get_result(StudentRecord record)
{
	int numeric_score = compute_grade(record);

	if (numeric_score >= 90)
		return 'A';
	else if (numeric_score >= 80 && numeric_score < 90)
		return 'B';
	else if (numeric_score >= 70 && numeric_score < 80)
		return 'C';
	else if (numeric_score >= 60 && numeric_score < 70)
		return 'D';
	else
		return 'F';
}

int compute_grade(StudentRecord record)
{
	double result = record.exam2 * 0.5 + 
					record.exam1 * 0.25 +
					(record.quiz1 * 5 + record.quiz2 * 5) * 0.25;

	if ( (result - static_cast<int>(result))
		>= 0.5)
		return static_cast<int>(result + 1);
	else
		return static_cast<int>(result);
}