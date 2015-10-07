// ch3proj4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int h, m, duration;
	double cost;
	const double RATELOW = 0.25, RATEHIGH = 0.40, RATELOWEST = 0.15;
	char semicolon, d1, d2;
	const unsigned char pounds = 156;

	cout << "This program calculates the cost of a call,\n"
		<< "based on its duration and start time.\n"
		<< "Calls are most expensive 8AM to 6PM on weekdays,\n"
		<< "and least expensive on the weekend.\n\n";
		
	while (true)
	{
		cout << "Enter the first two letters of the day of the week on which the call was made,\n"
			<< "or type \'qq\' to quit the program:\n";
		cin >> d1 >> d2;

		switch (d1) //Weekday input validity check
		{
		case 'M':
		case 'm':
			switch (d2) //checking second letter for good formatting
			{
			case 'O':
			case 'o':
				break;
			default:
				//cout << "Mo default clause:\n";
				cout << "Day of week input invalid, please try again.\n";
				continue;
			}
			break;
		case 'T':
		case 't':
			switch (d2)//checking second letter for good formatting
			{
			case 'U':
			case 'u':
			case 'H':
			case 'h':
				break;
			default:
				//cout << "Tu/Th default clause:\n";
				cout << "Day of week input invalid, please try again.\n";
				continue;
			}
			break;
		case 'W':
		case 'w':
			switch (d2)
			{
			case 'E':
			case 'e':
				break;
			default:
				cout << "Day of week input invalid, please try again.\n";
				continue;
			}
			break;
		case 'F':
		case 'f':
			switch (d2)//checking second letter for good formatting
			{
			case 'R':
			case 'r':
				break;
			default:
				cout << "Day of week input invalid, please try again.\n";
				continue;
			}
			break;

		case 'S':
		case 's':
			switch (d2)//checking second letter for good formatting
			{
			case 'A':
			case 'a':
			case 'U':
			case 'u':
				break;
			default:
				cout << "Day of week input invalid, please try again.\n";
				continue;
			}
			break;

		case 'Q':
		case 'q':
			switch (d2)
			{
			case 'Q':
			case 'q':
				exit(0);
			default:
				cout << "Input invalid, try again.\n"
					<< "Type two \'q\'s to exit the program.\n";
				continue;
			}
		default:
			//cout << "d1 variable switch default clause:\n";
			cout << "Day of week input invalid, please try again.\n";
			continue;
		}

		cout << "Enter the time the call started in 24-hour format (e.g.: 13:30):\n";
		cin >> h;
		cin >> semicolon;
		if (semicolon != ':')
		{
			cout << "Input format invalid, please try again.\n";
			cin.ignore();
			cin.ignore();
			continue;
		}
		cin >> m;

		cout << "Enter the duration of the call in minutes (rounded to the nearest whole number):\n";
		cin >> duration;

		switch (d1)
		{
			case 'M':
			case 'm':
			case 'T':
			case 't':
			case 'W':
			case 'w':
			case 'F':
			case 'f':
			
				if (h < 8 || h > 18)
					cost = duration * RATELOW;
				else
					cost = duration * RATEHIGH;
				break;

			case 'S':
			case 's':

				cost = duration * RATELOWEST;
				break;

			default:
				cout << "Something went wrong, try again.\n";
				continue;
		}
	
		cout << "The cost of a call started on " << d1
			<< d2 << " at " << h << ':' << m;
		if (m == 0)
			cout << 0;//to avoid printing something like: 8:0
		cout << " is:\n" << pounds << cost << endl;
	}
	return 0;
}

