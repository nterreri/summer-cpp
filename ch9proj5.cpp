// ch9proj5.cpp : Defines the entry point for the console application.
// Program to simulate computer lab logins-logouts

#include "stdafx.h"
#include <iostream>
#include <iomanip>

const int LABN = 4;
const int LABSIZE[LABN] = { 5, 6, 4, 3 };

void initialize_labs(int* positions[]);

void display(int* positions[LABN]);

void input_login(int& username, int& stationid, int& labid);

bool check_position_input_for_errors(int stationid, int labid);

void input_logout(int& stationid, int& labid);

void login_user_to_position(int* positions[LABN], int userid, int stationid, int labid);

void logout_from_position(int* positions[LABN], int stationid, int labid);

void input_name(int& username);

void search_username(int *positions[LABN], int username);


//main:
int main()
{
	int* positions[LABN];
	int username, stationid, labid;
	initialize_labs(positions);


	//menu:
	using namespace std;
	char ans;

	while (true)	//	This loop never terminates, the program exits on exit()
	{
		
		cout << endl;
		cout << "Enter 1 to login a user, 2 to logout a user, 3 to search\n"
			<< "a username through the ones currently logged in or 4 to display\n"
			<< "system login status. Enter 'q' to quit.\n";

		cout << "Enter your answer:\n";
		cin >> ans;

		switch (ans)
		{
		case '1':
			input_login(username, stationid, labid);
			login_user_to_position(positions, username, stationid, labid);
			display(positions);
			break;

		case '2':
			input_logout(stationid, labid);
			logout_from_position(positions, stationid, labid);
			display(positions);
			break;

		case '3':
			input_name(username);
			search_username(positions, username);
			break;

		case '4':
			display(positions);
			break;

		case 'q':
		case 'Q':
			exit(0);
			break;	//	Unnecessary after exit(), but left in for good measure.

		default:
			cout << "Answer not recognized.\n";
		}
	} 
	
	return 0;
}

void initialize_labs(int* positions[LABN])
{
	for (int i = 0; i < LABN; i++)
		positions[i] = new int[LABSIZE[i]];
	
	for (int i = 0; i < LABN; i++)
	{
		for (int i2 = 0; i2 < LABSIZE[i]; i2++)
			positions[i][i2] = 0;
	}
}

void display(int* positions[LABN])
{
	using namespace std;

	cout.setf(ios::left);
	cout << setw(14) << "Lab Number " << "Computer Stations\n";
	for (int i = 0; i < LABN; i++)
	{
		cout << setw(14) << i + 1;
		for (int i2 = 0; i2 < LABSIZE[i]; i2++)
		{
			cout << i2 + 1 << ": ";
			if (positions[i][i2] == 0)
				cout << "empty" << " ";
			else
				cout << positions[i][i2] << " ";
		}
		
		cout << endl;
	}

}

void input_login(int& username, int& stationid, int& labid)
{
	using namespace std;
	bool input_correct;

	do
	{
		input_correct = true;
		cout << "Enter the data input: 5-digits username, station number and\n"
			<< "laboratory number:\n";


		cin >> username;
		if (username < 10000 || username > 99999)
		{
			cout << "Username must be a 5-digit number not starting with a 0.\n";
			input_correct = false;
		}

		cin >> stationid;
		cin >> labid;
		stationid--;
		labid--;

		if (!check_position_input_for_errors(stationid, labid))
		{
			cout << "Station and laboratory numbers must be valid values,\n"
				<< "among the ones displayed earlier.\n" << endl;
			input_correct = false;
		}
	} while (!input_correct);
	
}

bool check_position_input_for_errors(int stationid, int labid)
{
	bool possible_station_value,
		possible_lab_value;

	//	Check labid first:
	if (labid < 0 || labid > LABN)
		return false;
	else
		possible_lab_value = true;

	//	Then check stationid, note that since labid was checked first,
	//	there is no danger of LABSIZE[labid] falling out of bounds.
	if (stationid < 0 || stationid > LABSIZE[labid])
		return false;
	else
		possible_station_value = true;

	//	Return true if both obtain, the else clause here should never be run,
	//	because the previous two checks would already have returned a value to
	//	the calling function.
	if (possible_lab_value && possible_station_value)
		return true;
	else
		return false;

}

void input_logout(int& stationid, int& labid)
{
	using namespace std;
	bool input_correct;

	do
	{
		input_correct = true;
		cout << "Enter the data input: station number and laboratory number:\n";

		cin >> stationid;
		cin >> labid;
		stationid--;
		labid--;

		if (!check_position_input_for_errors(stationid, labid))
		{
			cout << "Station and laboratory numbers must be valid values,\n"
				<< "among the ones displayed earlier.\n" << endl;
			input_correct = false;
		}
	} while (!input_correct);

}

void login_user_to_position(int* positions[LABN], int userid, int stationid, int labid)
{
	positions[labid][stationid] = userid;
}

void logout_from_position(int* positions[LABN], int stationid, int labid)
{
	positions[labid][stationid] = 0;
}

void input_name(int& username)
{
	using namespace std;
	bool input_correct;
	do
	{
		input_correct = true;

		cout << "Enter the username:\n";
		cin >> username;

		if (username < 10000 || username > 99999)
		{
			input_correct = false;
			cout << "Input incorrect: a username is a five digit name not beginning\n"
				<< "by 0. Try again.\n" << endl;
		}

	} while (!input_correct);
	
}

void search_username(int *positions[LABN], int username)
{
	bool found = false;

	for (int i = 0; i < LABN; i++)
		for (int i2 = 0; i2 < LABSIZE[i]; i2++)
			if (positions[i][i2] == username)
			{
				std::cout << "Username currently logged at station " << i2 + 1
					<< " in laboratory " << i + 1 << std::endl;
				found = true;
			}

	if (!found)
		std::cout << "None\n";
}

