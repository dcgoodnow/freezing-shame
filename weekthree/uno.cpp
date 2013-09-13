#include "uno.h"
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include <fstream>
using namespace std;
void PrintMenu()
{
   cout << "Welcome to Uno Shuffler!" << endl;
   cout << "What would you like to do?" << endl;
   cout << "1. Shuffle the deck" << endl;
   cout << "2. Print unshuffled deck" << endl;
   cout << "3. Write shuffled deck to file" << endl;
   cout << "4. Deal shuffled cards" << endl;
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

void WriteDeck(card deck[108], char filename[])
{
   ofstream shufDeck;
   shufDeck.open(filename);
   //write each card to a file
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

void LoadPlayers(player list[4])
{
   char filename[30];
   char idChar;
   ifstream players;
   //get filename
   cout << "What is the name of the player file? ";
   cin >> filename;

   players.open(filename);

   for( int i = 0; i < 4; i++)
   {
      //get player name
      players >> list[i].name;
      for( int j = 0; j < 5; j ++)
      {
         //load each integer into temporary character
         players >> idChar;
         //convert to integer, store in array
         list[i].id[j]= idChar-48;
      }
   }
}

void PrintPlayer(player toPrint)
{
   cout << "Name: " << toPrint.name << endl;
   cout << "ID:   ";
   //print ID character by character
   for(int i = 0; i < 5; i++)
   {
      cout << toPrint.id[i];
   }
   cout << endl;
   //print each card in the hand
   for(int i = 0; i < 7; i ++)
   {
      cout << i << '\t';
      cout << toPrint.hand[i].color << '\t';
      cout << toPrint.hand[i].rank << '\t';
      cout << toPrint.hand[i].action << '\t' << '\t';
      cout << toPrint.hand[i].location << endl;
   }
}

void DealCards(card deck[108], player hands[4], card disc[108], card draw[108])
{
   //deal hands
   for(int i = 0; i < 7; i++)
   {
      for(int j = 0; j<4; j++)
      {
         CopyCard(deck[i*4+j], hands[j].hand[i]);
      }
   }
   //deal first discard card
   CopyCard(deck[28], disc[0]);
   //move the remainder of cards to draw pile
   for( int i = 29; i < 108; i++)
   {
      CopyCard(deck[i], draw[i-29]);
   }
}

void CopyCard(card origin, card &dest)
{
   //copy all aspects of the card
   dest.color = origin.color;
   dest.rank = origin.rank;
   StringCopy(origin.action, dest.action);
}
