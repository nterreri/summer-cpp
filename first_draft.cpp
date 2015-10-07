// ch7proj2.cpp : Defines the entry point for the console application.
//Program to sum two hexadecimals up to 10 digits in length

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

const int LIMIT = 10;


//Function that takes in a hex char and retruns an int:
int convert_hex_digit_to_decimal(char parameter);
//Prec: uses iostream, parameter is initialized
//postc: a switch operates on the char to decide which integer
//value to return on the basis of the 16 characters/digits
//in the hexadecimal system



int main()
{
	using namespace std;

	char hexa[LIMIT] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char hexb[LIMIT] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	int deca;
	int decb;

	cout << "This program sums two hexadecimal from user input,"
		<< "only up to " << LIMIT << " digits long hexadecimals are here allowed.\n"
		<< "Hexadecimal numbers are represented by digits 0 through 9 and letters\n"
		<< "\'a\' through \'f\'.\n"
		<< "No other characters are allowed.\n"
		<< endl;

	//read input:


	cout << "Enter the first hexadecimal, then press enter:\n";
	char next;
	int char_bytesize, index_buffer = 0;
	char hexbuffer1[LIMIT] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };

	int index = 0;
	cin.get(next);
	while (index < LIMIT && next != '\n')
	{
		hexa[index] = next;
		cin.get(next);
		index++;
	}
	int hexsize = index;



	//convert whole string to decimal:

	//A for loop accesses the array read and multiplies
	//the value at the first (0th) address by 16^(hexsize - 1)
	//the next (1st) value is then accessed and multiplied by
	//16^(hexsize - 2) (and stored in an integer iterating sum
	//starting from 0,
	//representing the decimal conversion of the hex number).
	//This goes on as long as hexsize > 0 or hexsize - 1 hex array
	//values are accessed.
	//To obtain this, the program counts up the values in
	//the hex array until i < hexsize; and counts down with
	//a different counter until this other index is > 0

	int sum = 0;
	int index1 = 0, index2 = hexsize - 1;

	while (index1 < hexsize && index2 >= 0)
	{
		sum += convert_hex_digit_to_decimal(hexa[index1]) * pow(16, index2);
		index1++;
		index2--;
	}

	return sum;

	//summing the two numbers:

	int decimal = deca + decb;
	if (decimal > 1099511627775)//if the number cannot be written in 10 hex digits,
		cout << "Addition overflow.\n" << endl;
	//else
	//output sum in hex:
	//get the highest power of 16 that is less than
	//the decimal
	int store[10];
	int result;
	int difference;
	int power;

	for (power = 0; pow(16, power) < decimal; power++)
		;
	power--;
	//divide the decimal number by this power
	result = decimal / power;
	store[index] = convert_decimal_digit_to_hex

		//compute the difference between the decimal and
		//the result from the previous step times the current
		//power of 16
		difference = decimal - result;

	//then do the same with this result and the next
	//smaller power of 16
	power--;


	return 0;
}

// Function that takes in a hex char and retruns an int:
int convert_hex_digit_to_decimal(char parameter)
{
	using namespace std;

	switch (parameter)
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
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	default:
		cout << "String entered is not a hex number.\n" << endl;
		//recall input function here
		exit(1);
	}
}