// ch11proj15.cpp : Defines the entry point for the console application.
/*outline:
Write a program that reads the posted voting list from a file and outputs
the percent of votes cast for each ballot item.*/

/*task 1:
You may assume that the file
does not have any header lines. The first line will contain a voter ID and a
string representing votes.*/

/*task 2:
Define a class named Voter that stores an
individual’s voting record. The class should have a constructor that takes
as input a string of votes (e.g., “CDGH”), a voter ID, and accessor
function(s) that return the person’s ID and vote for a specific question.*/

/*task 3:
Store each Voter instance in an array or vector. Your program should
iterate over the array to compute and output the percent of votes cast for
each candidate, proposition, and measure. It should then prompt the user
to enter a voter ID, iterate over the list again to find the object with that
ID, and print his or her votes.*/

#include "stdafx.h"
#include <fstream>
#include <iostream>

class Voter
{
public:
	Voter();
	Voter(char* votes, int ID_par);

	//Accessors:
	int getID() const;
	char get_vote(char question) const;

private:
	int ID;
	char mayor;
	char prop17;
	char meas1;
	char meas2;
};

int count_lines(std::istream& is);

//-------------------------------------------------------------------
int main()
{
	//Testing class:
	/*{
		using namespace std;

		int testID = 4925;
		char testchoices[4] = { 'C', 'D', 'G', 'H' };
		Voter testvoter(testchoices, testID);
		cout << testvoter.getID() << endl;
		for (int i = 0; i < 4; i++)
			cout << testvoter.get_vote((i + 1) + '0');
	}*/

	std::ifstream is;
	//count votes first:
	is.open("votes.txt");
	if (is.fail())
		exit(1);
	int number_of_votes = count_lines(is);
	is.close();
	
	//then create appropriate array and read votes:
	Voter *a = new Voter[number_of_votes];
	is.open("votes.txt");
	if (is.fail())
		exit(1);
	for (int i = 0; i < number_of_votes; i++)
		read_next_vote(is, a[i]);

	//store percentages per question:
	double percentages[4];

	return 0;
}
//-------------------------------------------------------------------

int count_lines(std::istream& is)
{
	char next;
	int lines = 0;

	while (!is.eof())
	{
		is.get(next);
		if (next == '\n')
			lines++;
	}
	
	return lines;
}

//Voter class implementation:
Voter::Voter(){}
Voter::Voter(char votes[4], int ID_par)
{
	mayor = votes[0];
	prop17 = votes[1];
	meas1 = votes[2];
	meas2 = votes[3];
	ID = ID_par;
}

//Accessors implementation:
int Voter::getID() const
{
	return ID;
}
char Voter::get_vote(char question) const
{
	switch (question)
	{
	case '1':
		return mayor;
		break;
	case '2':
		return prop17;
		break;
	case '3':
		return meas1;
		break;
	case '4':
		return meas2;
		break;
	default:
		std::cout << "Question choice invalid.\n";
		return '\0';
	}
}


