// ch6proj14.cpp : Defines the entry point for the console application.
//Program to respond to any question with predefined answers, modification of ch6proj13

#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

const int NUMBER_OF_CHAPTERS = 17;
const int ANSWERS = 8;

void keyboard_input(int& input_count);
//prec: uses iostream
//postc: reads one line of input, and checks that it ends with "?" before the newline character
//also counts the number of characters in the question, and passes it to the output question via
//a variable in main

void output(std::ifstream& is, int input_count);
//prec: is must be accessing a file, uses fstream and iostream;
//warning: input file's last line of text must end with the newline character
//otherwise the program does not terminate upon reading the last line
//postc: reads one line from a file, then outputs an answer
//if it reaches the end of the file, it closes and opens the stream again
//also responds with different chapter numbers where appropriate

void check_for_N(std::ifstream& is, int input_count, char next);
//prec: subroutine of "output(int&)", uses fstream and iostream
//postc: checks if the next character in "is" is N, in which case it outputs
//"n + 1" and lowers "n" by one, also if this puts "n" below 0, it resets "n" to "NUMBER_OF_CHAPTERS"

int main()
{
	using namespace std;

	ifstream is;
	char loopcontrol;
	int input_count;

	cout << "This program will answer any question.\n" << endl;

	is.open("answers.txt");
	if (is.fail())
	{
		cout << "Failed to open answers file.\n" << endl;
		exit(1);
	}

	do
	{

		keyboard_input(input_count);
		output(is, input_count);

		cout << "Hopefully, that answered your question.\n"
			<< "Would you like to enter another question? (y/n)\n" << endl;
		cin >> loopcontrol;
		cin.ignore(); //skips newline character otherwise it messes with keyboard_input() at the next iteration
	} while (loopcontrol == 'y' || loopcontrol == 'Y');

	return 0;
}

void keyboard_input(int& count)
{
	using namespace std;

	char previous, next;

	cout << "Type your one-line question (include a question mark at the end):\n" << endl;

	count = 1;
	cin.get(next);
	while (next != '\n')
	{
		previous = next;
		cin.get(next);
		count++;
	}

	if (previous == '?')
		;
	else
	{
		cout << "Are you sure that's a question?\n"
			<< "Try ending your line with \'?\' before pressing enter.\n" << endl;

		keyboard_input(count);
	}
}

void output(std::ifstream& is, int count)
{
	using namespace std;

	char next;

	is.close();
	is.open("answers.txt");
	if (is.fail())
	{
		cout << "Failed to re-open answers file.\n" << endl;
		exit(1);
	}
	//is.ignore(); //skips the "begin of file" character

	//int store = count%ANSWERS; for 
	for (int i = 0; i < count%ANSWERS; i++)//skip to line number count%ANSWERS
	{
		is.get(next);//gets the next character in file (either the very first,
		while (next != '\n') //or the one following the previous iteration of the for loop
			is.get(next);
	}

	if (is.eof()) //if there are no more characters, reopens the file (warning: should break the program
	{				//when the answer file is empty)
		is.close();
		is.open("answers.txt");
		if (is.fail())
		{
			cout << "Failed to re-open answers file.\n" << endl;
			exit(1);
		}
		is.ignore(); //skips the "begin of file" character
	}

	is.get(next); //gets the next thing after the endline detected by the previous loop (if any)
	while (next != '\n') //until the end of a line ...
	{
		if (next == '#')
		{
			check_for_N(is, count, next);
		}
		else
			cout.put(next);

		is.get(next); //... gets the next character
	}
	cout.put('\n'); //puts a newline to make output more legible
}

void check_for_N(std::ifstream& is, int count, char next)
{
	using namespace std;

	is.get(next);
	if (next == 'N')
	{
		cout << count%NUMBER_OF_CHAPTERS + 1;
	}
	else
	{
		cout.put('#');
		cout.put(next);
	}
}