
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
#include <fstream>

using namespace std;

const int CARD_LENGTH = 25;

/***
	*Name: PrintMenu
	*Purpose: Prints user menu
	*Args: none
	*Retval: none, prints menu 
***/
void PrintMenu(); //foo

/**
  *Name: 	LoadDeck
  *Purpose:	loads unshuffled deck from a  file
  *Args: array for deck to be loaded into
  *Retval: loads array
*/
void LoadDeck(char unshuffledDeck[][25][CARD_LENGTH]);

int main()
{
   char unshuffled[5][25][CARD_LENGTH]; 
   char userResponse;
   //display user menu
   PrintMenu();

   //get user response
   cin >> userResponse;
   
      //respond to action
      switch(userResponse)
      {
         case '1':
	 {
            cout << "working";
	    break;
	 }

         //read in deck
         case '2':
	    {
               LoadDeck(unshuffled);
               cout << unshuffled[0][1];
	       break;
	    }

	 //shuffle deck
         case '3':
	 {
	    break;
	 }
      }

      cout << endl;
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

void LoadDeck(char unshuffledDeck[][25][CARD_LENGTH])
{
   //open file 
   ifstream unoDeck;
   unoDeck.open("cards.txt");
   
   for(int i = 0; i < 4; i++)
   {
      for( int j = 0; j < 25; j++)
      {
         unoDeck >> unshuffledDeck[i][j];
         unoDeck >> unshuffledDeck[i][j];
      }
   }
   for( int i = 0; i < 25; i++)
   {
      unoDeck >> unshuffledDeck[4][i];
   }
   unoDeck.close();
}
