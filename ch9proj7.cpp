// ch9proj7.cpp : Defines the entry point for the console application.
// Program to emulate multi-dimensional arrays wrapper functions

#include "stdafx.h"
#include <iostream>

const int ROWS = 2, COLUMNS = 3;


int* create2DArray(int rows, int columns);
//	See project specification

void fill_2D_array(int* pointer);
//	Initializes the pointer's space with as many int values as a[ROWS][COLUMNS]

void fill_2D_array(int a[][COLUMNS]);
//	Same as the other overload, but for a[][]

void output(int a[][COLUMNS]);
//	Prints out all of the values in a, dividing row by row

void output(int* pointer);
//	Prints out all the values in pointer, in a single row

void set(int* arr, int rows, int columns,
	int desired_row, int desired_column, int val);
//	Puts value val in arr[desired_row][desired_column]

int get(int* arr, int rows, int columns,
	int desired_row, int desired_column);
//	Returns the value in arr[desired_row][desired_column]

int main()
{

	int a[ROWS][COLUMNS];
	int* ptr = create2DArray(ROWS, COLUMNS);

	fill_2D_array(a);
	fill_2D_array(ptr);

	a[1][1] = 10;
	set(ptr, ROWS, COLUMNS, 1, 1, 10);

	std::cout << a[1][0] << std::endl;
	std::cout << get(ptr, ROWS, COLUMNS, 1, 0) << std::endl;
	std::cout << a[1][1] << std::endl;
	std::cout << get(ptr, ROWS, COLUMNS, 1, 1) << std::endl;

	output(a);
	output(ptr);

	return 0;
}

int* create2DArray(int rows, int columns)
{
	int* result = new int[rows*columns];
	return result;
}

void fill_2D_array(int* pointer)
{
	for (int i = 0; i < ROWS*COLUMNS; i++)
			pointer[i] = 0;
}

void fill_2D_array(int a[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
		for (int i2 = 0; i2 < COLUMNS; i2++)
			a[i][i2] = 0;
}

void output(int a[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int i2 = 0; i2 < COLUMNS; i2++)
			std::cout << a[i][i2] << " ";
		std::cout << std::endl;
	}
	
}

void output(int* pointer)
{
	for (int i = 0; i < ROWS * COLUMNS; i++)
		std::cout << pointer[i] << " ";
	std::cout << std::endl;
}

void set(int* arr, int rows, int columns,
	int desired_row, int desired_column, int val)
{
	if (desired_row < rows && desired_column < columns)
		arr[desired_row * columns + desired_column] = val;
	else
	{
		std::cout << "Error: set value coordinates out of bounds.\n";
		exit(1);
	}
}

int get(int* arr, int rows, int columns,
	int desired_row, int desired_column)
{
	if (desired_row < rows && desired_column < columns)
		return arr[desired_row * columns + desired_column];
	else
	{
		std::cout << "Error: get value coordinates out of bounds.\n";
		exit(1);
	}
}
