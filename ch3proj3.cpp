// ch3proj3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int d, m;
	char loopcontrol = 'y';
	string capricorn = " You may need to make some distinct mental adjustments in order to fit in with the energy of the day, Capricorn.\n Try to tune into these energies and see what kind of balance they can bring to your life.\n Be more mindful of your words and don't say things you don't really mean.\n Be genuine in all your interactions.\n",
		aquarius = " There's likely to be a bit of tension today regarding your position in society, Aquarius.\n Maybe you're running into issues that stem from your involvement in the collective versus your focus on your personal issues.\n Make sure these two aspects of your life are in balance. \nUnexpected things may pop out of the woodwork to keep you on your toes.\n", 
		pisces = " There's a bit of rigidity in the air today that might leave you feeling as if you're butting heads with everything you come in contact with, Pisces.\n Try not to get too bent out of shape if people disagree with your opinions.\n People need their space, and emotions will be operating at a fairly high level.\n Consider this during all your encounters.\n", 
		aries = " Your emotions may surprise you today as unexpected issues crop up out of nowhere, Aries.\n Take time to smooth the wrinkles in your current plan of attack regarding your involvement with the world.\n A self-centered approach will create barriers between you and those you wish get near.\n Consider how your actions affect those you love, and make any necessary adjustments in your approach.\n", 
		taurus = " You may wonder what all the fuss is about today, Taurus.\n People may be getting all worked up over nothing. Don't get absorbed in the melodrama.\n Set the record straight and bring out the truth as you see it.\n Don't let others hide behind façades, and don't do the same.\n It's important that everyone be aware of how you feel.\n", 
		gemini = " Today is a wonderful and productive day for you, Gemini.\n Don't hog the limelight. Let other people feel like they're being heard, too.\n You might get into trouble if your head gets too big or your attitude too stubborn.\n Opinions will be strong, so give people room to voice their own.\n They will appreciate your patience and tolerance.\n", 
		cancer = " Stand back and let someone else take the reins today, Cancer.\n Trust in others. There are many helpful hands out there to guide you.\n The most important thing is to let go and have confidence that others will direct you.\n They will if you let them. Your brain may buzz to the point that you feel you've lost control.\n Relax your mind and calm your nerves.\n", 
		leo = " You have quite the juggling act on your hands today, Leo.\n Things may fly at you from all directions, all demanding your attention. Give equal weight to your needs.\n You will be on an important road with a great deal of responsibility. Don't shy away from a starring role.\n You have the diplomacy and peaceful nature required to be a successful leader.\n", 
		virgo = " Tension may build today from all directions, Virgo.\n Everyone may seem to be operating as part of a great conspiracy against you. Don't get paranoid.\n This scenario is most likely far from the truth of the matter. Try to embrace change and don't treat it like an enemy.\n Outdated ways of doing things may get in the way of important progress toward success.\n", 
		libra = " Spread your ideas out to the world, Libra.\n Now is a great time to go on a long trip, or at least begin planning one.\n Explore the far reaches of your space, literally and figuratively. Join others who share a similar spiritual mission.\n By reaching out to new and different people, you can have some unforgettable experiences with the potential to have a positive impact on your life.\n", 
		scorpio = " Take time out to change the things in your life that need restoring, Scorpio.\n Explore your emotional needs and find ways to satisfy them. You may need to adopt a radically different approach in order to get where you need to go.\n Even if things seem unstable at first, they're likely to smooth out and be much more dependable eventually.\n Be an individual.\n", 
		sagittarius = " Today may be quite emotionally intense, Sagittarius.\n Your greatest gifts may get you into trouble on a day like this, but that doesn't mean you should stop being yourself for even one minute.\n There's a great deal of important information to exchange, so remain open to all opportunities and possibilities.\n Meet the world with open arms.\n";

	do
	{
		cout << "Enter your date of birth (day and month separated by a space; ex. 12 4):\n";
		cin >> d >> m;

		if (d < 0 || d > 31)
		{
			cout << "The number entered for the day is not a valid input.\n";
			continue;
		}

		switch (m)
		{
		case 1:
			if (d <= 19)
			{

				cout << "Capricorn\n"
					<< capricorn;
				
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";
				if (d > 17)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Aquarius\n"
					<< aquarius;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";



			}
			else
				cout << "Aquarius\n"
					<< aquarius;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";
				
			break;

		case 2:
			if (d <= 18)
			{

				cout << "Aquarius\n"
					<< aquarius;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";

				if (d > 16)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Pisces\n"
					<< pisces;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";

			}
			else
				cout << "Pisces\n"
					<< pisces;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";
			break;

		case 3:
			if (d <= 20)
			{

				cout << "Pisces\n"
					<< pisces;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";
				if (d > 18)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Aries\n"
					<< aries;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";

			}
			else
				cout << "Aries\n"
					<< aries;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";
			break;

		case 4:
			if (d <= 19)
			{

				cout << "Aries\n"
					<< aries;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";
				if (d > 17)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Taurus\n"
					<< taurus;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";

			}
			else
				cout << "Taurus\n"
				<< taurus;

			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";

			break;

		case 5:
			if (d <= 20)
			{

				cout << "Taurus\n"
					<< taurus;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";

				if (d > 18)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Gemini\n"
					<< gemini;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";

			}
			else
				cout << "Gemini\n"
				<< gemini;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";
			break;

		case 6:
			if (d <= 21)
			{

				cout << "Gemini\n"
					<< gemini;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";
				if (d > 19)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Cancer\n"
					<< cancer;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";

			}
			else
				cout << "Cancer\n"
				<< cancer;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";
			break;

		case 7:
			if (d <= 22)
			{

				cout << "Cancer\n"
					<< cancer;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";
				if (d > 20)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Leo\n"
					<< leo;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";

			}
			else
				cout << "Leo\n"
				<< leo;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";
			break;

		case 8:
			if (d <= 22)
			{

				cout << "Leo\n"
					<< leo;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";
				if (d > 20)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Virgo\n"
					<< virgo;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";

			}
			else
				cout << "Virgo\n"
				<< virgo;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";
			break;

		case 9:
			if (d <= 22)
			{

				cout << "Virgo\n"
					<< virgo;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";
				if (d > 20)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Libra\n"
					<< libra;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";
			}
			else
				cout << "Libra\n"
				<< libra;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";
			break;

		case 10:
			if (d <= 22)
			{

				cout << "Libra\n"
					<< libra;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Air: Gemini, Libra, Aquarius.\n";
				if (d > 20)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Scorpio\n"
					<< scorpio;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";

			}
			else
				cout << "Scorpio\n"
				<< scorpio;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";
			break;

		case 11:
			if (d <= 21)
			{

				cout << "Scorpio\n"
					<< scorpio;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Water: Cancer, Scorpio, Pisces.\n";
				if (d > 19)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Sagittarius\n"
					<< sagittarius;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";


			}
			else
				cout << "Sagittarius\n"
				<< sagittarius;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";

			break;

		case 12:
			if (d <= 21)
			{

				cout << "Sagittarius\n"
					<< sagittarius;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Fire: Aries, Leo, Sagittarius.\n";

				if (d > 19)
					cout << "The birthdate entered is on a cusp: it close to the "
					<< "Capricorn\n"
					<< capricorn;
				cout << "You are most comfortable with people of the same Element as your sign.\n"
					<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";

			}
			else
				cout << "Capricorn\n"
				<< capricorn;
			cout << "You are most comfortable with people of the same Element as your sign.\n"
				<< "Your sign belongs to the element of Earth: Taurus, Virgo, Capricorn.\n";
			break;

		default:
			cout << "The number entered for the month is not a valid input.\n";
			continue;
		}
		cout << "Type 'y', then press enter if you wish to ask for another date of birth,\n"
			<< "otherwise enter another letter:\n";
		cin >> loopcontrol;
	} while (loopcontrol == 'y');

	return 0;
}

