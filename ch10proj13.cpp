// ch10proj13.cpp : Defines the entry point for the console application.
//	Program to implement POSTNET bar code class

#include "stdafx.h"
#include <iostream>
#include <string.h>

const int DIGITSIZE = 5;
const int MIN = 27;
const int MAX = 52;
const int NUMARRSIZE = MAX / DIGITSIZE;


class Postnet
{
public:
	//	Constructors:
	Postnet(char* barcode);
	Postnet(int zipcode);
	Postnet();

	//	Accessors:
	void get_barcode(char* arraystorage);
	int get_zipcode();

private:
	void convert_zip_to_bar(int zipcode, char* bar);
	char* encode_number(int number);
	int convert_bar_to_zip(char* barcode);
	int decode_digit(char* encoded_digit);
	
	int zip;
};

//	Driver:
int main()
{
	//	Testing constructors:

	Postnet zip1;
	Postnet zip2(99504);
	Postnet zip3("110100101000101011000010011");

	//	Testing accessors:

	std::cout << "zip3 zipcode number: " << zip3.get_zipcode() << std::endl;

	char zip2bar[MAX];
	zip2.get_barcode(zip2bar);

	std::cout << "zip2 barcode number: ";
	//	In this example, we know that the barcode is minimum size (MIN), generally
	//	to output the barcode result without terminal garbage data at the end of the
	//	array, it is necessary to either know how much of the array was filled, or
	//	stop at the NULL character:
	for (int i = 0; i < MIN /*&& zip2bar[i] != '\0'*/; i++)
		std::cout << zip2bar[i];
	std::cout << std::endl;

	return 0;
}

//	Returns the address of a temporary c-string, to be used with strcat:
char* Postnet::encode_number(int number)
{
	switch (number)
	{
	case 11:
		return "11000";
	case 10:
		return "10110";
	case 9:
		return "10100";
	case 8:
		return "10010";
	case 7:
		return "10001";
	case 6:
		return "01100";
	case 5:
		return "01010";
	case 4:
		return "01001";
	case 3:
		return "00110";
	case 2:
		return "00101";
	case 1:
		return "00011";
	case 0:
		return "11000";
	default:
		return "\0";
	}
}

//	The public get_barcode is just a call to the private convert_zip_to_bar,
//	the first argument is just a copy of the zip of the calling object, this is done
//	intentionally so that convert_zip_to_bar can also be used for other purposes:
void  Postnet::get_barcode(char bar[MAX])
{
	convert_zip_to_bar(zip, bar);
}

void Postnet::convert_zip_to_bar(int zipcode, char bar[MAX])
{
	//	Assuming max postcode size is (MAX / DIGITSIZE) digits:
	int number_array[NUMARRSIZE];

	//	First, find out the order of magnitude:
	int order_of_magnitude = 0;
	while (zipcode / pow(10, order_of_magnitude) > 10)
		order_of_magnitude++;

	//	Then, place each digit composing the zipcode into an array:
	for (int i = 0; i < NUMARRSIZE && order_of_magnitude >= 0; i++)
	{
		number_array[i] = static_cast<int>(zipcode / pow(10, order_of_magnitude));
		zipcode -= static_cast<int>(number_array[i] * pow(10, order_of_magnitude));
		order_of_magnitude--;
	}

	//	Then, begin initializing the barcode array:
	bar[0] = '1';
	bar[1] = '\0';

	//	Then, use strcat to concatenate the encoding of each number after this value:
	int chararraypos = 1;
	int numberarraypos = 0;
	while (chararraypos < MAX &&
		numberarraypos < NUMARRSIZE)
	{
		strcat_s(bar, MAX, encode_number(number_array[numberarraypos]));
		chararraypos += DIGITSIZE;
		numberarraypos++;
	}
	strcat_s(bar, MAX, "1");
	//	Note: visual studio community 2013 enforces the use of strcat_s over strcat.
}

int Postnet::get_zipcode()
{
	return zip;
}

//	Implementation with C-Strings, the other option being the <string> class
Postnet::Postnet(char* barcode)
{
	int i = 0;

	while (i < MAX &&
		barcode[i] != '\0')
	{
		//	Checking if any character on the string is not a 0 or a 1 (or the 
		//	null character:
		if (barcode[i] != '0' &&
			barcode[i] != '1' &&
			barcode[i] != '\0')
		{
			std::cout << "Each value in barcode must be either 0 or 1.\n"
				<< "Terminating program...\n";
			exit(1);
		}
		i++;
	}
		
	


	//	Checking for begin and end:
	if (barcode[0] != '1' || barcode[i - 1] != '1')
	{
		std::cout << "Constructor error: barcode must begin and end with a 1.\n"
			<< "Terminating program...\n";
		exit(1);
	}

	//	Checking that the number encorded is at least 5 digits long:
	if (i < MIN)
	{
		std::cout << "Constructor error: barcode must be at least " << MIN
			<< " digits long.\n"
			<< "Terminating program...\n";
		exit(1);
	}

	//	Checking that the length of the barcode is a multiple of DIGITSIZE, plus 2:
	//	the beggining and end 1s:
	if (( (i - 2) % DIGITSIZE ) != 0)
	{
		std::cout << "The length of the barcode must be a multiple of " << DIGITSIZE
			<< ", plus 2.\n"
			<< "Terminating program...\n";
		exit(1);
	}


	zip = convert_bar_to_zip(barcode);
}

int Postnet::convert_bar_to_zip(char* barcode)
{
	int length = 0;

	//	Figure out the length (this could be done invoking string.length())
	while (length < MAX &&
		barcode[length] != '\0')
		length++;
	
	//	The order of magnitude is the exponent of 10 to which a decoded digit
	//	must be multiplied (in other words, it is used to figure out which decimal
	//	position a decoded digit occupies):
	int order_of_magnitute = ((length - 2) / 5) - 1;

	//	Each 5 numbers digit is recorded in the following array:
	char encoded_digit[DIGITSIZE];
	int decoded_number = 0;

	for (int i = 1; i < (length - 1);)
	{
		int i2 = 0;
		//	Do this DIGITSIZE times:
		while (i2 < DIGITSIZE &&
			i < (length - 1))
		{
			encoded_digit[i2] = barcode[i];
			i2++;
			i++;
		}

		//	Decoded number is the sum of each decoded digit multiplied by its proper
		//	power of ten:
		decoded_number += decode_digit(encoded_digit) * 
			static_cast<int>(pow(10, order_of_magnitute));
		order_of_magnitute--;
	}


	return decoded_number;
}

//	This is the function to alter to change the encoding:
int Postnet::decode_digit(char* encoded_digit)
{
	int result =
	(encoded_digit[0] - '0') * 7 + (encoded_digit[1] - '0') * 4 + (encoded_digit[2] - '0')
	* 2 + (encoded_digit[3] - '0') * 1 + (encoded_digit[4] - '0') * 0;

	if (result == 11)
		return 0;
	else
		return result;
}

Postnet::Postnet(int zipcode)
{
	zip = zipcode;
}

//	Since there are no modifiers, this constructor is effectively useless
//	unless 0 is a legitimate zip code
Postnet::Postnet()
{
	//	Empty
}

