// ch11proj1.cpp : Defines the entry point for the console application.
//	Expansion of "Money" class

#include "stdafx.h"
#include <iostream>

class Money
{
public:
	//	Operator overloads:
	friend Money operator +(const Money& amount1, const Money& amount2);

	friend Money operator -(const Money& amount1, const Money& amount2);

	friend Money operator -(const Money& amount);

	friend bool operator ==(const Money& amount1, const Money& amount2);

	friend bool operator <(const Money& m1, const Money& m2);

	friend bool operator <=(const Money& m1, const Money& m2);

	friend bool operator >(const Money& m1, const Money& m2);

	friend bool operator >=(const Money& m1, const Money& m2);

	//	Constructors:
	Money(long dollars, int cents);

	Money(long dollars);

	Money();

	//	Accessor:
	double get_value() const;

	//	I/O:
	friend std::istream& operator >>(std::istream& ins, Money& amount);

	friend std::ostream& operator <<(std::ostream& outs, const Money& amount);

	//	Other member function:
	Money percent(int percent_figure) const;
	//Returns a percentage of the money amount in the
	//calling object. For example, if percent_figure is 10,
	//then the value returned is 10% of the amount of
	//money represented by the calling object.

private:
	long all_cents;
};

//	Driver for the new functions
int main()
{
	using namespace std;

	Money amount1 = 10, amount2 = 5;

	cout << "amount1 = " << amount1 << endl
		<< "amount2 = " << amount2 << endl;

	cout << "Is amount1 < amount2?\n";
	cout << (amount1 < amount2) << endl;
	cout << "Is amount2 <= amount2?\n";
	cout << (amount2 <= amount2) << endl;
	cout << "Is amount2 <= amount1?\n";
	cout << (amount2 <= amount1) << endl;
	cout << "Is amount1 > amount2?\n";
	cout << (amount1 > amount2) << endl;
	cout << "Is amount2 >= amount1?\n";
	cout << (amount2 >= amount1) << endl;

	Money amount3 = 100;
	Money percent_of_amount3 = amount3.percent(10);

	cout << "amount3 = " << amount3 << endl
		<< 10 << "% of amount 3 = " << percent_of_amount3 << endl;

	Money amount4(0, 1);
	Money percent_of_amount4 = amount4.percent(75);

	cout << "amount4 = " << amount4 << endl
		<< 75 << "% of amount4 = " << percent_of_amount4 << endl;

	Money purse(100, 10);
	Money percent_of_purse = purse.percent(10);

	cout << "purse = " << purse << endl
		<< 10 << "% of purse = " << percent_of_purse << endl;

	return 0;
}

bool operator <(const Money& m1, const Money& m2)
{
	return (m1.all_cents < m2.all_cents);
}

bool operator <=(const Money& m1, const Money& m2)
{
	return (m1.all_cents <= m2.all_cents);
}

bool operator >(const Money& m1, const Money& m2)
{
	return (m1.all_cents > m2.all_cents);
}

bool operator >=(const Money& m1, const Money& m2)
{
	return (m1.all_cents >= m2.all_cents);
}

std::ostream& operator <<(std::ostream& os, const Money& amount)
{
	long positive_cents, dollars, cents;
	positive_cents = labs(amount.all_cents);
	dollars = positive_cents / 100;
	cents = positive_cents % 100;

	if (amount.all_cents < 0)
		os << "-$" << dollars << '.';
	else
		os << "$" << dollars << '.';

	if (cents < 10)
		os << '0';
	os << cents;

	return os;
}

Money Money::percent(int figure) const
{
	Money new_object;
	new_object.all_cents = ((figure*all_cents) / 100);

	return new_object;
}

Money::Money(long dollars, int cents)
{
	all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100)
{
	//	Nothing
}

Money::Money() : all_cents(0)
{
	//	Nothing
}
