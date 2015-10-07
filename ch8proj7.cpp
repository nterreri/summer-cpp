// ch8proj7.cpp : Defines the entry point for the console application.
// Program to suggest gender-neutral rewording of pronouns.

#include "stdafx.h"
#include <iostream>
#include <string>

std::string input();
//Reads one line from keyboard, returns the line read.
//Uses iostream and string.

std::string make_gender_neutral(std::string line);
//Makes a copy of line then goes through it one word at a time
//and replaces masculine English pronouns with neutral ones
//("they", "them", etc.).
//Returns this edited line.
//Uses skip_blanks(), process_next_word(), get_next_word_length_from_index(),
//and eradicate_toxic_masculinity() and skip_ahead().

void skip_blanks(std::string line, int& index);
//Skips blanks and punctuation from index "index" until the next
//non-blank non-punctuation character. Moves index forward accordingly.

void process_next_word(std::string& line, int& i);
//Gets the length of the next word in line from index i.
//Replaces masculine pronouns where opportune.
//Uses string and get_next_word_length_from_index() and 
//eradicate_toxic_masculinity() and skip_ahead().

void skip_ahead(int& index, int length);
//Shifts index "index" forward by length.

unsigned int get_next_word_length_from_index(std::string line, int index);
//Returns the length of the next word from index "index" in line.
//Uses string.

void eradicate_toxic_masculinity(std::string& line, int index,
	unsigned int word_length);
//Checks every word in line and replaces masculine pronouns with gender neutral
//ones.
//Uses string.

//main:
int main()
{
	std::cout << "This program suggests some edits to a user-input line\n"
		<< "of text, to make it more gender-neutral.\n" << std::endl;
	
	std::string line;
	std::string gender_neutral_line;
	char loopcontrol;

	do
	{
		line = input();
		gender_neutral_line = make_gender_neutral(line);

		std::cout << gender_neutral_line << std::endl;

		std::cout << "If you would like to quit press \'q\' then press\n"
			<< "enter, otherwise press enter to try another line:\n";
		std::cin.get(loopcontrol);
	} while (loopcontrol != 'q' || loopcontrol != 'Q');
	

	return 0;
}

std::string input()
{
	using namespace std;
	string line;

	cout << "Enter the line to be edited:\n";
	getline(cin, line);

	return line;
}

std::string make_gender_neutral(std::string line)
{
	std::string line_edited = line;

	int i = 0;//	word start index

	for (; i < line_edited.length(); i++)
	{
		skip_blanks(line_edited, i);
		process_next_word(line_edited, i);
	}
	

	return line_edited;
}

void skip_blanks(std::string line, int& index)
{
	char next = line[index];
	while (next == ' ' || next == '\t' || next == '\n' ||
		next == '.' || next == ':' || next == ',' || next == ';' ||
		next == '?' || next == '!')

		next = line[++index];
}

void process_next_word(std::string& line, int& i)
{
	
	unsigned int length;

	length = get_next_word_length_from_index(line, i);
	
	eradicate_toxic_masculinity(line, i, length);
	
	skip_ahead(i, length);
}

void skip_ahead(int& index, int length)
{
	index = index + length;
}

unsigned int get_next_word_length_from_index(std::string line, int index)
{
	unsigned int n = index;//	word end index, see make_gender_neutral(string) above

	while (n < (line.length())
		&&
		(line[n] != ' ' && line[n] != '\t' &&
		line[n] != '\n' && line[n] != '.' &&
		line[n] != ':' && line[n] != ',' &&
		line[n] != ';' && line[n] != '?' &&
		line[n] != '!'))
	{
		n++;
	}

	return n - index;
}

void eradicate_toxic_masculinity(std::string& line, int index,
	unsigned int word_length)
{
	std::string word;

	word = line.substr(index, word_length);
	if (word == "he")
	{
		line.erase(index, word_length);
		line.insert(index, "they");
	}
	else if (word == "him")
	{
		line.erase(index, word_length);
		line.insert(index, "them");
	}
	else if (word == "his")
	{
		line.erase(index, word_length);
		line.insert(index, "their");
	}
	else if (word == "He")
	{
		line.erase(index, word_length);
		line.insert(index, "They");
	}
	else if (word == "Him")
	{
		line.erase(index, word_length);
		line.insert(index, "Them");
	}
	else if (word == "His")
	{
		line.erase(index, word_length);
		line.insert(index, "Their");
	}
}