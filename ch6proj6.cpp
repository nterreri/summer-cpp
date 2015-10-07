// ch6proj6.cpp : Defines the entry point for the console application.
//Program to "neaten" a file by swapping every double occurrence of the ' ' character with a single occurrence

#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void neaten_file(ifstream& file_read, ofstream& file_neaten);
//prec: fstream variables opened different files, uses fstream
//postc: file_neaten is identical to file_read except every double space is corrected to a single space.

int main()
{
	ifstream messy;
	ofstream neat;

	messy.open("messy.dat");
	if (messy.fail())
	{
		cout << "Failed to open input file.\n" << endl;
		exit(1);
	}

	neat.open("neat.dat");
	if (neat.fail())
	{
		cout << "Failed to open output file.\n" << endl;
		exit(1);
	}

	neaten_file(messy, neat);
	messy.close();
	neat.close();

	cout << "Neatened file in \"neat.dat\".\n" << endl;
	return 0;
}

void neaten_file(ifstream& istream, ofstream& ostream)
{
	char next;

	while (istream.get(next))
	{
		ostream.put(next);
		if (next == ' ')
		{
			istream.get(next);
			if (next == ' ')
				continue;
			else
				ostream.put(next);
		}
	}
}