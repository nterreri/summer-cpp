// ch11proj13.cpp : Defines the entry point for the console application.
/*task 1:
Modify the StringSet from Programming Project 12 by adding an
additional member function that computes the similarity between the
current StringSet and an input parameter of type StringSet. The sqrt
function is in the cmath library.*/

/*task 2:
Create two text files on your disk named Document1.txt and Document2.txt.
Write some text content of your choice in each file, but make sure that
each file contains different content.*/

/*task 3:
Next, write a program that allows the
user to input from the keyboard a set of strings that represents a query.
The program should then compare the query to both text files on the disk
and output the similarity to each one using the binary cosine coefficient.*/

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class StringSet
{
public:
	StringSet();
	StringSet(const std::string *string_array, int array_size);

	//accessors:
	int size() const;

	//modifiers:
	void push_back(std::string);
	void remove(std::string);
	void clear_set();

	//Operators:
	friend StringSet operator+(const StringSet& left, const StringSet& right);
	friend StringSet operator*(const StringSet& left, const StringSet& right);

	//I/O:
	void output(std::ostream& os = std::cout) const;

	//Other:
	double compute_similarity(const StringSet&) const;

private:
	void erase_duplicates();
	std::vector<std::string> set;
};

void delete_entry(std::vector<std::string>& v, int pos);
//-----------------------------------------------------------------------------
void read_query(StringSet& query);
std::string get_next_word(std::string, unsigned int& i);
void read_document(std::istream& is, StringSet& document);

//-----------------------------------------------------------------------------
int main()
{
	using namespace std;

	cout << "Enter your query on a single line (a set of strings,\n"
		<< "no capitalization or punctuation of any kind):\n";
	StringSet query;
	read_query(query);

	StringSet docstrset1, docstrset2;
	ifstream is;

	cout << "Reading document1.txt ...\n";
	is.open("document1.txt");
	if (is.fail())
		exit(1);
	read_document(is, docstrset1);
	is.close();

	cout << "Reading document2.txt ...\n";
	is.open("document2.txt");
		if (is.fail())
			exit(1);
	read_document(is, docstrset2);
	is.close();

	cout << "Read both documents.\n";
	cout << "The similarity between the query and document1.txt scores\n"
		<< "a binary cosine coefficient of: "
		<< query.compute_similarity(docstrset1) << endl;
	cout << "The similarity between the query and document2.txt scores:\n"
		<< "a binary cosine coefficient of: "
		<< query.compute_similarity(docstrset2) << endl;

	return 0;
}

//StringSet implementation:
//Constructor:
StringSet::StringSet()
{
	set.reserve(0);
}
StringSet::StringSet(const std::string *string_array, int array_size)
{
	/*This constructor requires the number of elements in the dynamic array
	to be passed as a parameter in addition to the pointer.

	This is a less elegant solution: because it would require an additional argument
	in constructor call. However, itis a more versatile solution:
	generally, it is easy to pass this information as variable of some sort:
	for example, calling the constructor with a set of words read from a file.
	It is easy enough to build a function that reads and keeps count of how
	many words it has read.*/

	set.reserve(array_size);
	for (int i = 0; i < array_size; i++)
		set.push_back(string_array[i]);

	erase_duplicates();

}

//Public methods:
//Accessors:
int StringSet::size() const
{
	return set.size();
}

//Modifiers:
void StringSet::push_back(std::string parameter)
{
	set.reserve(set.size() + 1);
	set.push_back(parameter);

	erase_duplicates();
}
void StringSet::remove(std::string parameter)
{
	unsigned int i = 0;
	while (i < set.size())
	{
		if (set[i] == parameter)
			delete_entry(set, i);
		i++;
	}

	erase_duplicates();
}
void StringSet::clear_set()
{
	set.resize(0);
}

//Operators:
StringSet operator+(const StringSet& left, const StringSet& right)
{
	std::string *stringptr = new std::string[left.set.size() + right.set.size()];

	unsigned int i = 0;
	while (i < left.set.size())
	{
		stringptr[i] = left.set[i];
		i++;
	}

	unsigned int j = 0;
	while (j < right.set.size())
	{
		stringptr[i] = right.set[j];
		j++;
		i++;
	}

	StringSet result(stringptr, (left.set.size() + right.set.size()));

	return result;
}
StringSet operator*(const StringSet& left, const StringSet& right)
{
	std::vector<std::string> stringv;

	for (unsigned int i = 0; i < left.set.size(); i++)
		for (unsigned int j = 0; j < right.set.size(); j++)
		{
			if (left.set[i] == right.set[j])
				stringv.push_back(left.set[i]);
		}

	StringSet result;
	result.set = stringv;
	return result;
}

//Others:
void StringSet::output(std::ostream& os) const
{
	for (unsigned int i = 0; i < set.size(); i++)
	{
		os << set[i] << " ";
	}
}
double StringSet::compute_similarity(const StringSet& parameter) const
{
	StringSet product;
	product = *this * parameter;

	return (product.size() / (sqrt(size()) * sqrt(parameter.size())));
}

//Private methods:
void StringSet::erase_duplicates()
{
	//Given that the StringSet type stores SETS of strings, duplicate strings
	//are not allowed.


	//Compare each element of the set with all the following elements:
	for (unsigned int i = 0; i < set.size(); i++)
		for (unsigned int j = (i + 1); 	/*(j != i) &&*/ j < set.size(); j++)
			if (set[j] == set[i])
			{
				delete_entry(set, j);
				set.resize(set.size() - 1);
			}
	//"delete" position: from this position, copy the next element
	//back one place up to position [set.size() - 1]
}

//Other functions:
void delete_entry(std::vector<std::string>& v, int pos)
{
	for (unsigned int i = pos; i < (v.size() - 1); i++)
		v[i] = v[i + 1];
}
void read_query(StringSet& query)
{
	std::string line;
	std::getline(std::cin, line);

	for (unsigned int i = 0; i < line.length(); i++)
		query.push_back(get_next_word(line, i));
}
std::string get_next_word(std::string line, unsigned int& index)
{
	//skip to next non-blank
	while (index < line.length() && (
		line[index] == ' ' || line[index] == '\t' || line[index] == ','
		|| line[index] == ';' || line[index] == '.' || line[index] == ':'
		|| line[index] == '!' || line[index] == '?' || line[index] == '"'
		|| line[index] == '\'' || line[index] == '(' || line[index] == ')'))
		index++;

	//store each nonblank in a char vector/array or string in lowercase
	std::string word;

	while (index < line.length() && (
		line[index] != ' ' && line[index] != '\t' && line[index] != '\n' &&
		line[index] != ',' && line[index] != ';' && line[index] != '.' &&
		line[index] != ':' && line[index] != '!' && line[index] != '?' &&
		line[index] != '"' && line[index] != '\'' && line[index] != '(' &&
		line[index] != ')'))
	{
		word.push_back(tolower(line[index]));
		index++;
	}

	//return this char vector/array/string:
	return word;
}
void read_document(std::istream& is, StringSet& documentstrset)
{
	
	while (!is.eof())
	{
		std::string line;
		std::getline(is, line);

		for (unsigned int i = 0; i < line.length(); i++)
			documentstrset.push_back(get_next_word(line, i));
	}
}

