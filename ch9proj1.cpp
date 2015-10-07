// ch9proj1.cpp : Defines the entry point for the console application.
//	Program to sum arbitrarily long numbers (revision of ch7proj7)

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>

const int NUM = 20;

std::string get_input();
//	Reads a line from keyboard and extracts the first substring of adjecent digits
//	it finds. Returns this string.
//	Uses iostream and string.

bool check_digit_presence(std::string line);
//	Returns true if line contains at list one digit character, false otherwise.
//	Uses iostream and string. Called by get_input().

int compute_max_size(std::string number1, std::string number2);
//	Returns the higher value between the length of number1 and number2.
//	Uses string. Called by compute_sum().

int* compute_sum(std::string number1_chars, std::string number2_chars);
//	Returns a pointer to an array of integer numbers. This array is constructed
//	to house the sum of the numbers in number1_chars and number2_chars.
//	Uses string.

int pen_paper_sum(int number1, int number2, int& carryover);
//	Returns a between 0 and 9: the sum of number1 and number2 and carryover.
//	Also changes carryover with a value between 0 and 1.
//	This function is meant to replicate one step of the "pen and paper" addition
//	algorythm: to sum two numbers between 0 and 9 carry over a 1 to the next step
//	in case the sum resulted in a number > 10.
//	Requires that number1 and number2 are between 0 and 9 to function correctly.

int convert_char_to_int(char letter);
//prec: parameter initialized
//postc: converts one char digit to 
//an int type



int main()
{

	std::cout << "This program computes the sum of two arbitrarily long\n"
		<< "numbers.\n";

	std::string number1, number2;
	int *result;

	number1 = get_input();
	number2 = get_input();
	
	//result = new int [compute_max_size(number1, number2) + 1];

	/*	The previous statement appears unnecessary: result is
	initialized to the addressed returned by a function whose
	type is int*	*/

	result = compute_sum(number1, number2);
	
	//	Output:
	int i = 0;
	if (result[0] == 0)
		i = 1;

	std::cout << "The result is:\n";
	for (; i < (compute_max_size(number1, number2) + 1); i++)
		std::cout << result[i];
	std::cout << std::endl;

	return 0;
}

std::string get_input()
{
	using namespace std;

	string whole_line, number_string;

	do
	{
		cout << "Enter the number:\n";
		getline(cin, whole_line);

	} while (!check_digit_presence(whole_line));
	//	If no digit is present,
	//	the user is prompted for
	//	input again.

	int i = 0;
	while (!isdigit(whole_line.at(i)) &&
		i < static_cast<int>(whole_line.length()))
	{
		i++;	//	Finds the index of the first digit in the input line.
	}

	int i2 = i;
	while (i2 < static_cast<int>(whole_line.length()) &&
		isdigit(whole_line.at(i2)))
	{
		i2++;	//	Finds the index of the first non-digit after the first digit.
	}

	number_string = whole_line.substr(i, i2 - i);	
							//	The substring between 
							//	the first index and
	return number_string;	//	the second one is the 
							//	target string of digits.
}

bool check_digit_presence(std::string line)
{
	for (int i = 0; i < static_cast<int>(line.length()); i++)
	{
		if (isdigit(line.at(i)))
			return true;
	}

	std::cout << "Input must be a number.\n";
	return false;
}

int compute_max_size(std::string number1, std::string number2)
{
	if (number1.length() >= number2.length())
		return number1.length();

	else //if (number2.length() > number1.length())
		return number2.length();
}

int* compute_sum(std::string number1_chars, std::string number2_chars)
{
	int *number1_integers, *number2_integers;
	int *result;

	//	All dynamic int pointers are allocated enough room to store the largest
	//	of the two numbers. The result pointer is allocated enough room to
	//	accommodate the largest one plus one.

	//	This is done to so that if there is any carry over on the last
	//	number in the array pointer, it can easily be put in the first
	//	index of the result array pointer.
	int largest_size = compute_max_size(number1_chars, number2_chars);

	number1_integers = new int[largest_size];
	number2_integers = new int[largest_size];
	result = new int[largest_size + 1];

	//	Initialize first integer dynamic pointer:
	//	The smaller of the two pointers is initialized for less 
	//	than its allotted size, the remaining spots are initialized to 0.
	//	The larger pointer is initialized for the whole of its allotted size,
	//	so there are no remaining spots to fill.

	//	This is done in reverse (from the last spot to the first) to facilitate
	//	carrying over in the pen and paper algorithm.
	int index_n = largest_size - 1;
	int index_s = number1_chars.length() - 1;
	while (index_s >= 0	&& 
		index_n >= (largest_size - static_cast<int>(number1_chars.length())))
	{
		number1_integers[index_n] = convert_char_to_int(number1_chars.at(index_s));
		index_n--;
		index_s--;
	}	//	Counting down with two index: one for the int* and the other for
		//	the string. Recall the the first is allotted more space than the
		//	latter, even though the content of the latter gets copied onto the
		//	first.
	while (index_n >= 0)
	{
		number1_integers[index_n] = 0;
		index_n--;
	}


	//	Initialize second integer dynamic pointer:
	//	See previous comment.
	index_n = largest_size - 1;
	index_s = number2_chars.length() - 1;
	while (index_s >= 0 &&
		index_n >= (largest_size - static_cast<int>(number2_chars.length())))
	{
		number2_integers[index_n] = convert_char_to_int(number2_chars.at(index_s));
		index_n--;
		index_s--;
	}

	while (index_n >= 0)
	{
		number2_integers[index_n] = 0;
		index_n--;
	}
	
	//	For testing purposes:

	/*for (int i = 0; i < largest_size; i++)
		std::cout << number1_integers[i];
	std::cout << std::endl;
	for (int i = 0; i < largest_size; i++)
		std::cout << number2_integers[i];
	std::cout << std::endl;*/

	//	Summing each int in array one by one:
	int carryover = 0;
	for (int i = largest_size - 1; i >= 0; i--)
	{
		result[i + 1] = 
			pen_paper_sum(number1_integers[i], number2_integers[i], carryover);
	}
	
	result[0] = carryover;	

	return result;
}

int pen_paper_sum(int number1, int number2, int& carryover)
{
	int result;
	
	result = number1 + number2 + carryover;
	carryover = result / 10;	//	The expression evaluates to 1 whenever
								//	result is between 10 and 19.
	
	result = result - 10 * carryover;	//	carryover is either 0 or 1.
										//	Where carryover is 1,
										//	result = result - 10.
	
	return result;
}

int convert_char_to_int(char letter)
{
	switch (letter)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	default:
		std::cout << "This should not happen.\n";
		exit(1);
	}
}
