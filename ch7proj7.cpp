// ch7proj7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

const int NUM = 20;


void input(char a[], int& used_size);
//prec: uses iostream
//postc: initialized array with used_size values
//(at most NUM values)

void output(char a[], int used_size);
//prec: parameters initialized, usesiostream
//postc: the first used_sized values in array are printed

void convert_array_to_int(const char a[], int converted[], int used_size);
//prec: parameters initialized
//postc: converts the digits in array a from char type to
//int type and places them in converted[] in reverse order

int convert_char_to_int(char letter);
//prec: parameter initialized
//postc: converts one char digit to 
//an int type

void sum(int result[], int& result_size, int number1[], int size1,
	int number2[], int size2);
//prec: parameters are initialized appropriately.
//postc: initializes result array and result_size by summing 
//(and carrying where necessary) each of the digits in each
//of the int bytesizes in number1 and number2.
//Initializes result_size as the largest of size1 and size2,
//or, if there is leftover carry after the sum of the last digit
//of the larger of number1 and number2, as this largest size + 1.
//Also, determines the smaller between size1 and size2 and 
//fills in the difference of spaces between the two arrays
//with zeroes in the smaller one to facilitate summing and
//carrying.

void straighten_result(int result[],
	const int result_inverted[], int result_size);
//prec: const array and int parameter initialized appropriately.
//called by sum().
//postc: result array is the content of result_inverted inverted.

void convert_array_to_char(const int a[], char converted[], int size);
//prec: parameters initialized appropriately.
//postc: copies the digits in array a into array converted
//from type int to type char

char convert_int_to_char(int digit);
//prec: parameter initialized.
//returns the appropriate integer character
//for the integer number argument.
//called by convert_array_to_char()

int main()
{
	char number1[NUM];
	int size1;
	char number2[NUM];
	int size2;
	char result_to_display[NUM];

	int converted_number1[NUM];
	int converted_number2[NUM];
	int result[NUM];
	int result_size;

	input(number1, size1);
	input(number2, size2);

	convert_array_to_int(number1, converted_number1, size1);
	convert_array_to_int(number2, converted_number2, size2);

	sum(result, result_size, converted_number1, 
		size1, converted_number2, size2);

	convert_array_to_char(result, result_to_display, result_size);
	output(result_to_display, result_size);

	return 0;
}

void input(char a[], int& used_size)
{
	using namespace std;

	cout << "Enter the number:\n";
	used_size = 0;
	char next;
	cin.get(next);
	for (int i = 0; i < NUM && next != '\n'; i++)
	{
		if (isdigit(next))
		{
			a[i] = next;
			cin.get(next);
			used_size++;
		}
		else
		{
			cout << "Input must be a number at most 20 digits long.\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			input(a, used_size);
		}
	}

	if (used_size == NUM)
	{
		if (next != '\n')
		{
			cout << "Input must be a number at most 20 digits long.\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			input(a, used_size);
		}
	}
	
}

void output(char a[], int used_size)
{

	if (used_size > 20)
		std::cout << "Integer overflow.\n";
	
	else
	{
		for (int i = 0; i < used_size; i++)
			std::cout << a[i];
		std::cout << std::endl;
	}
}

void convert_array_to_int(const char a[], int converted[], int used_size)
{
	int index1, index2;
	index1 = used_size - 1;
	index2 = 0;
	while (index2 < used_size && index1 >= 0)
	{
		converted[index2] = convert_char_to_int(a[index1]);
		index1--;
		index2++;
	}
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

void sum(int result[], int& result_size, int number1[], int size1,
	int number2[], int size2)
{
	int result_inverted[NUM];

	int larger_size;
	if (size1 > size2)
	{
		larger_size = size1;
		for (int i = size2; i < larger_size; i++)
			number2[i] = 0;
	}
	else if (size2 > size1)
	{
		larger_size = size2;
		for (int i = size1; i < larger_size; i++)
			number1[i] = 0;
	}
	else
		larger_size = size1; //size1 == size2
	
	int carry = 0;
	for (int i = 0; i < larger_size; i++)
	{
		int result = number1[i] + number2[i] + carry;
		carry = 0;
		if (result >= 10)
		{
			carry = result / 10;
			result = result % 10;
		}
		result_inverted[i] = result;
	}

	if (carry > 0)
	{
		result_inverted[larger_size] = carry;
		result_size = larger_size + 1;
	}
	else
		result_size = larger_size;

	straighten_result(result, result_inverted, result_size);
}

void straighten_result(int result[],
	const int result_inverted[], int result_size)
{
	int index_straight = 0,
		index_inverted = result_size - 1;

	while (index_straight < result_size && index_inverted >= 0)
	{
		result[index_straight] = result_inverted[index_inverted];
		index_straight++;
		index_inverted--;
	}
}

void convert_array_to_char(const int a[], char converted[], int size)
{
	for (int i = 0; i < size; i++)
		converted[i] = convert_int_to_char(a[i]);
}

char convert_int_to_char(int digit)
{
	switch (digit)
	{
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	default:
		std::cout << "This should never happen.\n";
		exit(1);
	}
}