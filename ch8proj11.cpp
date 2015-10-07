// ch8proj11.cpp : Defines the entry point for the console application.
//	Program to convert a name to pig latin.

#include "stdafx.h"
#include <iostream>
#include <string>


void input(std::string& first, std::string& last);

std::string get_conversion_to_piglatin(std::string first, std::string last);

void make_lowercase(std::string& s);

void translate_to_piglatin(std::string& s);

void output(std::string s);

//main
int main()
{
	std::string first, last, piglatin;

	std::cout << "This program converts your name to piglatin.\n" << std::endl;
	input(first, last);
	piglatin = get_conversion_to_piglatin(first, last);

	std::cout << "Your name in piglatin is:\n";
	output(piglatin);

	return 0;
}

void input(std::string& first, std::string& last)
{
	using namespace std;

	cout << "Enter your first name:\n";
	cin >> first;
	cout << "Enter your last name:\n";
	cin >> last;
}

std::string get_conversion_to_piglatin(std::string first, std::string last)
{
	make_lowercase(first);
	make_lowercase(last);

	translate_to_piglatin(first);
	translate_to_piglatin(last);

	return (first + " " + last);
}

void make_lowercase(std::string& s)
{
	for (int i = 0; i < static_cast<int>(s.length()); i++)
		s.at(i) = tolower(s.at(i));
}

void translate_to_piglatin(std::string& s)
{
	if (s.length() > 0)
	{
		switch (s.at(0))
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			s += "way";
			break;
		default:
			std::string initial;	//	Because there is no constructor to
			initial = s.at(0);		//	initialize a string with a char,
									//	it is necessary to separate declaration
			s = s.substr(1, s.length() - 1);	//	and assignment.
			s += initial + "ay";
		}

		s.at(0) = toupper(s.at(0));
	}
}

void output(std::string s)
{
	using namespace std;

	cout << endl;
	cout << s;
	cout << endl;
}