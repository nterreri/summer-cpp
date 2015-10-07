// ch11proj7.cpp : Defines the entry point for the console application.
/*Enhance the definition of the class StringVar given in Displays 11.11 and
11.12 by adding all of the following:
- Member function copy_piece, which returns a specified substring;
member function one_char, which returns a specified single character;
and member function set_char, which changes a specified character.
- An overloaded version of the == operator (note that only the string values
have to be equal; the values of max_length need not be the same).

Getting strange bad memory allocation runtime errors with this task:
- An overloaded version of + that performs concatenation of strings of
type StringVar.

->
- An overloaded version of the extraction operator >> that reads one
word (as opposed to input_line, which reads a whole line).
- If you did the section on overloading the assignment operator, then add it
as well.
- Also write a suitable test program and thoroughly test your class
definition.*/

//	This solution does not work in its current state: weird damaged heap
//	errors and breakpoints being triggered upon destructor call

#include "stdafx.h"
#include <iostream>

const int BASE_INPUT_ARRAY_SIZE = 1;

class StringVar
{
public:
	//	Constructors:
	StringVar(int size);
	//Initializes the object so it can accept string values up to size
	//in length. Sets the value of the object equal to the empty string.
	
	StringVar();
	//Initializes the object so it can accept string values of length 100
	//or less. Sets the value of the object equal to the empty string.

	StringVar(const char a[]);
	//Precondition: The array a contains characters terminated with '\0'.
	//Initializes the object os its value is the string stored in a and
	//so that it can later be set to string values up to strlen(a) in length

	StringVar(const StringVar& string_object);
	//Copy constructor.

	//	Destructor:
	//~StringVar();
	//Returns all the dynamic memory used by the object to the freestore.

	//Operator overloadings:
	friend bool operator ==(const StringVar& v1, const StringVar& v2);

	friend StringVar operator+(const StringVar& v1, const StringVar& v2);

	//	Assignment overload:
	void operator =(const StringVar& right_side);

	//	Accessors:
	int length() const;
	//Returns the length of the current string value.

	char* copy_piece(int start_pos, int end_pos) const;

	char one_char(int pos) const;

	//	Modifiers:
	void set_char(int pos, char value);

	// I/O, and operator overload:
	void input_line(std::istream& ins);
	//Precondition: If ins is a file input stream, then ins has been
	//connected to a file.
	//Action: The next text in the input stream ins, up to '\n', is copied
	//to the calling object. If there is not sufficient room, then
	//only as much as will fit is copied.

	friend std::istream& operator >>(std::istream& is, StringVar& str);

	friend std::ostream& operator <<(std::ostream& outs, const StringVar& 
		the_string);
	//Overloads the << operator so it can be used to output values
	//of type StringVar
	//Precondition: If outs is a file output stream, then outs
	//has already been connected to a file.

private:
	char *value; //pointer to dynamic array that holds the string value.
	int max_length; //declared max length of any string value.
};

//	Driver:
int main()
{
	using namespace std;

	//	Testing substring extractor:
	cout << "Constructing two StringVar variables, one empty the other\n"
		<< "with some sentence.\n";
	char* charstr;
	StringVar str1;
	StringVar str2(
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse nec.");
	StringVar str3("Nam sit amet laoreet eros. Praesent venenatis elit at sodales\n"
		"commodo. Sed ornare nulla accumsan neque elementum.");

	charstr = str2.copy_piece(6, 20);

	cout << str2 << endl;
	cout << charstr << endl;

	//	Testing >> overload:

	cout << "Enter some finite string:\n";
	cin >> str1;

	cout << "You entered:\n" << str1 << endl;

	//	Testing assignment:
	StringVar str4;

	str4 = str1;

	cout << "str4 has been assigned str1, str4 contains:\n"
		<< str4;

	//	Testing + binary overload (does not work):

	str1 = (str2 + str3);

	cout << str1 << endl;

	//	Testing == overload:
	str1 = str2; //Copy constructor call
	cout << "Are str1 and str2 the same?\n";
	cout << (str1 == str2) << endl;

	cout << "Are str2 and str3 the same?\n";
	cout << (str2 == str3) << endl;

	//	Testing single char extractor:
	char single_char = str2.one_char(20);
	cout << single_char << endl;


	char single_char_outofrange = str2.one_char(1000);
	cout << single_char_outofrange << endl;
	
	//	Testing single char modifier:
	char new_char = '\t';
	str2.set_char(20, new_char);

	cout << str2 << endl;
	
	return 0;
}

//	Proejct:
//	Operator overload definitions:

void StringVar::operator =(const StringVar& right)
{
	int new_length = strlen(right.value);
	if (new_length > max_length)
	{
		delete [] value;
		max_length = new_length;
		value = new char[max_length + 1];
	}

	for (int i = 0; i < new_length; i++)
		value[i] = right.value[i];
	value[new_length] = '\0';
}

bool operator==(const StringVar& s1, const StringVar& s2)
{
	if (!strcmp(s1.value, s2.value))
		return true;
	else
		return false;
}


StringVar operator +(const StringVar& s1, const StringVar& s2)
{
	StringVar str;
	if (str.max_length <= strlen(s2.value) + strlen(s1.value) + 1)
	{
		strncpy_s(str.value, str.max_length, s1.value, strlen(s1.value) + 1);
	}
	else
	{
		delete[] str.value;
		str.value = new char[strlen(s1.value) + 1 + strlen(s2.value)];
		strncpy_s(str.value, str.max_length, s1.value, strlen(s1.value) + 1);
	}
	str.max_length = strlen(s1.value) + strlen(s2.value) + 1;
	strncat_s(str.value, str.max_length, s2.value, str.max_length);

	return str;
}
	
std::istream& operator >> (std::istream& is, StringVar& str)
{
	//first, this function reads up to 1000 chars and stores them in
	//an array,
	//then, the content of this array is assigned to the StringVar parameter
	bool finished = false;
	int array_size = BASE_INPUT_ARRAY_SIZE;

	char *a = new char[array_size];
	char *memory;

	char next;
	int i = 0;

	is.get(next);
	//skip to first non-blank character:
	while (next == ' ' || next == '\t' || next == '\n')
		is.get(next);

	do
	{

		//read and store up to array_size characters or until the first
		//blank character:
		while (i < array_size &&
			(next != ' ' && next != '\t' && next != '\n'))
		{
			a[i] = next;
			is.get(next);
			i++;
		}

		//if we filled up the whole array ...
		if (i == array_size)
		{
			//...AND there is more to read ...
			if ((!is.fail() || !is.bad()) ||
				(next == ' ' || next == '\t' || next == '\n'))
			{

				// ...make a copy of the array ...
				memory = new char[array_size];

				for (int index = 0; index < array_size; index++)
					memory[index] = a[index];

				//...double the size of the array for the next cycle:
				array_size *= 2;

				//check if this size is getting too large:
				if (array_size > 1000)
					finished = true;
				else
				{
					//if it is not, then reassign the array and copy
					//its previous content into it, which will amount to
					//half its new size:
					a = new char[array_size];

					for (int index = 0; index < (array_size / 2); index++)
						a[index] = memory[index];

					delete[] memory;
				}
			}
			//...otherwise we are done reading
			else
				finished = true;
		}
		else
			finished = true;

		//if there was a failure to read, then clear the error:
		if (!is)
		{
			is.clear();
			is.putback(next);
		}
			
		
		
		//Stop the cycle once we are done reading:
	} while (!finished);

	//Now that array a contains the content to be read, we assign this
	//content to the StrVar parameter:
	str.value = new char[array_size + 1];// +1: it has to be a c-string
	str.max_length = array_size;

	for (unsigned int index = 0; index < i; index++)
		str.value[index] = a[index];
	str.value[i] = '\0';

	return is;
}

//	Accessor definitions:

char* StringVar::copy_piece(int start_pos, int end_pos) const
{
	if (start_pos < 0)
	{
		std::cout << "Error: negative StringVar::copy_piece(int, int)" 
			<< "start_pos parameter. Defaulting to position 0.\n";
		start_pos = 0;
	}

	if (end_pos > length() || end_pos > max_length)
	{
		std::cout << "Error: copy_piece(int, int) end_pos parameter out of\n"
			<< "occupied array range. Defaulting to length() of calling"
			<< "object.\n";
		end_pos = length();
	}

	char* result = new char[end_pos + 1];

	int iresult = 0;
	int icalling = start_pos;
	while (iresult < end_pos)
	{
		result[iresult] = value[icalling];
		iresult++;
		icalling++;
	}
	result[end_pos] = '\0';
	
	return result;
}

char StringVar::one_char(int pos) const
{
	if (pos < 0)
	{
		std::cout << "Error: one_char(int) parameter less than 0, defaulting\n"
			<< "to 0.\n";
		pos = 0;
	}

	if (pos > length())
	{
		std::cout << "Warning: one_char(int) parameter higher than utilized\n"
			<< "C-string length, defaulting to lenght().\n";
		pos = length() - 1;
	}

	return value[pos];
}

//	Modifier definitions:
void StringVar::set_char(int pos, char new_value)
{
	if (pos < 0)
	{
		std::cout << "Error: one_char(int) parameter less than 0, defaulting\n"
			<< "to 0.\n";
		pos = 0;
	}

	if (pos > length())
	{
		std::cout << "Warning: one_char(int) parameter higher than utilized\n"
			<< "C-string length, defaulting to lenght().\n";
		pos = length() - 1;
	}

	value[pos] = new_value;
}


//	Pre-made methods:
//	Constructor definitions:

//Uses cstddef and cstdlib:
StringVar::StringVar(int size) : max_length(size)
{
	value = new char[max_length + 1];//+1 is for '\0'.
	value[0] = '\0';
}

//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const char a[]) : max_length(strlen(a))
{
	value = new char[max_length + 1];//+1 is for '\0'.
	strcpy_s(value, max_length + 1, a);
}

//Uses cstddef and cstdlib
StringVar::StringVar() : max_length(100)
{
	value = new char[max_length + 1];//+1 is for '\0'.
	value[0] = '\0';
}

//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const StringVar& string_object)
: max_length(string_object.length())
{
	value = new char[max_length + 1];//+1 is for '\0'.
	strcpy_s(value, max_length, string_object.value);
}

//	Destructor definition:
/*StringVar::~StringVar()
{
	delete[] value;
}*/

//	Accessor definitions:

//Uses cstring:
int StringVar::length() const
{
	return strlen(value);
}


//	I/O definitions:

//Uses iostream:
std::ostream& operator <<(std::ostream& outs, const StringVar& the_string)
{
	outs << the_string.value;
	return outs;
}
