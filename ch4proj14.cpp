// ch4proj14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

double basal(double weight);
double activity(int intensity, double weight, int minutes);

int main()
{
	double w, food_calories, servings;
	int intensity, minutes;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	cout << "This program calculates how many servings of your favourite meal you can have\n"
		<< "in a day without gaining or losing weight (assuming you do not consume any more\n"
		<< "calories).\n";

	cout << endl;
	
	cout << "Enter your weight (in pounds): ";
	cin >> w;
	cout << "Enter the intensity of an activity: ";
	cin >> intensity;
	cout << "Enter the duration of the activity in minutes: ";
	cin >> minutes;
	cout << "Enter the calories in one serving of your favourite food: ";
	cin >> food_calories;

	servings = (basal(w) + activity(intensity, w, minutes)) / (food_calories /* 0.10*/);

	cout << endl;

	cout << "You can have at most " << servings << " servings of your favourite food a day\n"
		<< "(amounting to a total of " << servings * food_calories << " calories per day)\n"
		<< "without gaining weight (assuming you don't eat anything else, and the intensity\n"
		<< "estimation for the activity is accurate, which it probably isn't).\n";

	cout << endl;
	return 0;
}

double basal(double weight)
{
	return 70 * pow( (weight / 2.2), 0.756);
}

double activity(int intensity, double weight, int minutes)
{
	return 0.0385 * intensity * weight * minutes;
}