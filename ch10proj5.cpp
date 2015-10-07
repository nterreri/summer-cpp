// ch10proj5.cpp : Defines the entry point for the console application.
/*Define a class for a type called CounterType. An object of this type is used
to count things, so it records a count that is a nonnegative whole number.
Include a default constructor that sets the counter to zero and a constructor
with one argument that sets the counter to the value specified by its
argument. Include member functions to increase the count by one and to
decrease the count by one. Be sure that no member function allows the
value of the counter to become negative. Also, include a member function
that returns the current count value and one that outputs the count to a
stream. The member function for doing output will have one formal
parameter of type ostream for the output stream that receives the output.
Embed your class definition in a test program.*/

#include "stdafx.h"
#include <iostream>
#include <fstream>

class CounterType
{
public:
	//	Constructors:
	CounterType(int par);
	CounterType();

	//	Modifiers:
	void addone();
	void subtractone();

	//	Accessor:
	unsigned int get_count();

	//	Output:
	void output_count(std::ostream& os = std::cout);

private:
	unsigned int count;
};


int main()
{
	//	Testing constructors:
	CounterType counter1;
	CounterType counter2(5);

	//	Testing modifiers:
	counter1.subtractone();
	counter1.addone();
	counter2.subtractone();

	//	Testing accessor:
	std::cout << "The count member of the first counter stores value: "
		<< counter1.get_count() << std::endl;
	std::cout << "The count member of the second counter stores value: "
		<< counter2.get_count() << std::endl;

	//	Testing output:
	counter1.output_count();

	std::ofstream os;
	os.open("output.txt");
	if (os.fail())
		exit(1);

	counter2.output_count(os);

	os.close();

	return 0;
}

CounterType::CounterType()
{
	count = 0;	
	// compiler does not assign 0 to member count if the body
	//	of the default constructor is left empty
}

CounterType::CounterType(int par)
{
	if (par < 0)
	{
		std::cout << "A CounterType obect must have non-negative count member\n"
			<< "variable.\n";
		exit(1);
	}

	count = static_cast<unsigned>(par);
}

void CounterType::addone()
{
	++count;
}

void CounterType::subtractone()
{
	//count has to be cast to int because it is unsigned, therfore subtracting
	//one to 0 would have the result of returning the max unsigned int value,
	//not to return -1:

	if ((static_cast<int>(count) - 1) < 0)
		;// Do nothing, here some error message may be appropriate
	else
		--count;
}

unsigned int CounterType::get_count()
{
	return count;
}

void CounterType::output_count(std::ostream& os)
{
	using namespace std;
	os << "Count value: " << count << endl;
}
