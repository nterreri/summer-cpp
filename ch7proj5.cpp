// ch7proj5.cpp : Defines the entry point for the console application.
// Program to read a list of integers, then print out two columns to screen:
// one with the integers sorted from the largest, the second
// with the number of occurrences of the number

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

const int MAX = 50;

void input(int input_array[], int& size_used);
//prec: uses iostream and string and ifstream
//postc: the user is prompted to enter
//either input from keyboard, or from a file
//then input is read

int get_index_of_next_largest(int a[], int start_index, int size_used);
//prec: 0 <= start_index < size_used, parameters are initialized
//array is at least partially initialized.
//Returns: the index of the largest number in array between
//start_index and (size_used - 1)

void swap_values(int& v1, int& v2);
//prec: parameters are initialized
//postc: the value of v2 is now in v1 and
//viceversa

int sort_repeats(int a[], int size_used,
	int largest, int index_of_largest_after_swap);
//prec: array is filled with size_used values,
//largest is the largest value in range within a,
//index_of_largest is its index in a
//postc: swaps places between any other occurrence
//of value equal to largest from index_of_largest
//placing any such value just after largest in array a.
//Returns the number of occurrences of largest within 
//a

void delete_repeats(int a[], int& size, int index_of_largest_after_swap
	, int occurrences_of_largest);
//prec: array is filled with size values, all parameters are
//initialized properly, the next largest value in array has been shifted all the
//way to the left (closer to the 0th index) next to the previous largest value
//and any repetition of the next largest value has been placed in front of it
//(i.e. from index_of_largest_after_swap + 1).
//Postc: any such repetition is swapped for the last value in array,
//and by-reference-parameter size is decreased.
//This is a way to "delete" repetitions by shifting them to the end of the array
//a more straightforward way is to simply assign the last value in array
//to the position index_of_largest_after_swap + a number less than
//index_of_largest_after_swap + occurrences_of_largest.


//main:
int main()
{
	int list[MAX];
	int occurrences[MAX];
	int size;

	input(list, size);

	int index_of_largest[MAX];
	for (int i = 0; i < size; i++)
	{
		index_of_largest[i] = get_index_of_next_largest(list, i, size);
		swap_values(list[index_of_largest[i]], list[i]);
		int occurrences_of_largest = sort_repeats(list, size, list[i], i);
		delete_repeats(list, size, i, occurrences_of_largest);
		occurrences[i] = occurrences_of_largest;
	}

	std::cout << "Number" << '\t' << "Occurrences" << std::endl << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << list[i] << '\t' << occurrences[i] << std::endl;
	}

	std::cout << "Enter anything to quit:\n";
	char anything;
	std::cin >> anything;

	return 0;
}

void input(int input_array[], int& size_used)
{
	using namespace std;

	string filename;
	ifstream is;
	
	char ans;
	cout << "Enter 1 to enter input via keyboard\n"
		<< "or 2 to enter input via file:\n";
	cin >> ans;
	if (ans == '1')
	{
		cin.ignore(); //ignore first newline character, the one after ans
		cout << "Enter the list of integer numbers:\n";
		
		size_used = 0;
		char next;
		cin.get(next);
		for (int i = 0; i < 50 && next != '\n'; i++)
		{
			cin.putback(next);
			cin >> input_array[i];
			size_used++;
			cin.get(next);
		}
	}
	else if (ans == '2')
	{
		cout << "Enter the name of the file:\n";
		cin >> filename;

		is.open(filename);
		if (is.fail())
		{
			cout << "Failed to open input file.\n";
			exit(1);
		}

		size_used = 0;
		for (int i = 0; i < 50; i++)
		{
			is >> input_array[i];
			if (is.eof())	//if the cycle breaks at eof,
				break;		//then is >> fails but
			size_used++;	//size_used++ would still be executed
		}					//making size_used off by one too many

		
		is.close();
	}
	else
	{
		cout << "Invalid input.\n";
		input(input_array, size_used);
	}
}


int get_index_of_next_largest(int a[], int start_index, int size_used)
{
	int largest = a[start_index];
	int index_of_largest = start_index;
	for (int i = start_index; i < size_used; i++)
	{
		if (a[i] > largest)
		{
			largest = a[i];
			index_of_largest = i;
		}
	}

	return index_of_largest;
}


int sort_repeats(int a[], int size_used,
	int largest, int index_of_largest_after_swap)
{
	int occurrences_counter = 1;
	for (int i = index_of_largest_after_swap + 1; i < size_used; i++)
	{
		if (a[i] == largest)
		{
			swap_values(a[i],
				a[index_of_largest_after_swap + occurrences_counter]);
			occurrences_counter++;
		}
	}

	return occurrences_counter;
}


void delete_repeats(int a[], int& size, int index_of_largest_after_swap
	, int occurrences_of_largest)
{
	for (int i = index_of_largest_after_swap + 1; 
		i < (index_of_largest_after_swap + occurrences_of_largest); i++)
	{
		swap_values(a[i], a[size - 1]);
		size--;
	}
}


void swap_values(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

