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
   cout << "3. Print shuffled deck" << endl;
   cout << "4. Write shuffled deck to file" << endl;
   cout << "5. Print players to screen" << endl;
   cout << "6. Deal shuffled cards" << endl;
   cout << "Enter q to quit the program" <<endl;
        
}

void LoadDeck(card* load)
{
   char foo[10];
   char filename[40];
   card* dptr;
   dptr = load;

   //get file name for cards
   cout << "What is the name of the uno cards file?";
   cin >> filename;

   //open file 
   ifstream unoDeck;
   unoDeck.open(filename);
   
   //load in the first four rows (numbered cards)
   for(int i = 0; i < 76; i++)
   {
      unoDeck >> (*dptr).color;

      //dump the remaining characters of the color
      unoDeck >> foo;
      unoDeck >> (*dptr).rank;
      dptr++;
   }

   //load in the fifth row (action cards)
   for(int i = 76; i < 100; i++)
   {
      unoDeck >> (*dptr).color;
      
      //dump the remaining characters of the color
      unoDeck >> foo;
      unoDeck >> (*dptr).action;
      dptr++;
   }

   //load in the sixth row (wild cards)
   for(int i = 100; i < 108; i++)
   {
      unoDeck >> (*dptr).action;
      dptr++;
   }
   

   unoDeck.close();
   return;
}

void PrintDeck(card* deck)
{
   card* dptr;
   dptr = deck;
   for(int i = 0; i<108; i++)
   {
      cout << i << '\t';
      cout << (*dptr).color << '\t';
      cout << (*dptr).rank << '\t';
      cout << (*dptr).action << '\t' << '\t';
      cout << (*dptr).location << endl;
      dptr++;
   }
}

void StringCopy(char* strA, char* strB) 
{
   while(*strA != '\0')
   {
      *strB = *strA;
      strA++;
      strB++;
   }
   *strB = '\0';  //null-terminated
}

void ShuffleDeck(card* unshuff, card* shuff)
{
   char shufname[10] = "shuffled";
   card* tptr;
   card* uptr = unshuff;
   card* sptr = shuff;
   //copy all cards into shuffled deck
   for(int i = 0; i < 108; i++)
   {
      CopyCard(*uptr, *sptr);
      uptr++;
      sptr++;
   }
   srand(time(NULL));
   card temp;
   int randtemp;
   for(int i = 0; i < 1000; i++)
   {
      sptr = shuff;
      tptr = shuff;
      randtemp = rand()%108;
      for(int j = 0; j < (rand()%108); j++)
      {
         sptr++;   
      }
      randtemp = rand()%108;
      for(int j = 0; j < randtemp; j++)
      {
         tptr++;   
      }
      CopyCard(*sptr, temp);
      CopyCard(*tptr, *sptr);
      CopyCard(temp, *tptr);
      StringCopy(shufname, (*sptr).location);
      StringCopy(shufname, (*tptr).location);
   }
}

void WriteDeck(card* deck, char* filename)
{
   ofstream shufDeck;
   shufDeck.open(filename);
   //write each card to a file
   for(int i = 0; i < 108; i++)
   {
      shufDeck << (*deck).color << '\t';
      shufDeck << (*deck).rank << '\t';
      shufDeck << (*deck).action << '\n';
      deck++;
   }
}

void InitializeDeck(card* deck)
{
   char action[7] = "action";
   char location[9] = "location";
   //initialize values for each card
   for( int i = 0; i < 108; i++)
   {
      (*deck).color = 'c';
      (*deck).rank = -1;
      StringCopy(action, (*deck).action);
      StringCopy(location, (*deck).location);
      deck++;
   }
}
   
void InitializePlayer(player* init)
{
   for(int i = 0; i < 4; i++)
   {
      //initialize player id to 00000
      int* iptr = (*init).id;
      for(int j = 0; j < 5; j++)
      {
         iptr = 0;
         iptr++;
      }
      init++;
   }
}

void LoadPlayers(player* list)
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
      players >> (*list).name;
      int* iptr = (*list).id;
      for( int j = 0; j < 5; j ++)
      {
         //load each integer into temporary character
         players >> idChar;
         //convert to integer, store in array
         *iptr = idChar-48;
         iptr++;
      }
      list++;
   }
}

void PrintPlayer(player toPrint)
{
   cout << "Name: " << toPrint.name << endl;
   cout << "ID:   ";
   //print ID character by character
   int* iptr = toPrint.id;
   for(int i = 0; i < 5; i++)
   {
      cout << *iptr;
      iptr++;
   }
   cout << endl;
}

void DealCards(card* deck, card* disc, card* draw)
{
   char discName[10] = "discard";
   char drawName[5] = "draw";
   card* cptr = deck;
   card* drptr = draw;
   for(int i = 0; i < 28; i++)
   {
      cptr++;  
   }
   //deal first discard card
   CopyCard(*cptr, *disc);
   StringCopy(discName, (*disc).location);
   cptr++;
   //move the remainder of cards to draw pile
   
   for( int i = 29; i < 108; i++)
   {
      CopyCard(*cptr, *drptr);
      StringCopy(drawName, (*drptr).location);
      cptr++;
      drptr++;
   }
}

void CopyCard(card origin, card &dest)
{
   //copy all aspects of the card
   dest.color = origin.color;
   dest.rank = origin.rank;
   StringCopy(origin.action, dest.action);
}

