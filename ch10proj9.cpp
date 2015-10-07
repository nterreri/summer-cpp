// ch10proj9.cpp : Defines the entry point for the console application.
//	Program to simulate a portable counter

#include "stdafx.h"
#include <iostream>

class Counter
{
public:
	//	Constructors:
	Counter(int par);
	Counter();

	//	Accessor:
	int get_count();
	int get_limit();

	//	Modifiers:
	void reset();
	void incr1();
	void incr10();
	void incr100();
	void incr1000();

	//	Flag:
	bool overflow();

private:
	int limit;
	int count = 0;
};

void read_command(char ans[2], std::istream& is = std::cin);
//	Reads 2 char values in is, one alphabetic character and one digit

void execute_command(Counter& c, char answer[2]);
//	Modifies c according to the command stored in answer

void output(Counter c, std::ostream& os = std::cout);
//	Outputs the value of the counter (or its limit, if overflowing)

int main()
{
	Counter redclicker(9999);
	char ans[2];

	//	Program quits only upon command in the input phase
	while (true)
	{
		read_command(ans);

		execute_command(redclicker, ans);

		output(redclicker);
	}

	return 0;
}

//	This implementation pretty much assumes that is = cin
void read_command(char ans[2], std::istream& is)
{
	using namespace std;

	char line[50];
	char alpha;
	char digit;

	//	Input is made to accept an istream argument, but clearly this implementation
	//	is designed with the default argument (cin) in mind
	bool alpha_found = false;
	bool digit_found = false;

	do
	{
		cout << "Enter \'a\' followed by a digit (1-9) to enter cents,\n"
			<< "\'s\' followed by a digit (1-9) to enter dimes,\n"
			<< "\'d\' followed by a digit (1-9) to enter dollars,\n"
			<< "\'f\' followed by a digit (1-9) to enter tens of dollars,\n"
			<< "\'o\' to report overflow, or \'r\' to reset the counter.\n"
			<< "Enter \'q\' to quit the program.\n";

		is.getline(line, 50);

		for (int i = 0; i < 50 && line[i] != '\0'; i++)
		{
			if (isalpha(line[i]))
			{
				alpha = line[i];
				alpha_found = true;

				if (line[i] == 'q' || line[i] == 'o' || line[i] == 'r')
				{
					ans[1] = 0;
					digit_found = true;
					break;
				}
			}

			if (isdigit(line[i]))
			{
				digit = line[i];
				digit_found = true;
			}
		}
	} while (!alpha_found || !digit_found);
	
	//	The alphabetic character and the digit are stored in a 2-place array,
	//	the starting address of which is returned to caller
	ans[0] = alpha;
	ans[1] = digit;

}

void execute_command(Counter& c, char answer[2])
{
	int number_of_times = answer[1] - '0';

	switch (answer[0])
	{
	case 'a':
		for (int i = 0; i < number_of_times; i++)
			c.incr1();
		break;
	case 's':
		for (int i = 0; i < number_of_times; i++)
			c.incr10();
		break;
	case 'd':
		for (int i = 0; i < number_of_times; i++)
			c.incr100();
		break;
	case 'f':
		for (int i = 0; i < number_of_times; i++)
			c.incr1000();
		break;
	case 'o':
		if (c.overflow())
			std::cout << "Overflow!\n";
		else
			std::cout << "Not in overflow\n";
		break;
	case 'r':
		c.reset();
		break;
	case 'q':
		exit(0);
		break;
	default:
		std::cout << "Command not recognized.\n";
	}
}

void output(Counter c, std::ostream& os)
{
	using namespace std;

	int result_to_display;
	if (c.overflow())
	{
		os << "Warning: overflow. Resetting the counter is strongly advised.\n";
		result_to_display = c.get_limit();
	}
	else
		result_to_display = c.get_count();
	os << "Count value: ";
	if ((result_to_display / 100) < 10)
		os << '0';
	os << result_to_display / 100 << '.';
	if ((result_to_display % 100) < 10)
		os << '0';
	os << result_to_display % 100 << endl;

}

//	Driver:
int driver()
{
	//	Testing constructors:
	Counter c1;
	Counter c2(99);

	//	Testing modifiers and flag:
	c1.incr1();
	c1.incr10();
	c1.incr100();
	c1.incr1000();

	c2.incr100();

	std::cout << "Is c1 in overflow?\n";
	if (c1.overflow())
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	std::cout << "Is c2 in overflow?\n";
	if (c2.overflow())
		std::cout << "Yes\n";
	else
		std::cout << "No\n";

	char symbol;
	std::cout << "Enter a symbol to reset c2:\n";
	std::cin.get(symbol);

	c2.reset();

	return 0;
}

Counter::Counter(int par)
{
	if (par < 1)
	{
		std::cout << "Parameter in Counter constructor must be higher than 1\n"
			<< "Program will now quit.\n";
		exit(1);
	}

	limit = par;
}

Counter::Counter()
{
	limit = 9999;
}

int Counter::get_count()
{
	return count;
}

int Counter::get_limit()
{
	return limit;
}

void Counter::reset()
{
	count = 0;
}

void Counter::incr1()
{
	++count;
}

void Counter::incr10()
{
	count += 10;
}

void Counter::incr100()
{
	count += 100;
}

void Counter::incr1000()
{
	count += 1000;
}

bool Counter::overflow()
{
	if (count > limit)
		return true;
	else
		return false;
}

