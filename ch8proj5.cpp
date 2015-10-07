// ch8proj5.cpp : Defines the entry point for the console application.
// Program to replace any 4 letter word with "love".

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

void process_word(char word[]);
void process_word(std::string word);

void output_word(char word[]);
void output_word(std::string word);

int main()
{
	std::cout << "This program replaces any four-letter word with\n"
		<< "the word \"love\".\n" << std::endl;

	//char word[50];
	std::string parola;
	char loopcontrol;

	do
	{
		//process_word(word);
		process_word(parola);

		std::cout << std::endl;

		std::cout << "If you would like to enter another line\n"
			<< "press \'y\' then press enter:\n";
		std::cin >> loopcontrol;

	} while (loopcontrol == 'y' || loopcontrol == 'Y');
	
	return 0;
}

// c-string version. VS refused to compile it.
void process_word(char word[])
{
	using namespace std;

	char next;
	cin.get(next);
	while (next != '\n')
	{
		cin.putback(next);
		cin >> word;

		if (strlen(word) == 4)
		//	strcpy(word, "love"); //presumably, this would have worked,
								// but visual studio 2013 considers it deprecated
								// and an error to use it, therefore it will not
								// compile this source
		
		output_word(word);

		cin.get(next);
	}


}

// string version
void process_word(std::string word)
{
	using namespace std;

	cout << "Enter a line of words:\n";

	char next;
	cin.get(next);
	while (next != '\n')
	{
		cin.putback(next);
		cin >> word;

		if (word.length() == 4 &&
			(isalpha(word[0]) && isalpha(word[3])))
		{
			if (isupper(word[0]))
				word = "Love";
			else
				word = "love";
		}
		else if (word.length() == 5)
		{
			if (!isalpha(word[0]))
			{
				if (isupper(word[1]))
				{
					string buffer = "Love";
					word = static_cast<char>(word[0]) + buffer;
				}
				else
				{
					string buffer = "love";
					word = static_cast<char>(word[0]) + buffer;
				}
			}
			else if (!isalpha(word[4]))
			{
				if (isupper(word[0]))
				{
					string buffer = "Love";
					word = buffer + static_cast<char>(word[4]);
				}
				else
				{
					string buffer = "love";
					word = buffer + word[4];
				}
			}
		}

		output_word(word);

		cin.get(next);
	}


}


void output_word(char word[])
{
	using namespace std;
	
	cout << word << " ";
}

void output_word(std::string word)
{
	using namespace std;

	cout << word << " ";
}