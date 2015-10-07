// ch10proj11.cpp : Defines the entry point for the console application.
//	Program to implement and test odometer class

#include "stdafx.h"
#include <iostream>

class Odometer
{
public:
	//	Constructors:
	Odometer();

	//	Modifiers:
	void set_efficiency(double new_efficiency);
	void add_miles(double distance);
	void reset_miles();

	//	Accessor:
	double get_gallons_consumed();

private:
	double miles;
	double efficiency;	//miles/gallon
};

int main()
{
	using namespace std;

	Odometer car;

	//	First test:
	car.set_efficiency(5.0);
	car.add_miles(500.0);

	cout << "At an efficiency of " << 5 << " miles per gallon, travelling for\n"
		<< 500 << " miles, a car consumes " << car.get_gallons_consumed() << endl
		<< "gallons in total.\n" << endl;

	car.reset_miles();

	//	Second test:
	car.set_efficiency(1.0);
	car.add_miles(1000.0);

	cout << "At an efficiency of " << 1 << " miles per gallon, travelling for\n"
		<< 1000 << " miles, a car consumes " << car.get_gallons_consumed() << endl
		<< "gallons in total.\n" << endl;

	car.reset_miles();

	//	Third test:
	car.set_efficiency(2.0);
	car.add_miles(10000.0);

	cout << "At an efficiency of " << 2 << " miles per gallon, travelling for\n"
		<< 10000 << " miles, a car consumes " << car.get_gallons_consumed() << endl
		<< "gallons in total.\n" << endl;

	car.reset_miles();

	//	Fourth test:
	car.set_efficiency(50.0);
	car.add_miles(20000.0);

	cout << "At an efficiency of " << 50 << " miles per gallon, travelling for\n"
		<< 20000 << " miles, a car consumes " << car.get_gallons_consumed() << endl
		<< "gallons in total.\n" << endl;

	car.reset_miles();

	return 0;
}

//	Driver:
int driver()
{
	//	Constructor:
	Odometer odo;

	//	Modifiers & accessor:
	odo.set_efficiency(15);
	odo.add_miles(30);

	std::cout << "The number of gallons consumed is: " << odo.get_gallons_consumed();
	std::cout << std::endl;

	odo.reset_miles();

	std::cout << "The number of gallons consumed NOW is: "
		<< odo.get_gallons_consumed() << std::endl;


	return 0;
}

Odometer::Odometer()
{
	miles = 0.0;
	efficiency = 0.0;
}

void Odometer::set_efficiency(double new_efficiency)
{
	if (new_efficiency < 0)
		new_efficiency = 0;
	efficiency = new_efficiency;
}

void Odometer::add_miles(double distance)
{
	if (distance < 0)
		distance = 0;
	miles += distance;
}

void Odometer::reset_miles()
{
	miles = 0;
}

double Odometer::get_gallons_consumed()
{
	return miles / efficiency;
}

