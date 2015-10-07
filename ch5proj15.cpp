// ch5proj15.cpp : Defines the entry point for the console application.
//Program to simulate duel

#include "stdafx.h"
#include <random>
#include <iostream>
using namespace std;

void shoot(bool& targetAlive, double accuracy);
//prec: parameters are initialized
//postc: generates a number between 0 and 1, if accuracy > this number
//targetAlive is set to false, otherwise it is not changed

int startDuel(bool aliveAaron, double accuracyAaron, bool aliveBob, double accuracyBob,
	bool aliveCharlie, double accuracyCharlie);
//prec: uses void shoot(bool&, double), first version of startDuel()
//returns 0 if Aaron won, 1 if Bob won, 2 if Charlie won

int startDuel(bool aliveAaron, double accuracyAaron, bool aliveBob, double accuracyBob,
	bool aliveCharlie, double accuracyCharlie, char dummy);
//prec: uses void shoot(bool&, double), the dummy variable overloads to activate
//the second version where Aaron misses his first shot intentionally
//returns 0 if Aaron won, 1 if Bob won, 2 if Charlie won

int main()
{
	bool Aaron = true, Bob = true, Charlie = true;
	double accuracyA = (1.0 / 3.0), accuracyB = 0.5, accuracyC = 1;
	int victor;//winner is returned as a number by startDuel()
	double aCounter = 0;
	double bCounter = 0;
	double cCounter = 0;//counters for the number of victories for each contestant
	char overload = 'o', quit; //under visual studio, it is necessary to initialize
	//the overload variable, even though its value is irrelevant

	cout << "In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument over\n"
		<< "which one of them was the greatest puzzler of all time. To end the argument\n"
		<< "once and for all, they agreed on a duel to the death. Aaron is a poor shooter\n"
		<< "and only hits his target with a probability of 1 / 3. Bob is a bit better and\n"
		<< "hits his target with a probability of 1 / 2. Charlie is an expert marksman and\n"
		<< "never misses. A hit means a kill and the person hit drops out of the duel.\n"
		<< "To compensate for the inequities in their marksmanship skills, it is\n"
		<< "decided that the contestants would fire in turns starting with Aaron, \n"
		<< "followed by Bob, and then by Charlie. The cycle would repeat until there\n"
		<< "was one man standing. And that man would be remembered as the\n"
		<< "greatest puzzler of all time.\n";

	cout << endl;

	for (int i = 0; i < 1000; i++)//simulation loop
	{
		Aaron = Bob = Charlie = true;
		victor = startDuel(Aaron, accuracyA, Bob, accuracyB, Charlie, accuracyC);
	
		if (victor == 0)
			aCounter++;
		else if (victor == 1)
			bCounter++;
		else if (victor == 2)
			cCounter++;
	}

	cout << "Following the strategy of shooting the most accurate shooter\n"
		<< "on their turn, we can see that Bob is the most likely to win:\n";
	
	cout << endl;
	
	cout << "Probability of Aaron winning: " << aCounter / 10 << endl
		<< "Probability of Bob winning: " << bCounter / 10 << endl
		<< "Probability of Charlie winning: " << cCounter / 10 << endl;

	cout << endl;

	for (int i = 0; i < 1000; i++)//second simulation loop
	{
		Aaron = Bob = Charlie = true;
		victor = startDuel(Aaron, accuracyA, Bob, accuracyB, Charlie, accuracyC, overload);

		if (victor == 0)
			aCounter++;
		else if (victor == 1)
			bCounter++;
		else if (victor == 2)
			cCounter++;
	}

	cout << "Following the same strategy as before, but having Aaron miss his first\n"
		<< "shot intentionally, we can see that Aaron becomes the most likely to win.\n"
		<< "This is because the strategy guarantees that he will survive the first round.\n";

	cout << endl;

	cout << "Probability of Aaron winning: " << aCounter / 10 << endl
		<< "Probability of Bob winning: " << bCounter / 10 << endl
		<< "Probability of Charlie winning: " << cCounter / 10 << endl;

	cout << endl;

	cout << "Press any key, then press enter to quit:\n";
	cin >> quit;
	return 0;
}

void shoot(bool& targetAlive, double accuracy)
{
	random_device rd;
	mt19937_64 eng(rd());
	uniform_real_distribution<> distr(0, 1);

	double hit_chance = (distr(eng));
	
	if (hit_chance < accuracy)
		targetAlive = false;
}

//original strategy: everybody shoots at the most skilled shooter still alive
int startDuel(bool aliveAaron, double accuracyAaron, bool aliveBob, double accuracyBob,
	bool aliveCharlie, double accuracyCharlie)
{
	int contestants = 3;
	while (contestants > 1)
	{
		if (aliveAaron && aliveCharlie)//shooting
			shoot(aliveCharlie, accuracyAaron);
		else if (aliveAaron && aliveBob)
			shoot(aliveBob, accuracyAaron);

		if (aliveBob && aliveCharlie)
			shoot(aliveCharlie, accuracyBob);
		else if (aliveBob && aliveAaron)
			shoot(aliveAaron, accuracyBob);

		if (aliveCharlie && aliveBob)
			shoot(aliveBob, accuracyCharlie);
		else if (aliveCharlie && aliveAaron)
			shoot(aliveAaron, accuracyCharlie);

		contestants = 0;//counting who is still alive
		if (aliveCharlie)
			contestants++;
		if (aliveBob)
			contestants++;
		if (aliveAaron)
			contestants++;
	}//loop exits at contestants == 1

	if (aliveAaron && !aliveBob && !aliveCharlie)//deciding which one survived
		return 0;
	else if (!aliveAaron && aliveBob && !aliveCharlie)
		return 1;
	else if (!aliveAaron && !aliveBob && aliveCharlie)
		return 2;
	else 
		return 99;
}

//Second strategy: Aaron misses his first shot intentionally
int startDuel(bool aliveAaron, double accuracyAaron, bool aliveBob, double accuracyBob,
	bool aliveCharlie, double accuracyCharlie, char dummy)
{
	int contestants = 3;
	double accuracyAaronStorage = accuracyAaron;

	for (int i = 0; contestants > 1; i++)
	{
		if (i == 0)//Aaron missing his first shot
			accuracyAaron = 0;
		else
			accuracyAaron = accuracyAaronStorage;


		if (aliveAaron && aliveCharlie)//shooting
			shoot(aliveCharlie, accuracyAaron);
		else if (aliveAaron && aliveBob)
			shoot(aliveBob, accuracyAaron);

		if (aliveBob && aliveCharlie)
			shoot(aliveCharlie, accuracyBob);
		else if (aliveBob && aliveAaron)
			shoot(aliveAaron, accuracyBob);

		if (aliveCharlie && aliveBob)
			shoot(aliveBob, accuracyCharlie);
		else if (aliveCharlie && aliveAaron)
			shoot(aliveAaron, accuracyCharlie);

		contestants = 0;//counting who is still alive
		if (aliveCharlie)
			contestants++;
		if (aliveBob)
			contestants++;
		if (aliveAaron)
			contestants++;
	}//loop exits when contestants == 1

	if (aliveAaron && !aliveBob && !aliveCharlie)//then checks which one it is
		return 0;
	else if (!aliveAaron && aliveBob && !aliveCharlie)
		return 1;
	else if (!aliveAaron && !aliveBob && aliveCharlie)
		return 2;
	else
		return 99;
}

// void shoot() driver program:
/*int main()
{
bool living = true;
double bob_accuracy = 0.5;

while (true)
{
living = true;
shoot(living, 0.5);
}

return 0;
}*/

//driver function for startDuel()
/*int main()
{
bool Aaron = true, Bob = true, Charlie = true;
double accuracyA = (1.0 / 3.0), accuracyB = 0.5, accuracyC = 1;

int victor = 98;

victor = startDuel(Aaron, accuracyA, Bob, accuracyB, Charlie, accuracyC);
}*/