// ch8proj3.cpp : Defines the entry point for the console application.
// Program to read and clean a double.

#include "stdafx.h"
#include <iostream>

void new_line();

void read_and_clean(double& n);

int main()
{
	double n;
	char ans;

	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);

	do
	{
		std::cout << "Enter a float and press Return: ";
		read_and_clean(n);
		std::cout << "That string converts to the double " << n << std::endl;
		std::cout << "Again? (yes/no): ";
		std::cin >> ans;
		new_line();
	} while (ans != 'n' && ans != 'N');

	return 0;
}

void read_and_clean(double& n)
{
	using namespace std;

	const int ARRAY_SIZE = 100;
	char double_string[ARRAY_SIZE];


	char next;
	cin.get(next);
	int index = 0;
	int precision_counter = 1;
	bool dotmet = false;
	while (next != '\n')
	{
		if (isdigit(next) && (index < ARRAY_SIZE - 1))
		{
			double_string[index] = next;
			index++;
		}
		else if (next == '.' && !dotmet)
		{
			double_string[index] = next;
			dotmet = true;
			precision_counter = index++;
		}
		cin.get(next);
	}


	std::cout.precision((index - precision_counter) - 1);
	n = atof(double_string);
}

void new_line()
{
	char next;
	std::cin.get(next);
	while (next != '\n')
		std::cin.get(next);
}