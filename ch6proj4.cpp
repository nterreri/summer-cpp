// ch6proj4.cpp : Defines the entry point for the console application.
//Program to compute average and standard deviation of from a file containing only
//real numbers

#include "stdafx.h"
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const string IFILE = "c:\\Users\\salpo\\documents\\visual studio 2013\\Projects\\ch6proj4\\ch6proj4\\Text.txt";

void compute_average(double& average, int& total_elements_in_input_file);
//prec: uses fstream
//postc: initialized reference parameters

double return_deviation(double average, int total_elements_in_input_file);
//prec: parameter initialized, uses fstream and cmath
//returns standard deviation

int main()
{
	double avg, stdeviation;
	int n;

	cout << "This program computes and displays the average and the standard\n"
		<< "deviation of the elements of a file containing only real numbers\n"
		<< "and nothing else.\n"
		<< "The targeted file is specified in a constant in its source code.\n"
		<< endl;

	compute_average(avg, n);
	stdeviation = return_deviation(avg, n);

	cout << "The average is: " << avg << endl
		<< "The standard deviation is: " << stdeviation << endl;

	return 0;
}

void compute_average(double& avg, int& n)
{
	using namespace std;

	ifstream input;
	double sum = 0;
	double next;

	input.open(IFILE);
	if (input.fail())
	{ 
		cout << "Failed to open file.\n" << endl;
		exit(1);
	}

	int counting = 0;
	for (; input >> next; counting++)
		sum += next;

	input.close();

	avg = sum / counting;
	n = counting;
}

double return_deviation(double avg,int n)
{
	using namespace std;

	ifstream input;
	double sum = 0;
	double next;

	input.open(IFILE);
	if (input.fail())
	{
		cout << "Failed to access input file.\n" << endl;
		exit(1);
	}

	while (input >> next)
		sum += (next - avg) * (next - avg);

	input.close();

	return sqrt(sum / n);
}