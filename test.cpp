// ConsoleApplication1.cpp : Defines the entry point for the console application.
/*Using dynamic arrays, implement a polynomial class with polynomial
addition, subtraction, and multiplication.*/

/*task 1: Provide a default constructor, a copy constructor, and a parameterized
constructor that enables an arbitrary polynomial to be constructed. Also
supply an overloaded operator = and a destructor.

task2: Provide these operations:
? polynomial + polynomial
? constant + polynomial
? polynomial + constant
? polynomial - polynomial
? constant - polynomial
? polynomial - constant
? polynomial * polynomial
? constant * polynomial
? polynomial * constant

task3:
Supply functions to assign and extract coefficients, indexed by exponent.
Supply a function to evaluate the polynomial at a value of type double.
You should decide whether to implement these functions as members,
friends, or standalone functions.*/

#include "stdafx.h"
#include <iostream>

const int LIMIT_SIZE = 100;
const int DEFAULT_SIZE = 10;

class Polynomial
{
public:
	Polynomial();
	Polynomial(const double* coefficients_in_order,
		const int* exponents_in_order);

private:
	bool overflow();
	void increase_maxsize();

	double max_size;
	double used_size;
	double *value;
};

void copy_array(double*& target, const double* source, const int source_size);

//driver:
int main()
{
	using namespace std;

	//test constructors:
	Polynomial poly1;

	//test copy_array

	double a1[10], *a2 = new double[1];

	for (int i = 0; i < 10; i++)
		a1[i] = i;

	copy_array(a2, a1, 10);

	for (int i = 0; i < 10; i++)
		cout << a2[i] << " ";

	return 0;
}

//external function:
void copy_array(double*& target, const double *source, const int source_size)
{
	delete[] target;

	target = new double[source_size];

	for (int i = 0; i < source_size; i++)
		target[i] = source[i];
}

//public methods:
Polynomial::Polynomial() : max_size(10), used_size(0), value = new double[max_size]
{
	//body intentionally empty
}

//private methods:
bool Polynomial::overflow()
{
	if (used_size > max_size)
		return true;
	else
		return false;
}
