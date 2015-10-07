// ch7proj1.cpp : Defines the entry point for the console application.
//Program to read average and actual monthly rainfall (mm) for a city and output a well-formatted
//table with the differences

#include "stdafx.h"
#include <cstdlib> //for exit() function
#include <fstream>
#include <iostream>
#include <iomanip>

const int NUMBER_OF_MONTHS = 12;

void input(double averages[], double actuals[]);
//Prec: uses iostream
//Postc: averages, and actuals have been initialized with NUMBER_OF_MONTHS values

void pick_month(int iteration);
//prec: parameter is initialized, uses iostream
//postc: name of month is printed to screen corresponding to the value of the parameter:
// 0 for January, 1 for February etc..

void read_month(double actual[]);
//prec: called from input(double, double)
//postc: initialize actuals is called with number_corresponding_to_month
//determined on the basis of user input

void initialize_actuals(int number_corresponding_to_month, double actuals[]);
//prec: parameter value is used to determine the numeric value
//identifying the current month following user input, uses iostream
//postc: initializes actuals[NUMBER_OF_MONTHS] from keyboard

void compute_difference(const double averages[], const double actuals[], double differences[]);
//prec: const parameters are initialized for NUMBER_OF_MONTHS values
//postc: differences[NUMBER_OF_MONTHS] are initialized with actual[i] - averages[i] each

void output_table(double difference[], double actuals[]);
//prec: NUMBER_OF_MONTHS values are initialized for both arrays, uses iostream and iomanip
//postc: prints a table to screen:
//names of four months ...
//actual values followed by difference for each month ...

void ouput_graph(const double averages[], const double actuals[]);
//prec: array parameters are initialized, uses iostream
//postc: first, finds the maximum value in either array parameter,
//then it outputs a graph comparing average and actual rainfall measures
//scaled to this maximum value

int main()
{
	using namespace std;

	cout << "This program reads in average rainfall measurements for a year,\n"
		<< "and the actual rainfall measurements for the previous year.\n"
		<< "It then outputs a well-formatted table comparing the actual\n"
		<< "measurements with the averages.\n"
		<< endl;

	double average[NUMBER_OF_MONTHS];
	double actual[NUMBER_OF_MONTHS];
	double difference[NUMBER_OF_MONTHS];
	//double differencepercent[NUMBER_OF_MONTHS];

	input(average, actual);
	compute_difference(average, actual, difference);

	do
	{
		cout << endl
			<< "To see a table of actual measurements, and their variance\n"
			<< "from the average for each month, type 1 then press enter.\n"
			<< "To see a graph comparing actual and average measurements for\n"
			<< "each month, type 2 instead, then press enter.\n"
			<< "Otherwise, type 0 then press enter to quit:\n";

		char choice;
		cin >> choice;
		if (choice == '0')
			exit(0);
		else if (choice == '1')
			output_table(difference, actual);
		else if (choice == '2')
		{
			ouput_graph(average, actual);
		}
		else
		{
			cout << "Invalid input, try again.\n";
		}
	} while (true);

	return 0;
}

//input
void input(double average[], double actual[])
{
	using namespace std;

	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		cout << "Enter the *average* precipitation (in mm) for the month of ";
		pick_month(i);
		cout << ": ";
		cin >> average[i];
		if (cin.fail())
		{
			cout << "Bad input, try again.\n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			input(average, actual);
		}
	}

	cout << "Which month is it?\n" << endl;

	read_month(actual); //reads a month from keyboard, then calls initialize_actuals()
	//with appropriate parameters

	//unused for loop to read actual measurements for the past year:

	//Due to problem specification asking the user to input the current month,
	//and THEN prompting for input for the previous 12 months,
	//the program has been made to count backwards from the current month
	//through read_month(double []) and initialize_actuals(int, double [])
	//The result is the same in either case, but through a significantly more complicated
	//route rather than a straighforward for loop

	/*for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
	cout << "Enter the *actual* precipitation (in mm) for the previous month of ";
	pick_month(i);
	cout << ": ";
	cin >> actual[i];
	if (cin.fail())
	{
	cout << "Bad input, try again.\n" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	input(average, actual);
	}
	}*/
}

//pick_month
void pick_month(int iteration)
{
	using namespace std;

	switch (iteration)
	{
	case 0:
		cout << "January";
		break;
	case 1:
		cout << "February";
		break;
	case 2:
		cout << "March";
		break;
	case 3:
		cout << "April";
		break;
	case 4:
		cout << "May";
		break;
	case 5:
		cout << "June";
		break;
	case 6:
		cout << "July";
		break;
	case 7:
		cout << "August";
		break;
	case 8:
		cout << "September";
		break;
	case 9:
		cout << "October";
		break;
	case 10:
		cout << "November";
		break;
	case 11:
		cout << "December";
		break;
	}
}

//read month function, this one is done using char,
//and several nested switch loops over one main switch
//but a similar one, perhaps more clear one, could be
//written using <string>
void read_month(double actual[])
{
	using namespace std;

	char input;
	cin >> input;
	switch (input)
	{
		//if input is alphabetic:
	case 'j':
	case 'J':
		cin >> input;
		switch (input)
		{
		case 'a':
		case 'A':
			initialize_actuals(0, actual);
			break;
		case 'u':
		case 'U':
			cin >> input;
			switch (input)
			{
			case 'n':
			case'N':
				initialize_actuals(5, actual);
				break;
			case 'l':
			case 'L':
				initialize_actuals(6, actual);
				break;
			}
			break;
		}
		break;
	case 'f':
	case 'F':
		initialize_actuals(1, actual);
		break;
	case 'm':
	case 'M':
		cin >> input;
		switch (input)
		{
		case 'a':
		case 'A':
			cin >> input;
			switch (input)
			{
			case 'y':
			case 'Y':
				initialize_actuals(4, actual);
				break;
			case 'r':
			case 'R':
				initialize_actuals(2, actual);
				break;
			}
			break;
		}
		break;
	case 'a':
	case 'A':
		cin >> input;
		switch (input)
		{
		case 'p':
		case 'P':
			initialize_actuals(3, actual);
			break;
		case 'u':
		case 'U':
			initialize_actuals(7, actual);
			break;
		}
		break;
	case 's':
	case 'S':
		initialize_actuals(8, actual);
		break;
	case 'o':
	case 'O':
		initialize_actuals(9, actual);
		break;
	case 'n':
	case 'N':
		initialize_actuals(10, actual);
		break;
	case 'd':
	case 'D':
		initialize_actuals(11, actual);
		break;
		//if input is numeric:
	case '1':
	{
		cin.get(input);
		switch (input)
		{
		case '0':
			initialize_actuals(9, actual);
			break;
		case '1':
			initialize_actuals(10, actual);
			break;
		case '2':
			initialize_actuals(11, actual);
			break;
		default:
			initialize_actuals(0, actual);
			break;
		}
		break;
	}
	break;
	case '2':
		initialize_actuals(1, actual);
		break;
	case '3':
		initialize_actuals(2, actual);
		break;
	case '4':
		initialize_actuals(3, actual);
		break;
	case '5':
		initialize_actuals(4, actual);
		break;
	case '6':
		initialize_actuals(5, actual);
		break;
	case '7':
		initialize_actuals(6, actual);
		break;
	case '8':
		initialize_actuals(7, actual);
		break;
	case '9':
		initialize_actuals(8, actual);
		break;
	}
}

void initialize_actuals(int month_index, double actual[])
{
	using namespace std;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//ignores rest of input leftover from read_month(),
	//e.g. if the user wrote "January",
	//the loop only reads up to "Ja".
	//This is because those initials are sufficient to identify the
	//month of January, whereas "J" alone is not, since
	//there are three months starting with a "j" in English.
	//The ignore method clears the rest of the input: "nuary"
	//which would be treated as input for the the present sub-function
	//by the program.

	//Indeed, the user may have written "Janus" or
	//"JAruary" or "jaaaaaaaaaaaaaaaaa" but the program would
	//still decide the user meant to say that the current month is
	//January

	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		month_index--;//get previous month
		if (month_index < 0)
			month_index = NUMBER_OF_MONTHS - 1;//reset value to max when goint to negatives
		cout << "Enter the *actual* precipitation (in mm) for the previous month of ";
		pick_month(month_index);
		cout << ": ";
		cin >> actual[month_index];
	}
}

void compute_difference(const double average[], const double actual[], double difference[])
{
	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		difference[i] = actual[i] - average[i]; //if average > actual this lends a negative number
		//otherwise if average < actual this lends a positive number
	}
}

//compute/store % difference body, unused:
//Could not figure out how to make output format behave
//with a '%' sign printed after differencepercent[i].
//The width of the output depends on whether 1, 2 or 3 (or more) digits
//have to be printed to represent the percentage increase or decrease
//over the monthly average, but the % sing is always shifted to the right
//if (ios::left) is on
/*
{
for (int i = 0; i < NUMBER_OF_MONTHS; i++)
{
differencepercent[i] = difference[i] * (100 / average[i]); //this is a positive or negative number
//depending on the sign of the number in difference[i]
}
}*/

//output_table
void output_table(double difference[], double actual[])
{
	using namespace std;

	cout << endl
		<< "Table format:\n"
		<< endl
		<< "\"Month\"\n"
		<< "[actual measure] [difference from the monthly average]\n";

	cout << endl
		<< "All measures shown in mm:\n"
		<< endl;

	cout.setf(ios::left);
	cout.setf(ios::fixed);
	cout.precision(0);
	cout.unsetf(ios::showpoint);
	for (int i = 0; i < NUMBER_OF_MONTHS - 8; i++)
	{
		cout.width(17);
		pick_month(i);
	}

	cout << endl;
	for (int i = 0; i < NUMBER_OF_MONTHS - 8; i++)
	{
		cout.width(5);
		cout << actual[i] << " ";
		cout.setf(ios::showpos);
		cout.width(11);
		cout << difference[i];
		cout.unsetf(ios::showpos);

	}
	cout << endl;

	for (int i = NUMBER_OF_MONTHS - 8; i < NUMBER_OF_MONTHS - 4; i++)
	{
		cout.width(17);
		pick_month(i);
	}

	cout << endl;
	for (int i = NUMBER_OF_MONTHS - 8; i < NUMBER_OF_MONTHS - 4; i++)
	{
		cout.width(5);
		cout << actual[i] << " ";
		cout.setf(ios::showpos);
		cout.width(11);
		cout << difference[i];
		cout.unsetf(ios::showpos);
	}
	cout << endl;

	for (int i = NUMBER_OF_MONTHS - 4; i < NUMBER_OF_MONTHS; i++)
	{
		cout.width(17);
		pick_month(i);
	}

	cout << endl;
	for (int i = NUMBER_OF_MONTHS - 4; i < NUMBER_OF_MONTHS; i++)
	{
		cout.width(5);
		cout << actual[i] << " ";
		cout.setf(ios::showpos);
		cout.width(11);
		cout << difference[i];
		cout.unsetf(ios::showpos);
	}	cout << endl;

}

void ouput_graph(const double average[], const double actual[])
{
	using namespace std;

	double max = average[0];//assume the first value is the max
	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		if (max < average[i])//compare the current max with the
			max = average[i];//next value in array ...
	}

	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		if (max < actual[i])
			max = actual[i];
	}
	//at the end, max is the maximum value of all the ones in these arrays

	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		cout << endl;
		pick_month(i);//outputs name of month
		cout << ":\n";

		cout << "Average: ";
		for (int index = 0; index < average[i] * 25 / max; index++)
			cout << "*"; //writes "average[i] * 25 / max" asterisks
		cout << endl;	//if the ith average is max, outputs 25 asterisks

		cout << "Measured: ";
		for (int index = 0; index < actual[i] * 25 / max; index++)
			cout << "*";
		cout << endl;
	}
}