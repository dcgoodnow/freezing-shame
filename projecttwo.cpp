
/*****************************************
 *Name: Daniel Goodnow
 *
 *
 *
 *Project two
 *
 *
 *
 *Last Updated: 9/6/2013
*****************************************/
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "time.h"

using namespace std;

const int CARD_LENGTH = 25;

struct card
{
   char color;
   int rank;
   char action[15];
   char location[20];
};


struct player
{
   char name[20];
   int id[5];
   card hand[7];
};

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
void LoadDeck(card load[108]);

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

void PrintDeck(card deck[108]);

/**
  *Name:    String Copy
  *Purpose: Copies one c-style string to another location
  *Args:    StrA (string to be copied), StrB (location to be copied to)
  *retval:  none
**/
void StringCopy(char strA[], char strB[]);

/**
  *Name:    Shuffle Deck
  *Purpose: moves the unshuffled deck to shuffled deck in random order
  *Args:    unshuffled deck (3-d char array), shuffled deck(2-d char array)
  *Retval:  moves shuffled deck into shuffled array by pointer
**/
void ShuffleDeck(char unshuff[5][25][CARD_LENGTH], 
                 char shuff[108][CARD_LENGTH]);

void ShuffleDeck(card unshuff[108], card shuff[108]);

/**
  *Name:    WriteDeck
  *Purpose: Writes shuffled deck to file
  *Args:    deck(2-d char array), file name (c-style string)
  *Retval:  none, creates and writes file for deck
**/
void WriteDeck(char deck[108][CARD_LENGTH], char filename[]);

void WriteDeck(card deck[108], char filename[]);

/**
  *Name:    Initialize Deck
  *Purpose: initializes deck to generic values
  *Args:    array of 108 cards
  *Retval:  none
**/
void InitializeDeck(card deck[108]);

/**
  *Name:    Initialize player
  *Purpose: initializes player to generic values
  *Args:    array of 4 players
  *Retval:  none
**/
void InitializePlayer(player init[4]);

int main()
{
   //char unshuffled[5][25][CARD_LENGTH]; 
   char userResponse;
   //char shuffled[108][CARD_LENGTH];
   bool running = true;
   card unshuffled[108];
   card shuffled[108];
   player players[4];
   InitializeDeck(unshuffled);
   InitializePlayer(players);

   
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

void LoadDeck(card load[108])
{
   char foo[10];
   char filename[40];

   //get file name for cards
   cout << "What is the name of the uno cards file?";
   cin >> filename;

   //open file 
   ifstream unoDeck;
   unoDeck.open(filename);
   
   //load in the first four rows (numbered cards)
   for(int i = 0; i < 76; i++)
   {
      unoDeck >> load[i].color;

      //dump the remaining characters of the color
      unoDeck >> foo;
      unoDeck >> load[i].rank;
   }

   //load in the fifth row (action cards)
   for(int i = 76; i < 100; i++)
   {
      unoDeck >> load[i].color;
      
      //dump the remaining characters of the color
      unoDeck >> foo;
      unoDeck >> load[i].action;
   }

   //load in the sixth row (wild cards)
   for(int i = 100; i < 108; i++)
   {
      unoDeck >> load[i].action;
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

void PrintDeck(card deck[108])
{
   for(int i = 0; i<108; i++)
   {
      cout << i << '\t';
      cout << deck[i].color << '\t';
      cout << deck[i].rank << '\t';
      cout << deck[i].action << '\t' << '\t';
      cout << deck[i].location << endl;
   }
}

void StringCopy(char strA[], char strB[]) 
{
   int i = 0;
   while(strA[i] != '\0')
   {
      strB[i] = strA[i];
      i++;
   }
   strB[i] = '\0';  //null-terminated
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

void ShuffleDeck(card unshuff[108], card shuff[108])
{
   char shuffstr[9] = "shuffled";
   InitializeDeck(shuff);
   srand(time(NULL));

   for(int i = 0; i < 108; i++)
   {
      bool good = true;
      //find an empty slot
      while(good)
      {
         int temp = rand()%108;

         //if the slot is empty, transfer the current cards location to the empty slot
         if(shuff[temp].location[0] == 'l' )
         {
            shuff[temp].color = unshuff[i].color;
            shuff[temp].rank = unshuff[i].rank;
            StringCopy(unshuff[i].action, shuff[temp].action);
            StringCopy(shuffstr, shuff[temp].location);
            good = false;     //move to the next card
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

void WriteDeck(card deck[108], char filename[])
{
   ofstream shufDeck;
   shufDeck.open(filename);
   for(int i = 0; i < 108; i++)
   {
      shufDeck << deck[i].color << '\t';
      shufDeck << deck[i].rank << '\t';
      shufDeck << deck[i].action << '\n';
   }
}

void InitializeDeck(card deck[108])
{
   char action[7] = "action";
   char location[9] = "location";
   //initialize values for each card
   for( int i = 0; i < 108; i++)
   {
      deck[i].color = 'c';
      deck[i].rank = -1;
      StringCopy(action, deck[i].action);
      StringCopy(location, deck[i].location);
   }
}
   
void InitializePlayer(player init[4])
{
   for(int i = 0; i < 4; i++)
   {
      //initialize player id to 00000
      for(int j = 0; j < 5; j++)
      {
         init[i].id[j] = 0;
      }
   }
}
