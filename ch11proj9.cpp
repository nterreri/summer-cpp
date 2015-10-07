// ch11proj9.cpp : Defines the entry point for the console application.
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
	Polynomial(int largest_exponent);
	Polynomial(double* a, int array_size);
	Polynomial(const Polynomial& argument);
	~Polynomial();

	//Assignment:
	void operator =(const Polynomial& right_side);

	//Other operators:
	friend Polynomial operator+(const Polynomial& left, const double right);
	friend Polynomial operator+(const double left, const Polynomial& right);
	friend Polynomial operator+(const Polynomial& left,
		const Polynomial& right);

	friend Polynomial operator-(const Polynomial& left, const double right);
	friend Polynomial operator-(const double left, const Polynomial& right);
	friend Polynomial operator-(const Polynomial& left,
		const Polynomial& right);

	friend Polynomial operator* (const Polynomial& left, const double right);
	friend Polynomial operator* (const double left, const Polynomial& right);
	friend Polynomial operator*(const Polynomial& left,
		const Polynomial& right);

	//Accessor:
	double at(int index) const;

	//Modifier:
	void put_at(double new_value, int index);

	//External function to evaluate the polynomial to a double value:
	friend double evaluate(const Polynomial& poly, double value_of_variable);

	//for testing private methods:
	friend void private_test(Polynomial& poly);

private:
	//methods unused:
	/*bool overflow() const;
	void increase_maxsize();
	void increase_maxsize(int new_size);
	void change_size(int new_size);*/

	int size;
	double *value;
};

void copy_array(double*& target, const double* source,
	const int elements);
/*copy_array copies up to elements double values from source in the order,
therefore elements must be less than the space reserved for both target
and source (or at most equal to the smaller of these two).*/

//-------------------------------------------------------------------
//driver:
int main()
{
	using namespace std;

// task 1 test

	//test constructors:
	Polynomial poly1;
	Polynomial poly2(25);

	double a[10] = { 6.23, 78, 0, 23, 89, 0, 1, 0, 99.999, 0.00005 };
	Polynomial poly3(a, 10);
	Polynomial poly4(poly3);

	//testing assignment:
	poly1 = poly3;

// end of task 1 test
// task 2 test

	//testing +:
	poly1 = poly1 + 3.77;

	poly1 = 3.77 + poly1;

	Polynomial suml(a, 10);
	double b[5] = { 3.77, 22, 100, 77, 11 };
	Polynomial sumr(b, 5);

	Polynomial sum = suml + sumr;

	//testing -:

	double c[6] = { 0, 1, 2, 3, 4, 5 };
	double d[5] = { 0, 1, 2, 3, 4 };
	Polynomial subtl(c, 6);
	Polynomial subtr(d, 5);
	Polynomial subt = subtl - subtr;

	//testing *:
	double ptlv[4] = { 4,0,2,1 }, ptrv[4] = { 1,1,0,2 };

	Polynomial polytimesl(ptlv, 4), polytimesr(ptrv, 4);
	Polynomial polytimes = polytimesl * polytimesr;

// end of task 2 test
// task 3 test

	//testing accessor:

	for (int i = 0; i < 7; i++)
		cout << polytimes.at(i) << endl;
	cout << polytimes.at(-27) << endl
		<< polytimes.at(150) << endl;

	//testing modifier:

	polytimes.put_at(13.0, 7);
	cout << polytimes.at(7) << endl;

	//testing evaluate:
	double arrayev[4] = { 1, 1, 3, 1 };
	Polynomial polyev(arrayev, 4);

	cout << evaluate(polyev, 2.0) << endl;

// end of task 3 test

	//test copy_array

	double* a1 = new double[10], *a2 = new double[10];

	for (int i = 0; i < 10; i++)
		a1[i] = i;

	copy_array(a2, a1, 10);
	delete[] a1;

	for (int i = 0; i < 10; i++)
		cout << a2[i] << " ";

	return 0;
}

//-------------------------------------------------------------------
//external functions:
Polynomial operator+(const Polynomial& left, const double right)
{
	Polynomial result;

	result = left;

	result.value[0] += right;

	return result;
}

Polynomial operator+(const double left, const Polynomial& right)
{
	Polynomial result;

	result = right;

	result.value[0] += left;

	return result;
}

Polynomial operator+(const Polynomial& left, const Polynomial& right)
{
	Polynomial result;

	result = left;

	for (int i = 0; i < right.size; i++)
		result.value[i] += right.value[i];

	return result;
}

Polynomial operator-(const Polynomial& left, const double right)
{
	Polynomial result;

	result = left;

	result.value[0] -= right;

	return result;
}

Polynomial operator-(const double left, const Polynomial& right)
{
	Polynomial result;

	result = right;

	result.value[0] -= left;

	return result;
}

Polynomial operator-(const Polynomial& left, const Polynomial& right)
{
	Polynomial result;

	result = left;

	for (int i = 0; i < right.size; i++)
		result.value[i] -= right.value[i];

	return result;
}

Polynomial operator*(const Polynomial& left, const double right)
{
	Polynomial result = left;

	for (int i = 0; i < result.size; i++)
		result.value[i] *= right;

	return result;
}

Polynomial operator*(const double left, const Polynomial& right)
{
	Polynomial result = right;

	for (int i = 0; i < result.size; i++)
		result.value[i] *= left;

	return result;
}

Polynomial operator*(const Polynomial& left, const Polynomial& right)
{
	Polynomial result(right.size + left.size -2);
	//-2 because size variables are + 1 the largest exponent in the polynomial,
	//and since we are summing two of them here, the result is +2 the largest exponent.
	//This makes the size of result an array with a last value in array necessarily 0.
	//A more elegant solution allocates just as much memory as is needed, and nothing more.
	//Hence the size of result is "artificially" reduced by 1 unit.

	for (int index = 0; index < result.size; index++)
		result.value[index] = 0;

	for (int i = 0; i < right.size; i++)
		for (int j = 0; j < left.size; j++)
			result.value[i + j] += right.value[i] * left.value[j];

	return result;
}

double evaluate(const Polynomial& poly, double value_of_variable)
{
	double result = 0;

	for (int i = 0; i < poly.size; i++)
		result += (pow(value_of_variable, i) * poly.value[i]);

	return result;
}

void copy_array(double*& target, const double *source, const int elements)
{
	//these next two lines make the function delete array target, which is not
	//what we want in this case:
	/*delete[] target;
	target = new double[source_size];*/

	for (int i = 0; i < elements; i++)
		target[i] = source[i];
}

//unused:
/*void private_test(Polynomial& poly)
{
	poly.increase_maxsize();
	poly.increase_maxsize(50);
	poly.increase_maxsize(LIMIT_SIZE + 1);
	poly.increase_maxsize(1);
	poly.change_size(1);
}*/

//-------------------------------------------------------------------
//public methods:
Polynomial::Polynomial() : size(0), value(new double[size])
{
	;//body intentionally empty
}

Polynomial::Polynomial(int largest_exponent) : size(largest_exponent + 1)
{
	if (size > LIMIT_SIZE)
		size = LIMIT_SIZE;

	value = new double[size];
}

Polynomial::Polynomial(double* a, int array_size)
{
	size = array_size;
	if (size > LIMIT_SIZE)
		size = LIMIT_SIZE;

	value = new double[size];

	copy_array(value, a, size);
}

Polynomial::Polynomial(const Polynomial& argument)
{
	size = argument.size;
	value = new double[size];

	copy_array(value, argument.value, size);
}

Polynomial::~Polynomial()
{
	delete[] value;
}

//Accessor:
double Polynomial::at(int index) const
{
	if (index >= size)
		return value[size - 1];
	else if (index < 0)
		return value[0];
	else
		return value[index];
}

//Modifier:
void Polynomial::put_at(double new_value, int index)
{
	if (index >= size)
		index = size;
	else if (index < 0)
		index = 0;

	value[index] = new_value;
}

//Assignment:
void Polynomial::operator=(const Polynomial& right_side)
{
	size = right_side.size;
	value = new double[size];

	copy_array(value, right_side.value, size);
}

//useless:
/*
//private methods:
bool Polynomial::overflow() const
{
	if (used_size > size)
		return true;
	else
		return false;
}

void Polynomial::increase_maxsize()
{
	int old_size = size;
	double* buffer = new double[old_size];

	copy_array(buffer, value, old_size);

	size = static_cast<int>(size * 1.5);
	if (size > LIMIT_SIZE)
		size = LIMIT_SIZE;

	value = new double[size];
	copy_array(value, buffer, old_size);

	delete[] buffer;
}

void Polynomial::increase_maxsize(int new_size)
{
	if (size >= new_size)
		;


	else
	{
		int old_size = size;
		double* buffer = new double[old_size];
		copy_array(buffer, value, old_size);

		//the next line differs from the argumentless overload
		size = new_size;
		if (size > LIMIT_SIZE)
			size = LIMIT_SIZE;

		//the next line differs from the argumentless overload
		value = new double[new_size];
		copy_array(value, buffer, old_size);

		delete[] buffer;
	}
}

void Polynomial::change_size(int new_size)
{
	int old_size = size;
	double* buffer = new double[old_size];
	copy_array(buffer, value, old_size);

	size = new_size;
	if (size > LIMIT_SIZE)
		size = LIMIT_SIZE;

	/*the next two lines differ from both versions of increase_maxsize,
	only up to new_size (which is the size of the value array now) is
	copied into it if it is LESS than it was before*/
/*
	if (new_size < old_size)
	{
		value = new double[new_size];
		copy_array(value, buffer, new_size);
	}
	else
	{
		value = new double[new_size];
		copy_array(value, buffer, old_size);
	}

	delete[] buffer;

	// a better optimized version of these two functions checks to see if
	//the new_size is the same as the old one, in which case, nothing happens
}*/

