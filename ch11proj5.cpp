// ch11proj5.cpp : Defines the entry point for the console application.
/*Define a class for rational numbers. A rational number is a number that
can be represented as the quotient of two integers. For example, 1/2, 3/4,
64/2, and so forth are all rational numbers. (By 1/2, etc., we mean the
everyday meaning of the fraction, not the integer division this expression
would produce in a C++ program.) Represent rational numbers as two values
of type int, one for the numerator and one for the denominator. Call
the class Rational.
Include a constructor with two arguments that can be used to set the
member variables of an object to any legitimate values. Also include a
constructor that has only a single parameter of type int; call this single
parameter whole_number and define the constructor so that the object will
be initialized to the rational number whole_number/1. Also include a
default constructor that initializes an object to 0 (that is, to 0/1).
Overload the input and output operators >> and <<. Numbers are to be
input and output in the form 1/2, 15/32, 300/401, and so forth. Note
that the numerator, the denominator, or both may contain a minus sign,
so - 1/2, 15/- 32, and - 300/- 401 are also possible inputs.

--->>Overload all of
the following operators so that they correctly apply to the type Rational:
==, <, <=, >, >=, +, - , *, and /. Also write a test program to test your class.
Hints: Two rational numbers a/b and c/d are equal if a*d equals c*b. If b
and d are positive rational numbers, a/b is less than c/d provided a*d is less
than c*b. You should include a function to normalize the values stored so
that, after normalization, the denominator is positive and the numerator
and denominator are as small as possible. For example, after
normalization 4/- 8 would be represented the same as - 1/2. You should
also write a test program to test your class.*/

#include "stdafx.h"
#include <iostream>

class Rational
{
public:
	//	Constructors:
	Rational();
	Rational(int num, int denom);
	Rational(int whole_number);

	//	I/O overload:
	friend std::istream& operator >>(std::istream& is, Rational& r);
	friend std::ostream& operator <<(std::ostream& os, Rational& r);

	//	Operator overloadings:
	friend bool operator ==(Rational rat1, Rational rat2);

	friend bool operator <(Rational rat1, Rational rat2);

	friend bool operator <=(Rational rat1, Rational rat2);

	friend bool operator >(Rational rat1, Rational rat2);

	friend bool operator >=(Rational rat1, Rational rat2);

	friend Rational operator +(Rational rat1, Rational rat2);

	friend Rational operator +(Rational rat);

	friend Rational operator -(Rational rat1, Rational rat2);

	friend Rational operator -(Rational rat);

	friend Rational operator *(Rational rat1, Rational rat2);

	friend Rational operator /(Rational rat1, Rational rat2);

private:
	//	The two private functions are normalization functions.
	void minit();
	//	Reduced num and denom to minimum terms
	void format_negation();
	//	Rearranges negative num and denum values so that the negation
	//	sing is put on the num where appropriate, this helps with output
	//	formatting.

	int num;
	int denom;
};

int next_prime(int some_prime);
//	Returns the next prime number after some_prime, 
//	required by Rational::minit()

bool is_prime(int some_number);

void newline(std::istream& is = std::cin)
{
	char next;
is.get(next);
	while (next != '\n')
		is.get(next);
}


//	Driver program:
int main()
{
	using namespace std;

	//	Testing constructors:
	cout << "Constructing r0 with the default constructor...\n"
		<< "Constructing r1 with two numbers...\n"
		<< "Constructing r2 with a single number...\n"
		<< "Constructing r3 with a negative num...\n"
		<< "Constructing r4 with a negative denom...\n"
		<< "Constructing r5 with a negative num and denom...\n";
	Rational r0;
	Rational r1(20, 16);
	Rational r2(17);
	Rational r3(-17);
	Rational r4(17, -4);
	Rational r5(-17, -1);

	//	Testing I/O friends:
	cout << "Outputting r1:\n";
	cout << r1 << endl;

	cout << "Now, enter some input for r0:\n";
	//cin >> r0;

	//	Testing operators:
	
	bool loopcontrol = true;
	bool change_numbers = true;
	char ans, wer;
	while (loopcontrol)
	{
		if (change_numbers)
		{
			cout << "Enter two rational numbers:\n";
			cin >> r0 >> r1;
			newline();
		}
		cout << "Enter the operation you would like to perform:\n"
			<< "Options: ==, <, <=, >, >=, +, -, *, / or \'q\' to quit.\n";
		cin.get(ans);

		switch (ans)
		{
		case '=':
			cout << (r0 == r1) << endl;
			break;
		case '<':
			cin.get(wer);
			if (wer == '\n')
				cout << (r0 < r1) << endl;
			else if (wer == '=')
				cout << (r0 <= r1) << endl;
			else
				cout << "Input not understood.\n";
			break;
		case '>':
			cin.get(wer);
			if (wer == '\n')
				cout << (r0 > r1) << endl;
			else if (wer == '=')
				cout << (r0 >= r1) << endl;
			else
				cout << "Input not understood.\n";
			break;
		case '+':
			cout << (r0 + r1) << endl;
			break;
		case '-':
			cout << (r0 - r1) << endl;
			break;
		case '*':
			cout << (r0 * r1) << endl;
			break;
		case '/':
			cout << (r0 / r1) << endl;
			break;
		case 'q':
			loopcontrol = false;
			break;
		default:
			cout << "Input not understood.\n";
		}
		newline();

		cout << "Enter another pair of numbers? y/n:\n";
		cin >> ans;

		if (ans == 'y' || ans == 'Y')
			change_numbers = true;
		else
			change_numbers = false;

		newline();
	}
	
	

	return 0;
}

//	Constructors:
Rational::Rational() : num(0), denom(1)
{
	//	Intentionally empty
}

Rational::Rational(int n, int d) : num(n), denom(d)
{
	if (denom == 0)
	{
		std::cout << "Error: denum set to 0, terminating program...\n";
		exit(1);
	}
	
	//	If the rational is negative, the sign is always placed before the num.
	//	This helps with output formatting
	format_negation();

	minit();
}

Rational::Rational(int whole_number) : num(whole_number), denom(1)
{
	//	Intentionally empty
}

//	private methods:
void Rational::minit()
{
	int prime = 2;

	//	abs(num) because of the two num may be negative (see constructor
	//	definitions)
	while ((prime <= abs(num) || prime <= denom) &&
		prime < 10000)	//	Arbitrary stopping point
	{
		if ( num % prime == 0 &&
			denom % prime == 0)
		{
			num = num / prime;
			denom = denom / prime;
			continue;
		}

		prime = next_prime(prime);
	}
}

void Rational::format_negation()
{
	if (num < 0 && denom < 0)
	{
		num *= -1;
		denom *= -1;
	}
	else if (num > 0 && denom < 0)
	{
		num *= -1;
		denom *= -1;
	}
	/*else if(num == 0 || (num < 0 && denom > 0) ||
	(num < 0 && denom < 0))
	/*do nothing*/
}

//	External functions:

std::istream& operator >>(std::istream& is, Rational& rat)
{
	char next;

	is >> rat.num;
	is.get(next);
	is >> rat.denom;

	//	Input control:
	if (next != '/')
		std::cout << "Warning: rational input format incorrect.\n";
	
	if (rat.denom == 0)
	{
		std::cout << "Error: rational object denumerator set to 0,\n"
			<< "setting to 1 instead.\n";
		rat.denom = 1;
	}

	rat.format_negation();

	return is;
}

std::ostream& operator <<(std::ostream& os, Rational& rat)
{
	os << rat.num << '/' << rat.denom;
	return os;
}

int next_prime(int par)
{
	if (par < 2)
		return 2;

	if (par == 2)
		return 3;

	if (is_prime(par))
		++par;

	while (!is_prime(par))
	{
		if (par % 2 == 0)
			++par;
		else
			par += 2;
	}

	return par;
}

bool is_prime(int par)
{
	if (par == 2)
		return true;

	if (par % 2 == 0)
		return false;
	
	for (int i = 3; i < par; i++)
		if (par % i == 0)
			return false;

	return true;
}

//	Operator overloadings:
//	logical:
bool operator ==(Rational rat1, Rational rat2)
{
	return (rat1.num*rat2.denom == rat2.num*rat1.denom);
}

bool operator <(Rational rat1, Rational rat2)
{
	if (rat1.num < 0 && rat2.num > 0)
		return true;
	else if (rat1.num > 0 && rat2.num < 0)
		return false;
	else/* if (rat1.num > 0 && rat2.num > 0 ||
		rat1.num < 0 && rat2.num < 0)*/
		return ((rat1.num * rat2.denom) < (rat2.num * rat1.denom));
}

bool operator <=(Rational rat1, Rational rat2)
{
	//	Same as ==:
	if (rat1.num*rat2.denom == rat2.num*rat1.denom)
		return true;

	if (rat1.num < 0 && rat2.num > 0)
		return true;
	else if (rat1.num > 0 && rat2.num < 0)
		return false;
	else/* if (rat1.num > 0 && rat2.num > 0 ||
		rat1.num < 0 && rat2.num < 0)*/
		return ((rat1.num * rat2.denom) < (rat2.num * rat1.denom));
}

bool operator >(Rational rat1, Rational rat2)
{
	if (rat1.num > 0 && rat2.num < 0)
		return true;
	else if (rat1.num < 0 && rat2.num > 0)
		return false;
	else/* if (rat1.num > 0 && rat2.num > 0 ||
		rat1.num < 0 && rat2.num < 0)*/
		return ((rat1.num * rat2.denom) > (rat2.num * rat1.denom));
}

bool operator >=(Rational rat1, Rational rat2)
{
	//	Same as ==:
	if (rat1.num*rat2.denom == rat2.num*rat1.denom)
		return true;

	if (rat1.num > 0 && rat2.num < 0)
		return true;
	else if (rat1.num < 0 && rat2.num > 0)
		return false;
	else/* if (rat1.num > 0 && rat2.num > 0 ||
		rat1.num < 0 && rat2.num < 0)*/
		return ((rat1.num * rat2.denom) >(rat2.num * rat1.denom));
}

//	arithmetic:
Rational operator+(Rational rat)
{
	return rat;
}

Rational operator-(Rational rat)
{
	rat.num *= -1;
	return rat;
}

Rational operator +(Rational rat1, Rational rat2)
{
	Rational result;

	result.num = (rat1.num * rat2.denom + rat2.num * rat1.denom);
	result.denom = (rat1.denom * rat2.denom);

	result.minit();
	result.format_negation();

	return result;
}

Rational operator -(Rational rat1, Rational rat2)
{
	Rational result;

	result.num = (rat1.num * rat2.denom - rat2.num * rat1.denom);
	result.denom = (rat1.denom * rat2.denom);

	result.minit();
	result.format_negation();

	return result;
}

Rational operator *(Rational rat1, Rational rat2)
{
	Rational result;

	result.num = (rat1.num * rat2.num);
	result.denom = (rat1.denom * rat2.denom);

	result.minit();
	result.format_negation();

	return result;
}

Rational operator /(Rational rat1, Rational rat2)
{
	Rational result;

	result.num = (rat1.num * rat2.denom);
	result.denom = (rat1.denom * rat2.num);

	result.minit();
	result.format_negation();

	return result;
}
