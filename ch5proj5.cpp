// ch5proj5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void compute_coin(int coin_value, int& number, int& amount_left);
//Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
//Postcondition: number has been set equal to the maximum number of coins
//denomination coin_value cents that can be obtained from amount_left
//amount_left has been decreased by the value of the coins, that is,
//decreased by number*coin_value.

void output(int coin_value, int number, int original_input);
//prec: computing loop is iterating and number, coin_value have been initialized
//postc: current iteration information is printed to screen

int main()
{
	int coin_value, number = 0, amount_left, original_input;
	char loopcontrol;

	cout << "This program tells you the coins you need to make up\n"
		<< "a user-input total amounting to less than one " << static_cast<unsigned const char>(156) << "."
		<< endl;

	cout << endl;
	
	do
	{
		cout << "Enter the number of pence (less than one " << static_cast<unsigned const char>(156) << "):\n";
		cin >> original_input;
		
		amount_left = original_input;
		while (amount_left > 0)
		{

			if (amount_left / 25 != 0)
				coin_value = 25;
			else if (amount_left / 10 != 0)
				coin_value = 10;
			else
				coin_value = 1;
				
			compute_coin(coin_value, number, amount_left);
			output(coin_value, number, original_input);
		}
		cout << "\n"
			<< "is what you need to make "
			<< original_input;
		if (original_input != 1)
			cout << " pennies.\n";
		else
			cout << " penny.\n";

		cout << "If you would like to repeat the calculation enter \'y\'\n"
			<< "otherwise enter something else.\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y' || loopcontrol == 'Y');
	return 0;
}

void compute_coin(int coin_value, int& number, int& amount_left)
{
	while (amount_left / coin_value != 0)
	{
		number = amount_left / coin_value;
		amount_left -= number * coin_value;
	}
}

void output(int coin_value, int number, int original_input)
{
	if (number != 0)
	{
		std::cout << number;
		if (coin_value == 25)
		{
			std::cout << " quarter";
			if (number != 1)
				std::cout << "s";
			std::cout << " ";
		}
		else if (coin_value == 10)
		{
			std::cout << " dime";
			if (number != 1)
				std::cout << "s";
			std::cout << " ";
		}
		else if (coin_value == 1)
		{
			if (number == 1)
				std::cout << " penny";
			else
				std::cout << " pence";
		}
	}
}