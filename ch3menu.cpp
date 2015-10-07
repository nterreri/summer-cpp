// ch3menu.cpp : Defines the entry point for the console application.
//Program to give out homework assignment information.

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int choice;

	do
	{
		cout << endl
			<< "Choose 1 to see the next homework assignment.\n"
			<< "Choose 2 for your grade on the last assignement.\n"
			<< "Choose 3 for assignment hints.\n"
			<< "Choose 4 to exit this program.\n"
			<< "Enter your choice and press Return: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			//code to display the next assignment on screen would go here.
			break;
		case 2:
			//code to ask for a student number and give the corresponding
			//grade would go here.
			break;
		case 3:
			//code to display a hint for the current assignment would go
			//here.
			break;
		case 4:
			cout << "End of Program.\n";
		default:
			cout << "Not a valid choice.\n"
				<< "Choose again.\n";
		}
	} while (choice != 4);
	
	return 0;
}

