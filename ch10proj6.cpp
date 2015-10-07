// ch10proj6.cpp : Defines the entry point for the console application.
/*Define a class called Month that is an abstract data type for a month. Your
class will have one member variable of type int to represent a month
(1 for January, 2 for February, and so forth). Include all the following member
functions: a constructor to set the month using the first three letters in
the name of the month as three arguments, a constructor to set the month
using an integer as an argument (1 for January, 2 for February, and so
forth), a default constructor, an input function that reads the month as an
integer, an input function that reads the month as the first three letters in
the name of the month, an output function that outputs the month as an
integer, an output function that outputs the month as the first three letters
in the name of the month, and a member function that returns the next
month as a value of type Month. The input and output functions will each
have one formal parameter for the stream. Embed your class definition in
a test program.*/

#include "stdafx.h"
#include <iostream>
#include <fstream>

class Month
{
public:
	//	Constructors:

	Month(char initial1, char initial2, char initial3);
	Month(int par);
	Month();

	//	I/O:

	void input_int(std::istream& is = std::cin);
	void input_char(std::istream& is = std::cin);

	void output_int(std::ostream& os = std::cout);
	void output_char(std::ostream& os = std::cout);

	//	Next month function:

	Month next_month();

private:
	int convert_to_numeric(char initial1, char initial2, char initial3);
	void convert_to_alphabetic(char& initial1, char& initial2, char& initial3);
	int month;
};

void nextbreak(std::istream& is = std::cin);
//	Makes the input stream skip to the next space, tab, newline or NULL
//	character

int main()
{
	//	Testing constructors:
	Month month1;
	Month month2(2);
	Month month3('j', 'u', 'l');

	//	Testing input:
	std::cout << "Enter a month in number form:\n";
	month1.input_int();

	std::ifstream is;

	is.open("input.txt");
	if (is.fail())
		exit(1);

	month2.input_char(is);

	is.close();

	//	Testing output:
	std::ofstream os;
	os.open("output.txt");
	if (os.fail())
		exit(1);

	month3.output_int(os);

	os.close();

	month1.output_char();

	//	Testing next_month:
	Month after_month1 = month1.next_month();


	return 0;
}

Month::Month(char initial1, char initial2, char initial3)
{
	month = convert_to_numeric(initial1, initial2, initial3);
}

Month::Month(int par)
{
	if (par < 1 || par > 12)
	{
		std::cout << "Numeric month value must be an integer between 1 and 12.\n"
			<< "Program will now exit.\n";
		exit(1);
	} 
	else
		month = par;
}

Month::Month()
{
	month = 1;
}

int Month::convert_to_numeric(char initial1, char initial2, char initial3)
{
	switch (initial1)
	{
	case 'j':
	case 'J':
		switch (initial2)
		{
		case 'a':
		case 'A':
			return 1;
			break;
		case 'u':
		case 'U':
			switch (initial3)
			{
			case 'n':
			case 'N':
				return 6;
				break;
			case 'l':
			case 'L':
				return 7;
				break;
			default:
				std::cout << "Month name not recognized, setting to default (Jan)\n";
				return 1;
			}
			break;
		default:
			std::cout << "Month name not recognized, setting to default (Jan)\n";
			return 1;
		}
		break;

	case 'f':
	case 'F':
		return 2;
		break;

	case 'm':
	case 'M':
		switch (initial2)
		{
		case 'a':
		case 'A':
			switch (initial3)
			{
			case 'r':
			case 'R':
				return 3;
				break;
			case 'y':
			case 'Y':
				return 5;
				break;
			default:
				std::cout << "Month name not recognized, setting to default (Jan)\n";
				return 1;
			}
		default:
			std::cout << "Month name not recognized, setting to default (Jan)\n";
			return 1;
		}
		break;

	case 'a':
	case 'A':
		switch (initial2)
		{
		case 'p':
		case 'P':
			return 4;
			break;
		case 'u':
		case' U':
			return 8;
			break;
		default:
			std::cout << "Month name not recognized, setting to default (Jan)\n";
			return 1;
		}
		break;

	case 's':
	case 'S':
		return 9;
		break;

	case 'o':
	case 'O':
		return 10;
		break;

	case 'n':
	case 'N':
		return 11;
		break;

	case 'd':
	case 'D':
		return 12;
		break;

	default:
		std::cout << "Month name not recognized, setting to default (Jan)\n";
		return 1;
	}
}

void Month::input_int(std::istream& is)
{
	using namespace std;
	bool input_correct;

	do
	{
		input_correct = true;

		is >> month;

		if (month < 1 || month > 12)
		{
			cout << "Month value must be a number between 1 and 12.\n";
			nextbreak(is);
			input_correct = false;
		}

	} while (!input_correct);
	
}

void nextbreak(std::istream& is)
{
	char symbol;

	do
	{
		is.get(symbol);
	} while (symbol != '\n' && symbol != '\t' && symbol != ' ' && 
		symbol != '\0');
}

void Month::input_char(std::istream& is)
{
	using namespace std;
	char initial1, initial2, initial3;

	is >> initial1 >> initial2 >> initial3;
	nextbreak();

	month = convert_to_numeric(initial1, initial2, initial3);
}

void Month::output_int(std::ostream& os)
{
	os << month;
}

void Month::output_char(std::ostream& os)
{
	char initial1, initial2, initial3;
	convert_to_alphabetic(initial1, initial2, initial3);

	os << initial1 << initial2 << initial3;
}

void Month::convert_to_alphabetic(char& i1, char& i2,
	char& i3)
{
	switch (month)
	{
	case 1:
		i1 = 'J';
		i2 = 'a';
		i3 = 'n';
		break;
	case 2:
		i1 = 'F';
		i2 = 'e';
		i3 = 'b';
		break;
	case 3:
		i1 = 'M';
		i2 = 'a';
		i3 = 'r';
		break;
	case 4:
		i1 = 'A';
		i2 = 'p';
		i3 = 'r';
		break;
	case 5:
		i1 = 'M';
		i2 = 'a';
		i3 = 'y';
		break;
	case 6:
		i1 = 'J';
		i2 = 'u';
		i3 = 'n';
		break;
	case 7:
		i1 = 'J';
		i2 = 'u';
		i3 = 'l';
		break;
	case 8:
		i1 = 'A';
		i2 = 'u';
		i3 = 'g';
		break;
	case 9:
		i1 = 'S';
		i2 = 'e';
		i3 = 'p';
		break;
	case 10:
		i1 = 'O';
		i2 = 'c';
		i3 = 't';
		break;
	case 11:
		i1 = 'N';
		i2 = 'o';
		i3 = 'v';
		break;
	case 12:
		i1 = 'D';
		i2 = 'e';
		i3 = 'c';
		break;

	default:
		std::cout << "Month value not recognized, defaulting to Jan\n"
			<< "This should never happen.\n";
		i1 = 'J';
		i2 = 'a';
		i3 = 'n';
	}
}

Month Month::next_month()
{
	Month result;
	int next = month + 1;

	if (next > 12)
		next = 1;
	
	result.month = next;	
	//	Notice: direct access to a private variable if here allowed,
	//	even though the variable does not belong to the calling object.
	//	This is because the access is happening within a method of the
	//	same class?
	
	return result;
}

