#include "uno.h"
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include "string.h"
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
   char * temp;
   temp = new char[30];
   card* dptr;
   dptr = load;

   //get file name for cards
   cout << "What is the name of the uno cards file? ";
   cin >> temp;
   char * fileName;
   fileName = new char[length(temp)];
   StringCopy(temp, fileName);
   //open file 
   ifstream unoDeck;
   unoDeck.open(fileName);
   delete [] fileName;
   fileName = NULL;
   
   //load in the first four rows (numbered cards)
   for(int i = 0; i < 76; i++)
   {
      //load color
      unoDeck >> temp;
      (*dptr).color = *temp;

      //load rank
      unoDeck >> (*dptr).rank;

      //delete previous location array and create new properly sized array
      delete[] (*dptr).location;
      (*dptr).location = new char[11];
      StringCopy("Unshuffled", (*dptr).location);
      //move to next card
      dptr++;
   }

   //load in the fifth row (action cards)
   for(int i = 76; i < 100; i++)
   {
      //load color
      unoDeck >> temp;
      (*dptr).color = *temp;

      //load action
      unoDeck >> temp;
      (*dptr).action = new char[length(temp)];
      StringCopy(temp, (*dptr).action);

      //delete old location and load new location
      delete[] (*dptr).location;
      (*dptr).location = new char[11];
      StringCopy("Unshuffled", (*dptr).location);
      dptr++;
   }

   //load in the sixth row (wild cards)
   for(int i = 100; i < 108; i++)
   {
      //load action
      unoDeck >> temp;
      (*dptr).action = new char[length(temp)];
      StringCopy(temp, (*dptr).action);
      //load new location
      delete[] (*dptr).location;
      (*dptr).location = new char[11];
      StringCopy("Unshuffled", (*dptr).location);
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
      PrintCard(*dptr);
      dptr++;
   }
}

void ShuffleDeck(card* unshuff, card* shuff)
{
   card* tptr;
   card* uptr = unshuff;
   card* sptr = shuff;
   //copy all cards into shuffled deck
   for(int i = 0; i < 108; i++)
   {
      CopyCard(*uptr, *sptr);
      delete[] (*sptr).location;
      (*sptr).location = new char[9];
      StringCopy("Shuffled", (*sptr).location);
      uptr++;
      sptr++;
   }
   srand(time(NULL));
   card temp;
   temp.action = new char[6];
   StringCopy("action", temp.action);
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
   }
}

void WriteDeck(card* deck, char* filename)
{
   //open file
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
   //initialize values for each card
   for( int i = 0; i < 108; i++)
   {
      (*deck).color = 'c';
      (*deck).rank = -1;
      (*deck).action = new char[6];
      (*deck).location = new char[9];
      StringCopy("Action", (*deck).action);
      StringCopy("Location", (*deck).location);
      deck++;
   }
}

void InitializeHand(card* hand)
{
   //initialize values for each card
   for( int i = 0; i < 7; i++)
   {
      (*hand).color = 'c';
      (*hand).rank = -1;
      (*hand).action = new char[6];
      (*hand).location = new char[9];
      StringCopy("Action", (*hand).action);
      StringCopy("Location", (*hand).location);
      hand++;
   }
}
   
void InitializePlayer(player* init, int num)
{
   for(int i = 0; i < num; i++)
   {
      (*init).name = NULL;
      //initialize player id to 00000
      (*init).id = new int[5];
      int * iptr = (*init).id;
      for(int j = 0; j < 5; j++)
      {
         *iptr = 0;
         iptr++;
      }
      //initialize hand
      (*init).hand = new card[7];
      InitializeHand((*init).hand);

      init++;
   }
}

void LoadPlayers(player* list, ifstream &players, int numplayers)
{
   char * temp;
   temp = new char[30];
   char idChar;

   for( int i = 0; i < numplayers; i++)
   {
      //get player name
      players >> temp;
      (*list).name = new char[length(temp)];
      StringCopy(temp, (*list).name);
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
   cout << endl << endl;

   //Print hand
   cout << "Hand" << endl << "==========================================" << endl;
   card* temp = toPrint.hand;
   for(int i = 0; i < 7; i++)
   {
      PrintCard(*temp);
      temp++;
   }
   cout << endl << endl;
}

void DealCards(card* deck, card* disc, card* draw, player* players, int numpl)
{
   card* cptr = deck;
   card* drptr = draw;
   player* pptr = players;
   card* hptr;
   for(int i = 0; i < 7; i++)
   {
      pptr = players;
      for(int j = 0; j < numpl; j++)
      {
         hptr = (*pptr).hand;
         for(int k = 0; k < i; k++)
            hptr++;
         CopyCard(*cptr, *hptr);
         delete[] (*hptr).location;

         //change location to players name
         (*hptr).location = new char[length((*pptr).name)];
         StringCopy((*pptr).name, (*hptr).location);

         pptr++;
         cptr++;
      }
   }
   //deal first discard card
   CopyCard(*cptr, *disc);
   delete[] (*disc).location;
   (*disc).location = new char[8];
   StringCopy("Discard", (*disc).location);
   cptr++;

   //move the remainder of cards to draw pile
   for( int i = numpl*7+1; i < 108; i++)
   {
      CopyCard(*cptr, *drptr);

      //set new location
      delete[] (*drptr).location;
      (*drptr).location = new char[5];
      StringCopy("Draw", (*drptr).location);

      cptr++;
      drptr++;
   }
}

void CopyCard(card origin, card &dest)
{
   //copy all aspects of the card
   dest.color = origin.color;
   dest.rank = origin.rank;
   delete[] dest.action;
   dest.action = new char[20];
   StringCopy(origin.action, dest.action);
}


void DeleteDeck(card* deck)
{
   card *dptr = deck;
   for(int i = 0; i < 108; i++)
   {
      delete[] (*deck).action;
      (*deck).action = NULL;
      delete[] (*deck).location;
      (*deck).location = NULL;
      dptr++;
   }
}

void DeletePlayers(player* list, int num)
{
   player *pptr = list;
   for(int i = 0; i < num; i++)
   {
      delete[] (*pptr).name;
      (*pptr).name = NULL;
      delete[] (*pptr).id;
      (*pptr).id = NULL;
      card *dptr = (*pptr).hand;

      //delete hand
      for(int j = 0; j < 7; j++)
      {
         delete[] (*dptr).action;
         (*dptr).action = NULL;
         delete[] (*dptr).location;
         (*dptr).location = NULL;
         dptr++;
      }
      delete[] (*pptr).hand;
      pptr++;
   }
   
}

void PrintCard(card c)
{
      cout << c.color << '\t';
      cout << c.rank << '\t';
      cout << c.action << '\t' << '\t';
      cout << c.location << endl;
}


