
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

/**
  *Name:    Print Deck
  *Purpose: prints deck of cards
  *Args:    array for deck (3-d)
  *retval:  none, prints deck to screen
**/
void PrintDeck(char unshuffledDeck[][25][CARD_LENGTH]);

/**
  *Name:    String Copy
  *Purpose: Copies one c-style string to another location
  *Args:    StrA (string to be copied), StrB (location to be copied to)
  *retval:  none
**/
void StringCopy(char* strA, char* strB);

int main()
{
   char unshuffled[5][25][CARD_LENGTH]; 
   char userResponse;
   char test1[10]= "Hello";
   char test2[10];
   //display user menu
   PrintMenu();
   StringCopy(test1, test2);
   cout << test2;

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
               PrintDeck(unshuffled);
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
   char temp[10];
   //open file 
   ifstream unoDeck;
   unoDeck.open("cards.txt");
   
   for(int i = 0; i < 4; i++)
   {
      for( int j = 0; j < 25; j++)
      {
         unoDeck >> unshuffledDeck[i][j];
         int k = 0;
         while(unshuffledDeck[i][j][k] != '\0')
         {
            k++;
         }
         unoDeck >> unshuffledDeck[i][j][k];
         k++;
         while(unoDeck.peek() != ' ' && unoDeck.peek() != '\r' )
         {
            unoDeck >> unshuffledDeck[i][j][k];
            k++;
         }
         unshuffledDeck[i][j][k] = '\0';

      }
   }
   for( int i = 0; i < 8; i++)
   {
      unoDeck >> unshuffledDeck[4][i];
   }
   unoDeck.close();
}

void PrintDeck(char unshuffledDeck[][25][CARD_LENGTH])
{
   for(int i = 0;i < 4; i++)
   {
      for(int j=0; j< 25; j++)
      {
         cout << i*25 + j+1 << "   ";
         cout << unshuffledDeck[i][j];
         cout << endl; 
      }
   }
   for(int i = 0; i < 8; i++)
   {
      cout << 101 + i << "   ";
      cout << unshuffledDeck[4][i];
      cout << endl;
   }
}
void StringCopy(char* strA, char* strB) 
{
   while(*strA != '\0')
   {
      *strB = *strA;
      strB++;
      strA++;
   }
   *strB = '\0';
}

