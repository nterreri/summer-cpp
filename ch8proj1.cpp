// ch8proj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

const int MAX = 100;

void build_line(char line[]);
//Prompts user for input, reads a line and selectively
//copies/alters user-input to construct char line[] so
//that its first letter is uppercase, any repeated blanks
//or newlines are treated as a single space (' '),
//and any uppercase letter after the first is turned
//to lowercase.

void skip_blanks(char& next);
//Skips the next spaces/tabs/newlines in input cin.

int main()
{

	char line[MAX];
	
	build_line(line);

	std::cout << "The line entered is:\n";
	std::cout << line;

	return 0;
}

void build_line(char line[])
{
	std::cout << "Enter the line, end your line with a period,\n"
		<< "('.'):\n";

	int i = 0;
	char next;
	std::cin.get(next);
	while (i < MAX - 1 && next != '.')
	{
		if (i == 0)
		{
			if (next == ' ' || next == '\t' || next == '\n')
			{
				while (next == ' ' || next == '\t' || next == '\n')
					std::cin.get(next);
			}

			if (islower(next))
				next = toupper(next);
		}
		else
		{
			if (isupper(next))
				next = tolower(next);
		}

		line[i] = next;
		std::cin.get(next);
		if (next == ' ' || next == '\t' || next == '\n')
		{
			i++;
			line[i] = ' ';
			while (next == ' ' || next == '\t' || next == '\n')
				std::cin.get(next);
		}
		i++;
	}
	line[i] = '.';
	line[i + 1] = '\0';
}

void skip_blanks(char& next)
{
	while (next == ' ' || next == '\t' || next == '\n')
		std::cin.get(next);
}
