// ch11proj3.cpp : Defines the entry point for the console application.
/*In Chapter 8 we discussed vectors, which are like arrays that can grow in
size. Suppose that vectors were not defined in C++. Define a class called
VectorDouble that is like a class for a vector with base type double. Your
class VectorDouble will have a private member variable for a dynamic
array of doubles. It will also have two member variables of type int; one
called max_count for the size of the dynamic array of doubles, and one
called count for the number of array positions currently holding values.
(max_count is the same as the capacity of a vector; count is the same as the
size of a vector.)
If you attempt to add an element (a value of type double) to the vector
object of the class VectorDouble and there is no more room, then a new
dynamic array with twice the capacity of the old dynamic array is created and
the values of the old dynamic array are copied to the new dynamic array.
Your class should have all of the following:
- Three constructors: a default constructor that creates a dynamic array
for 50 elements, a constructor with one int argument for the number
of elements in the initial dynamic array, and a copy constructor.
- A destructor.
- A suitable overloading of the assignment operator =.
- A suitable overloading of the equality operator ==. To be equal, the values
of count and the count array elements must be equal, but the values
of max_count need not be equal.
- Member functions push_back, capacity, size, reserve, and resize
that behave the same as the member functions of the same names for
vectors.
- Two member functions to give your class the same utility as the square
brackets: value_at(i), which returns the value of the ith element in
the dynamic array; and change_value_at(d, i), which changes the
double value at the ith element of the dynamic array to d. Enforce suitable
restrictions on the arguments to value_at and change_value_at.
(Your class will not work with the square brackets. It can be made to
work with square brackets, but we have not covered the material
which tells you how to do that.)*/

#include "stdafx.h"
#include <iostream>

const int DEFAULTCAP = 50;
const int ARRAYSPACEINCR = 2;

class VectorDouble
{
public:
	//	Constructors:
	VectorDouble(const VectorDouble& vector_to_copy);
	VectorDouble(int size);
	VectorDouble();

	//	Destructor:
	~VectorDouble();

	//	Operator overloads:
	VectorDouble operator =(const VectorDouble& vector_to_assign);

	friend bool operator ==(const VectorDouble& v1,
		const VectorDouble& v2);

	//	Modifiers:
	void push_back(double value);
	//	Added value to the end of the vector (vector.dynamic_array, rather)

	void change_value_pos(double value, int index);

	void reserve(int additional_space);
	//	Reserved additional_space more space for the vector. Can only
	//	increase the vector size

	void resize(int new_capacity);
	//	Modifies the capacity of the vector to an arbitrary size
	//	larger or smaller

	//	Accessors:
	double pos(int index) const;
	//	Returns the value at index "index" of the array variable

	int capacity() const;
	//	Returns the current maximum number of elements the
	//	vector can hold

	int size() const;
	//	Returns the current number of positions that have
	//	an element assigned to them

private:
	void changesize(int new_max);
	//	Makes a copy of the vector then reinitializes the
	//	vector array to new_max and copies back into it the 
	//	original content from the copy, then destroys the copy

	double* dynamic_array;
	int max_count;
	int count;
};

void destructor_test();

void pushback_test(VectorDouble& vector);

//	Driver:
int main()
{
	using namespace std;

	//	Testing constructors:
	cout << "Constructing v0 with default constructor...\n";
	cout << "Constructing v1 with at least room for 10 values...\n";
	cout << "Constructing v2 by assigning v1 as constructor argument...\n";
	VectorDouble v0;
	VectorDouble v1(10);
	VectorDouble v2(v1);

	//	Testing destructor
	destructor_test();

	//	Testing assignment operator overload:
	cout << "Constructing v3 and assigning v1 to it...\n";
	VectorDouble v3;
	v3 = v1;

	//	Testing == operator overload:
	cout << "Are v2 and v3 the same?\n"
		<< (v2 == v3) << endl;

	//	Testing modifier pushback 1:
	cout << "Adding 50 values to v0...\n";
	pushback_test(v0);

	//	Testing position accessor pos:
	cout << "v0 contains:\n";
	for (int i = 0; i < DEFAULTCAP; i++)
		cout << v0.pos(i) << ' ';
	cout << endl;

	cout << "Attempting to access a position out of current range:\n";
	cout << v0.pos(DEFAULTCAP + 5) << endl;

	//	Testing modifier chenge_value_pos:
	cout << "Manually editing value " << DEFAULTCAP / 2 << endl;
	v0.change_value_pos(9.9999, DEFAULTCAP / 2);

	cout << "Attempting to manually change value out of range...\n";
	v0.change_value_pos(8.8888, DEFAULTCAP + 5);

	cout << "v0 now contains:\n";
	for (int i = 0; i < DEFAULTCAP; i++)
		cout << v0.pos(i) << ' ';
	cout << endl;

	//	Testing modifier pushback 2, going over max_count;
	//	also testing accessors capacity and size:

	cout << endl;
	cout << "v1 can hold: " << v1.capacity() << endl
		<< "and v1 is holding: " << v1.size() << endl;
	pushback_test(v1);

	cout << "After pushback_test, v1 can hold " << v1.capacity() << endl;
	cout << "v1 contains " << v1.size() << " elements:\n";
	for (int i = 0; i < DEFAULTCAP; i++)
		cout << v1.pos(i) << ' ';
	cout << endl;

	//	Testing resize:
	cout << "Putting " << DEFAULTCAP << " values in v0 and then resizing it to 10...\n";
	pushback_test(v0);
	v0.resize(10);

	cout << endl;
	cout << "Now v0 contains:\n";
	for (int i = 0; i < v0.size(); i++)
		cout << v0.pos(i) << " ";
	cout << endl;

	v0.resize(20);

	cout << "And now v0 can hold up to " << v0.capacity() << " double values.\n";

	//	Testing reserve 1; doesn't work when the space to be reserved is less
	//	than the space currently occupied:

	cout << "Attempting to reserve only 5 positions for v0:\n";
	v0.reserve(5);
	cout << "v0 can still hold up to " << v0.capacity() << " double values.\n";

	cout << "Attempting to reserve more than 10 positions for v0:\n";
	v0.reserve(40);
	cout << "v0 can now hold up to " << v0.capacity() << " double values.\n";

	return 0;
}

void destructor_test()
{
	VectorDouble v(DEFAULTCAP);
	//	the space occupied by v should be released once it goes out of scope
}

void pushback_test(VectorDouble& vector)
{
	for (int i = 0; i < DEFAULTCAP; i++)
		vector.push_back(i);
}

//	Constructors and destructor definitions:
VectorDouble::VectorDouble(const VectorDouble& to_copy) :
max_count(to_copy.max_count), count(to_copy.count)
{
	dynamic_array = new double[max_count];

	for (int i = 0; i < count; i++)
		dynamic_array[i] = to_copy.dynamic_array[i];
}

VectorDouble::VectorDouble(int size) : max_count(static_cast<int>
	(size*ARRAYSPACEINCR))
{
	count = 0;
	dynamic_array = new double[max_count];
}

VectorDouble::VectorDouble()
{
	max_count = DEFAULTCAP;
	count = 0;
	dynamic_array = new double[max_count];
}

VectorDouble::~VectorDouble()
{
	delete[] dynamic_array;
}

//	Operators overload definitions:
VectorDouble VectorDouble::operator =(const VectorDouble& to_assign)
{
	max_count = to_assign.max_count;
	count = to_assign.count;

	dynamic_array = new double[max_count];

	for (int i = 0; i < count; i++)
		dynamic_array[i] = to_assign.dynamic_array[i];

	return *this;
}

bool operator ==(const VectorDouble& v1, const VectorDouble& v2)
{
	if (v1.count == v2.count)
	{
		for (int i = 0; i < v1.count; i++)
		{
			if (v1.dynamic_array[i] != v2.dynamic_array[i])
				return false;
		}

		//	return true if no two values at the same position are different
		return true;
	}
	else
		return false;
}

//	Modifier definitions:
void VectorDouble::push_back(double value)
{
	++count;//	count is increased by one

	if (count > max_count)
	{
		--count;//recall that count has been increased, back up to the previous
		//size to allow the next private call to function properly

		changesize(static_cast<int>(max_count*ARRAYSPACEINCR));

		++count;//restore the new count size before pushing the next value
	}

	dynamic_array[count - 1] = value;
}

void VectorDouble::change_value_pos(double value, int index)
{
	if (index >= count)
	{
		std::cout << "Error: index out of range in change_value_pos(double, int)\n"
			<< "call, no values have been changed.\n";
	}
	else
	{
		dynamic_array[index] = value;
	}

}

void VectorDouble::resize(int new_capacity)
{

	if (new_capacity > max_count)
	{
		//make a copy, increase vector size to new capacity, then copy its
		//original content over

		changesize(new_capacity);
	}
	else if (new_capacity < max_count)
	{
		//make a copy, resize vector and then copy the content only up to
		//its new size

		count = new_capacity;

		changesize(new_capacity);
	}
	/*else if (new_capacity == max_count)
		Do nothing: the vector is already the right size;*/
}

void VectorDouble::reserve(int new_max)
{
	if (new_max <= count)
		std::cout << "Reserve size must be stricly larger than current size\n"
		<< "(the value of .size())\n";
	else
	{
		//make a copy, increase vector size to new capacity, then copy its
		//original content over

		changesize(new_max);
	}

}

//	Private method that does the heavy work of manipulating vector size
void VectorDouble::changesize(int new_max)
{
	//	Make a copy of the array:
	double* copy = new double[max_count];

	for (int i = 0; i < count; i++)
		copy[i] = dynamic_array[i];

	//	Reassign the array:
	delete[] dynamic_array;
	dynamic_array = new double[new_max];
	max_count = new_max;

	//	Copy the content of the previous array into the new, larger array:
	for (int i = 0; i < count; i++)
		dynamic_array[i] = copy[i];

	delete[] copy;
}



//	Accessor definitions:
//	this is what is called value_at(index) in the project description
double VectorDouble::pos(int index) const
{
	if (index >= count)
	{
		std::cout << "Warning: pos(index) call with index out of range.\n"
			<< "Returning default:\n";
		return 0.0;
	}
	else
		return dynamic_array[index];
}

int VectorDouble::capacity() const
{
	return max_count;
}

int VectorDouble::size() const
{
	return count;
}

