// ch11proj11.cpp : Defines the entry point for the console application.
/*Outline:
Define a class called List that can hold a list of values of type double.
Model your class definition after the class List given in Display
11.10, but your class List will make no reference to temperatures
when it outputs values. The values may represent any sort of data items as
long as they are of type double.
Design a program to thoroughly test your definition for the class List.*/

/*task 1:
Include the additional features specified
in Self-Test Exercises 21 and 22. Change the member function names so
that they do not refer to temperature.*/

/*task 2:
Add a member function called get_last that takes no arguments and
returns the last item on the list. The member function get_last does not
change the list. The member function get_last should not be called if the
list is empty. Add another member function called delete_last that
deletes the last element on the list. The member function delete_last is a
void function. Note that when the last element is deleted, the member
variable size must be adjusted. If delete_last is called with an empty list
as the calling object, the function call has no effect.*/


#include "stdafx.h"
#include <iostream>

const int MAX_LIST_SIZE = 50;

//----------------------------------------------------------------------------------------------

//Provided material:
class List
{
public:
	List();
	//Initializes the object to an empty list.

	//Accessors:
	int get_size() const;
	double at(int pos) const;
	double get_last() const;

	//Modifiers:
	void add_value(double value);
	//Precondition: The list is not full.
	//Postcondition: The temperature has been added to the list.
	void delete_last();

	//Public boolean check:
	bool full() const;
	//Returns true if the list is full; false otherwise.

	//Output:
	friend std::ostream& operator <<(std::ostream& outs,
		const List& the_object);
	//Overloads the << operator so it can be used to output values of
	//type List. Temperatures are output one per line.
	//Precondition: If outs is a file output stream, then outs
	//has already been connected to a file.
private:
	double list[MAX_LIST_SIZE]; //of values
	int size; //number of array positions filled
};

//----------------------------------------------------------------------------------------------

//Driver:
int main()
{
	using namespace std;
	List l;

	//Testing accessors and modifiers:

	//get_last() with an empty list, then with a full list:
	cout << l.get_last() << endl;

	for (int i = 0; i < MAX_LIST_SIZE; i++)
		l.add_value(i);

	cout << l.get_size() << endl;

	//, then after delete_last():
	l.delete_last();
	cout << l.get_size() << endl;

	int posread;
	cout << "Enter position to check: ";
	cin >> posread;

	cout << "Value at l.at(posread) = " << l.at(posread) << endl;

	return 0;
}

//----------------------------------------------------------------------------------------------

//This is the implementation for the class List.
List::List() : size(0)
{
	//Body intentionally empty.
}
void List::add_value(double value)
{//Uses iostream and cstdlib:
	if (full())
	{
		std::cout << "Error: adding to a full list.\n";
		exit(1);
	}
	else
	{
		list[size] = value;
		size = size + 1;
	}
}
bool List::full() const
{
	return (size == MAX_LIST_SIZE);
}
//Uses iostream:
std::ostream& operator <<(std::ostream& outs, const List& the_object)
{
	for (int i = 0; i < the_object.size; i++)
		outs << the_object.list[i] << " F\n";
	return outs;
}
//----------------------------------------------------------------------------------------------

//Project 11 contribution:

//Accessors:
int List::get_size() const
{
	return size;
}
double List::at(int pos) const
{
	if (pos < 0)
	{
		std::cout << "Error: reading empty or out of range list position.\n"
			<< "Defaulting to 0 or occupied size.\n";
		pos = 0;
	}
	else if (pos > size)
	{
		std::cout << "Error: reading empty or out of range list position.\n"
			<< "Defaulting to 0 or occupied size.\n";
		pos = size - 1;
		// -1: number of array positions filled is 1 when only index 0
		//holds a value.
	}

	return list[pos];
}
double List::get_last() const
{
	return list[size - 1];
}

//Modifier:
void List::delete_last()
{
	if (size != 0)
	{
		list[size - 1] = NULL;
		size = size - 1;
	}
}
