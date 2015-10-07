// ch8proj9.cpp : Defines the entry point for the console application.
// Reproduction of selection sort with vectors instead of arrays.

#include "stdafx.h"
#include <iostream>
#include <vector>

void fill_vector(std::vector<int>& v);

void selection_sort(std::vector<int>& v);

int get_index_of_smallest(std::vector<int> v, int start_index);

void swap_values(int& v1, int& v2);

int main()
{
	using namespace std;
	cout << "This program sorts number from lowest to highest.\n";

	vector<int> sample_vector;
	fill_vector(sample_vector);
	selection_sort(sample_vector);

	cout << "In sorted order the numbers are:\n";
	for (int i = 0; i < static_cast<int>(sample_vector.size()); i++)
		cout << sample_vector[i] << " ";
	cout << endl;

	return 0;
}

void fill_vector(std::vector<int>& v)
{
	using namespace std;
	cout << "Enter some nonnegative whole numbers.\n"
		<< "Mark the end of the list with a negative number.\n";
	int next;
	int i = 0;
	cin >> next;
	while (next >= 0 /*&& i < static_cast<int>(v.capacity())*/)
	{
		v.push_back(next);
		i++;
		cin >> next;
	}
}

void selection_sort(std::vector<int>& v)
{
	int index_of_next_smallest;
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		index_of_next_smallest = get_index_of_smallest(v, i);
		swap_values(v[i], v[index_of_next_smallest]);
	}
}

int get_index_of_smallest(std::vector<int> v, int start_index)
{
	int min = v[start_index];
	int index_of_min = start_index;
	for (int i = start_index + 1; i < static_cast<int>(v.size()); i++)
		if (v[i] < min)
		{
			min = v[i];
			index_of_min = i;
		}

	return index_of_min;
}

void swap_values(int& v1, int& v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}