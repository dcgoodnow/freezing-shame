
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
#include "stdlib.h"
#include "time.h"

using namespace std;

const int CARD_LENGTH = 25;

/**
  *Name: PrintMenu
  *Purpose: Prints user menu
  *Args: none
  *Retval: none, prints menu 
**/
void PrintMenu(); 

/**
  *Name:    LoadDeck
  *Purpose: loads unshuffled deck from a  file
  *Args:    array for deck to be loaded into
  *Retval:  loads array
**/
void LoadDeck(char unshuffledDeck[5][25][CARD_LENGTH]);

/**
  *Name:    Print Deck
  *Purpose: prints deck of cards
  *Args:    array for deck (3-d)
  *retval:  none, prints deck to screen
**/
void PrintDeck(char unshuffledDeck[5][25][CARD_LENGTH]);


/**
  *Name:    Print Deck
  *Purpose: prints deck of cards
  *Args:    array for deck (2-d)
  *retval:  none, prints deck to screen
**/
void PrintDeck(char shuffledDeck[108][CARD_LENGTH]);

/**
  *Name:    String Copy
  *Purpose: Copies one c-style string to another location
  *Args:    StrA (string to be copied), StrB (location to be copied to)
  *retval:  none
**/
void StringCopy(char* strA, char* strB);

/**
  *Name:    Shuffle Deck
  *Purpose: moves the unshuffled deck to shuffled deck in random order
  *Args:    unshuffled deck (3-d char array), shuffled deck(2-d char array)
  *Retval:  moves shuffled deck into shuffled array by pointer
**/
void ShuffleDeck(char unshuff[5][25][CARD_LENGTH], 
                 char shuff[108][CARD_LENGTH]);

/**
  *Name:    WriteDeck
  *Purpose: Writes shuffled deck to file
  *Args:    deck(2-d char array), file name (c-style string)
  *Retval:  none, creates and writes file for deck
**/
void WriteDeck(char deck[108][CARD_LENGTH], char filename[]);

int main()
{
   char unshuffled[5][25][CARD_LENGTH]; 
   char userResponse;
   char shuffled[108][CARD_LENGTH];
   bool running = true;
   
   //Load deck
   LoadDeck(unshuffled);

   //loop continuously until quit command ('q')
   while(running)
   {
      //display user menu
      PrintMenu();

      //get user response
      cin >> userResponse;
      
         //respond to action
         switch(userResponse)
         {
            //Shuffle Deck
            case '1':
            {
               ShuffleDeck(unshuffled, shuffled);
               break;
            }

            //Print Unshuffled Deck
            case '2':
            {
               PrintDeck(unshuffled);
               break;
            }

            //Write shuffled deck to file
            case '3':
            {
               char name[30];
               cout <<"What would you like to name the file?" << endl; 
               cin  >> name;
               WriteDeck(shuffled, name);
               break;
            }
            
            //quit
            case 'q':
            {
               running = false;
               break;
            }
         }

   }
   return 0;
}

void PrintMenu()
{
   cout << "Welcome to Uno Shuffler!" << endl;
   cout << "What would you like to do?" << endl;
   cout << "1. Shuffle the deck" << endl;
   cout << "2. Print unshuffled deck" << endl;
   cout << "3. Write shuffled deck to file" << endl;
   cout << "Enter q to quit the program" <<endl;
        
}

void LoadDeck(char unshuffledDeck[5][25][CARD_LENGTH])
{
   char temp[10];
   char filename[40];
   //get file name for cards
   cout << "What is the name of the uno cards file?";
   cin >> filename;
   //open file 
   ifstream unoDeck;
   unoDeck.open(filename);
   
   //loop through first 4 rows of cards
   for(int i = 0; i < 4; i++)
   {
      for( int j = 0; j < 25; j++)
      {
         unoDeck >> unshuffledDeck[i][j];       //input first word
         int k = 0;
         while(unshuffledDeck[i][j][k] != '\0') //find end of first word
         {
            k++;
         }
         unshuffledDeck[i][j][k] = ' ';         //insert space between words
         k++;

         //input second word
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
   //loop through last row of cards
   for( int i = 0; i < 8; i++)
   {
      unoDeck >> unshuffledDeck[4][i];
   }

   unoDeck.close();
}

void PrintDeck(char unshuffledDeck[5][25][CARD_LENGTH])
{
   //loop through colored cards
   for(int i = 0;i < 4; i++)
   {
      for(int j=0; j< 25; j++)
      {
         cout << i*25 + j+1 << "   ";
         cout << unshuffledDeck[i][j];
         cout << endl; 
      }
   }

   //loop through wild cards
   for(int i = 0; i < 8; i++)
   {
      cout << 101 + i << "   ";
      cout << unshuffledDeck[4][i];
      cout << endl;
   }

}

void PrintDeck(char shuffledDeck[108][CARD_LENGTH])
{
   //loop through all cards
   for( int i = 0; i < 108; i++)
   {
      cout << i+1 << "   ";
      cout << shuffledDeck[i];
      cout << endl;
   }
}

void StringCopy(char* strA, char* strB) 
{
   //parse string until null character
   while(*strA != '\0')
   {
      *strB = *strA;
      strB++;
      strA++;
   }
   *strB = '\0';  //null-terminated
}

void ShuffleDeck(char unshuff[5][25][CARD_LENGTH], 
                 char shuff[108][CARD_LENGTH])
{
   //initialize shuffled deck to 0
   for(int i = 0; i < 108; i++)
   {
      for(int j = 0; j < CARD_LENGTH; j++)
      {
         shuff[i][j] = '0';
      }
   }
   //seed random number generator
   srand(time(NULL));

   //shuffle colored cards
   for(int i = 0; i < 4; i++)
   {
      for(int j = 0; j < 25; j++)
      {
         //loop until an empty slot is found
         bool good = true;
         while(good)
         {
            int temp = rand()%108;
            if(shuff[temp][0] == '0')
            {
               StringCopy(unshuff[i][j], shuff[temp]); //copy to empty slot
               good = false;
            }
         }
      }
   }
   
   //shuffled wild cards
   for(int i = 0; i < 8; i++)
   {
      bool good = true;
      while(good)
      {
         int temp = rand()%108;
         if(shuff[temp][0] == '0')
         {
            StringCopy(unshuff[4][i], shuff[temp]);
            good = false;
         }
      }
   }

}

void WriteDeck(char deck[108][CARD_LENGTH], char filename[])
{
   ofstream shufDeck;
   shufDeck.open(filename);

   //loop through all cards and print with a preceding number
   for(int i = 0; i < 108; i++)
   {
      shufDeck << i+1 << "   ";
      shufDeck << deck[i];
      shufDeck << endl;
   }
   shufDeck.close();

   
}

