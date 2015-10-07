// ch7proj13.cpp : Defines the entry point for the console application.
//	Program to play LIFE

#include "stdafx.h"
#include <iostream>

const int ROWS = 22;
const int COLUMNS = 80;

void initialize_world(char world[][COLUMNS]);

void display(const char world[][COLUMNS]);

void generation(char world[][COLUMNS]);

void copy_world(const char copied[][COLUMNS], char copy[][COLUMNS]);

int count_neighbours(const char world[][COLUMNS], int row, int column);

int main()
{
	char world[ROWS][COLUMNS];
	char loopcontrol;

	initialize_world(world);

	std::cout << "This program plays a game of LIFE.\n" << std::endl;

	do
	{
		display(world);
		generation(world);

		std::cout << "Press enter to continue, or \'q\' to quit:\n";
		std::cin.get(loopcontrol);
	} while (loopcontrol != 'q');

	while (loopcontrol != '\n')
		std::cin.get(loopcontrol);
	
	return 0;
}

void initialize_world(char world[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int i2 = 0; i2 < COLUMNS; i2++)
		{
			world[i][i2] = ' ';
		}
	}

	//Modify here
	world[10][40] = 'X';
	world[10][41] = 'X';
	world[10][42] = 'X';
	world[11][41] = 'X';
}

void display(const char world[][COLUMNS])
{
	using namespace std;

	cout << endl << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int i2 = 0; i2 < COLUMNS; i2++)
			cout << world[i][i2];
	}
}

void generation(char world[][COLUMNS])
{
	char world_buffer[ROWS][COLUMNS];
	copy_world(world, world_buffer);

	for (int i = 0; i < ROWS; i++)
	{
		for (int i2 = 0; i2 < COLUMNS; i2++)
		{
			int neighbours = count_neighbours(world, i, i2);

			if (world[i][i2] == 'X')
			{
				if (neighbours <= 1)
					world_buffer[i][i2] = ' ';
				else if (neighbours > 3)
					world_buffer[i][i2] = ' ';
			}
			else if (world[i][i2] == ' ')
			{
				if (neighbours == 3)
					world_buffer[i][i2] = 'X';
			}

		}
	}

	copy_world(world_buffer, world);
}

void copy_world(const char copied[][COLUMNS], char copy[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int i2 = 0; i2 < COLUMNS; i2++)
			copy[i][i2] = copied[i][i2];
	}
}

int count_neighbours(const char world[][COLUMNS], int row, int column)
{
	int neighbour_count = 0;
	if (row > 0)
	{
		for (int i = column - 1; i <= column + 1; i++)
			if (world[row - 1][i] == 'X')
				neighbour_count++;
	}
	
	if (row < ROWS - 1)
	{
		for (int i = column - 1; i <= column + 1; i++)
			if (world[row + 1][i] == 'X')
				neighbour_count++;
	}

	if (column > 0)
	{
		if (world[row][column - 1] == 'X')
			neighbour_count++;
	}
	if (column < COLUMNS - 1)
	{
		if (world[row][column + 1] == 'X')
			neighbour_count++;
	}

	return neighbour_count;
}