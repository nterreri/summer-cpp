// ch10proj3.cpp : Defines the entry point for the console application.
/*Redefine CDAccount from Display 10.1 so that it is a class rather than a
structure.Use the same member variables as in Display 10.1 but make
them private.Include member functions for each of the following : one
to return the initial balance, one to return the balance at maturity, one
to return the interest rate, and one to return the term.Include a constructor
that sets all of the member variables to any specified values, as
well as a default constructor.Also, include an input member function
with one formal parameter of type istream and an output member function
with one formal parameter of type ostream.Embed your class definition
in a test program*/

#include "stdafx.h"
#include <iostream>

class CDAccount
{
public:
	//	Constructors
	CDAccount(double balance_par, double interestr_par, int term_par);
	CDAccount();

	//	I/O:
	void output_data(std::ostream& os = std::cout);
	void input_data(std::istream& is = std::cin);

	//	Accessors:
	double get_initial_balance();
	double get_mature_balance();
	double get_interestrate();
	int get_term();

private:
	double balance;
	double interest_rate;
	int term;
};

void newline(std::istream& is = std::cin);

int menu(CDAccount account);
//	Returns 0 upon the user inputting 'q', runs an otherwise endless loop over
//	a switch() to exemplify the use of the accessors in CDAccount

int main()
{
	// Testing constructors:

	CDAccount account1(2000.0, 1.5, 6);
	CDAccount account2;

	//	Testing input:

	account2.input_data();

	// Testing output:

	account1.output_data();
	account2.output_data();

	// Testing accessors:

	return menu(account2);
}

CDAccount::CDAccount(double balance_par, double interestr_par, int term_par)
{
	balance = balance_par;
	interest_rate = interestr_par;
	term = term_par;

	if (balance < 0)
	{
		std::cout << "Balance must be a positive value.\n";
		exit(1);
	}

	if (interest_rate < 0)
	{
		std::cout << "Interest rate must be a positive value.\n";
		exit(1);
	}
	
	if (term <= 0)
	{
		std::cout << "Term must be a non-zero positive integer.\n";
		exit(1);
	}
}

//	Default constructor
CDAccount::CDAccount()
{}

void CDAccount::input_data(std::istream& is)
{
	using namespace std;
	bool input_correct;

	cout << "Enter the CD account data.\n";

	do
	{
		input_correct = true;

		cout << "Enter the initial balance:\n";
		is >> balance;

		if (balance < 0 || !cin)
		{
			cout << "Error: balance must a positive value.\n";
			input_correct = false;
			cin.clear();
			newline();
		}

	} while (!input_correct);

	do
	{
		input_correct = true;

		cout << "Enter the interest rate:\n";
		is >> interest_rate;

		if (interest_rate < 0 || !cin)
		{
			cout << "Error: interest rate must a positive value.\n";
			input_correct = false;
			cin.clear();
			newline();
		}

	} while (!input_correct);

	do
	{
		input_correct = true;

		cout << "Enter the term:\n";
		is >> term;

		if (term <= 0 || !cin)
		{
			cout << "Error: term must a non-negative positive value.\n";
			input_correct = false;
			cin.clear();
			newline();
		}

	} while (!input_correct);

	
}

void newline(std::istream& is)
{
	char symbol;

	do
	{
		is.get(symbol);
	} while (symbol != '\n');
}

void CDAccount::output_data(std::ostream& os)
{
	using namespace std;

	os << "The initial account balance is: $" << balance << endl
		<< "The interest rate is: " << interest_rate << "%" << endl
		<< "The term lasts for: " << term << " month";
	
	//	Say months if term != 1, otherwise say month
	if (term != 1)
		os << "s";
	
	os << endl;
}

int menu(CDAccount account)
{
	using namespace std;
	char ans;

	while (true)
	{
		cout << "Enter 1 to test the balance accessor, 2 for the mature balance\n"
			<< "accessor, 3 for the interest rate accessor, 4 for the term accessor\n"
			<< "or \'q\' to quit the program:\n";
		
		cin >> ans;
		switch (ans)
		{
		case '1':
			cout << "The initial balance is: $" << account.get_initial_balance()
				<< endl;
			break;

		case '2':
			cout << "The mature balance is: $" << account.get_mature_balance()
				<< endl;
			break;

		case '3':
			cout << "The interest rate is: " << account.get_interestrate()
				<< "%" << endl;
			break;

		case '4':
			cout << "The term duration is: " << account.get_term() << " month";
			if (account.get_term() != 1)
				cout << "s";
			cout << endl;
			break;

		case 'q':
			cout << "Exiting program.\n";
			return 0;
			break;

		default:
			cout << "Input not recognized, try again.\n";
		}
		
		cout << endl;
	}
	

	
}

double CDAccount::get_initial_balance()
{
	return balance;
}

double CDAccount::get_mature_balance()
{
	return balance + (balance * (interest_rate / 100) * (term/12.0));
}

double CDAccount::get_interestrate()
{
	return interest_rate;
}

int CDAccount::get_term()
{
	return term;
}
