// ch6proj3.cpp : Defines the entry point for the console application.
//Program to calculate the median of a set of numbers from a file
//Imperfect due to instructions: does not compute an average of two values on first and third quartile
//this is DUE TO INSTRUCTIONS BEING UNCLEAR

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const string FILE_NAME = "c:\\Users\\salpo\\documents\\visual studio 2013\\Projects\\ch6proj3\\ch6proj3\\ch6proj3 test input file.txt";

//void open_file(ifstream& input_stream);
//prec: uses ifstream
//postc: input_stream tried accessing the file specified under FILE_NAME and either succeded or failed
//if succeeded the program progresses, if failed the program quits either for a failure to open the file, or because the file is empty
//does not closes input file on success

int compute_total_elements();
//prec: uses iostream and ifstream
//return total number of elements in file (assuming the file is an ascending list of numbers, containing only numbers)

double compute_median(int total_elements_in_file);
//prec: parameter is initialized, uses iostream and ifstream
//returns the median of the sorted list of numbers

double compute_first_quartile(int total_elements);
//prec: parameter is initialized, uses iostream and ifstream
//returns the first quartile of the sorted list

double compute_third_quartile(int total_elements);
//prec: parameter is initialized, uses iostream and ifstream
//returns third quartile of the sorted list

int main()
{
	ifstream stream;
	double median, quartile1, quartile3;
	double next;
	int count;

	cout << "This program calculates the median of an increasing sequence of numbers.\n" << endl;

	stream.open(FILE_NAME);
	if (stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		stream.close();
		exit(1);
	}//access, failure check

	stream >> next;
	if (stream.fail())
	{
		cout << "Input file is empty.\n" << endl;
		stream.close();
		exit(0);
	}//check if the file is empty
	stream.close();

	count = compute_total_elements();

	median = compute_median(count);

	cout << "The median (or second quartile) is: " << median << endl;

	quartile1 = compute_first_quartile(count);

	cout << "The first quartile is: " << quartile1 << endl;

	quartile3 = compute_third_quartile(count);

	cout << "The thrid quartile is: " << quartile3 << endl;

	return 0;
}

/*void open_file(ifstream& stream)
{
	using namespace std;
	double first_element;

	stream.open(FILE_NAME);
	if (stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		stream.close();
		exit(1);
	}//access, failure check


	stream >> first_element;
	if (stream.fail())
	{
		cout << "Input file is empty.\n" << endl;
		stream.close();
		exit(0);
	}//check if the file is empty
}*/

int compute_total_elements()
{
	using namespace std;
	ifstream stream;
	double next;
	stream.open(FILE_NAME);
	if (stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		stream.close();
		exit(1);
	}//access, failure check

	int count = 0;
	while (stream >> next)
		count++;//couting the total number of elements

	stream.close(); //closes file opened through open_file()
	return count;
}

double compute_median(int count)
{
	using namespace std;
	ifstream stream;
	double next;

	stream.open(FILE_NAME);
	if (stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		stream.close();
		exit(1);
	}//access, failure check


	for (int i = 1; i <= (count / 2); i++)
	{
		stream >> next;
	}//counting up to half of the elements of the file

	if (count % 2 != 0)
	{
		stream >> next;
		return next;
	}//if total number of elements is odd, the median is the next file

	else if (count % 2 == 0)
	{
		double median_half1, median_half2;

		median_half1 = next;
		stream >> next;
		median_half2 = next;

		return (median_half1 + median_half2) / 2;
	}//if the total number of elements is even, the median is the mean between the current file and the next file to be read
	else
	{
		cout << "Number of elements in file neither even nor odd, this should not happen.\n" << endl;
		exit(1);
	}
}

double compute_first_quartile(int count)
{
	using namespace std;
	ifstream stream;
	double next;

	stream.open(FILE_NAME);
	if (stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		stream.close();
		exit(1);
	}//access, failure check

	int one_fourth = 0;
	while (one_fourth <= (count / 4))
	{
		stream >> next;
		one_fourth++;
	}//counting up to a quarter of the elements

	return next;
}

double compute_third_quartile(int count)
{
	using namespace std;
	ifstream stream;
	double next;

	stream.open(FILE_NAME);
	if (stream.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		stream.close();
		exit(1);
	}//access, failure check

	int threefourths = 0;
	while (threefourths <= count * 3/4)
	{
		stream >> next;
		threefourths++;
	}//counting up to the third fourth of the list
	/*if (count % 4 / 3 != 0)
	{
		stream >> next;
	}*/

	return next;
}