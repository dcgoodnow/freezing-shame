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


/***
	*Name: PrintMenu
	*Purpose: Prints user menu
	*Args: none
	*Retval: none, prints menu 
***/
void PrintMenu();

int main()
{
	char userResponse;
	//display user menu
	PrintMenu();
	//get user response
	std::cin >> userResponse;
	//respond to action

		//read in deck

		//shuffle deck

		//print deck

	return 0;
}

/***
	*Name: PrintMenu
	*Purpose: Prints user menu
	*Args: none
	*Retval: none, prints menu 
***/
void PrintMenu()
{
	std::cout << "Welcome to Uno Shuffler!" << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Shuffle the deck" << std::endl;
	std::cout << "2. Print unshuffled deck" << std::endl;
	std::cout << "3. Write shuffled deck to file" << std::endl;
}

