// ch6proj7.cpp : Defines the entry point for the console application.
//Program reading two files of integers sorted in ascending order and merging the two into a third output file
//always in ascending order

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const string INPUT1 = "input1.dat";
const string INPUT2 = "input2.dat";

void merge_files(ifstream& file1, ifstream& file2, ofstream& output_file);
//prec: fstreams are accessing different files, uses fstream
//postc: merges file1 and file2 in output_file

int count_elements(ifstream& input_stream);
//prec: input file must be accessing a file already with nothing read yet, uses fstream
//returns the number of integer numbers in input stream, does not close streams

int main()
{
	ifstream istream1, istream2;
	ofstream ostream;

	istream1.open(INPUT1);
	if (istream1.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}
	istream2.open(INPUT2);
	if (istream2.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}
	ostream.open("merged.txt");
	if (ostream.fail())
	{
		cout << "Failed to open output file.\n" << endl;
		exit(1);
	}

	merge_files(istream1, istream2, ostream);
	istream1.close();
	istream2.close();
	ostream.close();

	cout << "Merged files \"input1.dat\" and \"input2.dat\" into \"merged.txt\".\n" << endl;

	return 0;
}

void merge_files(ifstream& is1, ifstream& is2, ofstream& os)
{
	int nextf1, nextf2;
	int size1, size2;

	size1 = count_elements(is1);
	size2 = count_elements(is2);

	is1.close();
	is2.close();
	is1.open(INPUT1);
	if (is1.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}
	is2.open(INPUT2);
	if (is2.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}

	is1 >> nextf1;
	is2 >> nextf2;

	int count1 = 1, count2 = 1;
	while (count1 <= size1 || count2 <= size2)//loop based on whether both files have been completely read
	{
		//cout << " looping ";
		if (nextf1 >= nextf2)
		{
			os << nextf2;
			os << ' ';
			//cout << nextf2 << " ";
			is2 >> nextf2;
			count2++;
		}
		else if (nextf2 >= nextf1)
		{
			os << nextf1;
			os << ' ';
			//cout << nextf1 << " ";
			is1 >> nextf1;
			count1++;
		}
		else if (nextf1 == nextf2)
		{
			os << nextf1;
			os << ' ';
			is1 >> nextf1;
			is2 >> nextf2;
			count1++;
			count2++;
		}
		
		if (count1 >= size1 && count2 <= size2) //these are necessary to give the program a way to print the rest of the input
			//after the end of the first input file
		{
			os << nextf1;//these instructions before the loop
			os << ' ';//make the program print the last element of the shorter list
			count1++;//in the appropriate position
			while (count2 <= size2)
			{
				os << nextf2;
				os << ' ';
				is2 >> nextf2;
				count2++;
			}
		}
		else if (count2 >= size2 && count1 <= size2)//these are necessary to give the program a way to print the rest of the input
			//after the end of the first input file
		{
			os << nextf2;//these instructions before the loop
			os << ' ';//make the program print the last element of the shorter list
			count2++;//in the appropriate position
			while (count1 <= size1)
			{
				os << nextf1;
				os << ' ';
				is2 >> nextf1;
				count1++;
			}
		}
	}
	//cout << " end loop" << endl;
}

int count_elements(ifstream& input)
{
	int count = 0;
	int next;

	while (input >> next)
		count++;

	return count;
}