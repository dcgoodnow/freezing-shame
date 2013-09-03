/*****************************************
 *Name: Daniel Goodnow
 *
 *
 *
 *Project One: Deck Shuffling
 *
 *
 *
 *Last Updated: 8/30/13
*****************************************/
#include <iostream>

using namespace std


/***
	*Name: PrintMenu
	*Purpose: Prints user menu
	*Args: none
	*Retval: none, prints menu 
***/
void PrintMenu();

/**
  *Name: 	LoadDeck
  *Purpose:	loads unshuffled deck from a  file
  *Args: array for deck to be loaded into
  *Retval: loads array
*/
void LoadDeck(unshuffledDeck[]);

int main()
{
	char userResponse;
	//display user menu
	PrintMenu();

	//get user response
	std::cin >> userResponse;

	//respond to action
	switch(userResponse)
	{
		case('1')
		{
			break;
		}

		//read in deck
		case('2')
		{
			break;
		}

		//shuffle deck
		case('3')
		{
			break;
		}

		//print deck

	return 0;
}

void PrintMenu()
{
	cout << "Welcome to Uno Shuffler!" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Shuffle the deck" << endl;
	cout << "2. Print unshuffled deck" << endl;
	cout << "3. Write shuffled deck to file" << endl;
}

void LoadDeck(unshuffledDeck[])
{
	
}
