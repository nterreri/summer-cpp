// ch3proj7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char firstd, secondd, thirdd, fourthd;


	while (true)
	{
		cout << "Enter a number between 1000 and 3000,\n"
			<< "or enter \'STOP\' to quit the program:\n";
		cin >> firstd >> secondd >> thirdd >> fourthd;

		if (firstd == 'S' || firstd == 's')
			exit(0);
		
		if (firstd != '1' && firstd != '2' && firstd != '3')
		{
			cout << "Input invalid,\n"
				<< "try again.\n";
			continue;
		}
		

		switch (firstd)
		{
		case '1':
			cout << 'M';
			break;
		case '2':
			cout << "MM";
			break;
		case '3':
			cout << "MMM";
			break;
		default:
			cout << "Something went wrong.\n"
				<< "try again.\n";
			continue;
		}

		switch (secondd)
		{
		case '1':
			cout << "C";
			break;
		case '2':
			cout << "CC";
			break;
		case '3':
			cout << "CCC";
			break;
		case '4':
			cout << "CD";
			break;
		case '5':
			cout << "D";
			break;
		case '6':
			cout << "DC";
			break;
		case '7':
			cout << "DCC";
			break;
		case '8':
			cout << "DCCC";
			break;
		case '9':
			cout << "CM";
			break;
		case '0':
			break;
		default:
			cout << "Input invalid.\n";
			continue;
		}

		switch (thirdd)
		{
		case '1':
			cout << "X";
			break;
		case '2':
			cout << "XX";
			break;
		case '3':
			cout << "XXX";
			break;
		case '4':
			cout << "XL";
			break;
		case '5':
			cout << "L";
			break;
		case '6':
			cout << "LX";
			break;
		case '7':
			cout << "LXX";
			break;
		case '8':
			cout << "LXXX";
			break;
		case '9':
			cout << "XC";
			break;
		case '0':
			break;
		default:
			cout << "Input invalid.\n";
			continue;
		}

		switch (fourthd)
		{
		case '1':
			cout << "I";
			break;
		case '2':
			cout << "II";
			break;
		case '3':
			cout << "III";
			break;
		case '4':
			cout << "IV";
			break;
		case '5':
			cout << "V";
			break;
		case '6':
			cout << "VI";
			break;
		case '7':
			cout << "VII";
			break;
		case '8':
			cout << "VIII";
			break;
		case '9':
			cout << "IX";
			break;
		case '0':
			break;
		default:
			cout << "Input invalid.\n";
			continue;
		}

		cout << " is the number entered in Roman numerals.\n";
	}
	
	return 0;
}

