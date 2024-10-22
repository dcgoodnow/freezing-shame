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
   char * temp;
   temp = new char[30];
   card* dptr;
   dptr = load;

   //get file name for cards
   cout << "What is the name of the uno cards file?";
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
      unoDeck >> temp;
      (*dptr).color = *temp;

      unoDeck >> (*dptr).rank;

      delete[] (*dptr).location;
      (*dptr).location = new char[11];
      StringCopy("Unshuffled", (*dptr).location);
      dptr++;
   }

   //load in the fifth row (action cards)
   for(int i = 76; i < 100; i++)
   {
      unoDeck >> temp;
      (*dptr).color = *temp;

      unoDeck >> temp;
      (*dptr).action = new char[length(temp)];
      StringCopy(temp, (*dptr).action);
      delete[] (*dptr).location;
      (*dptr).location = new char[11];
      StringCopy("Unshuffled", (*dptr).location);
      dptr++;
   }

   //load in the sixth row (wild cards)
   for(int i = 100; i < 108; i++)
   {
      unoDeck >> temp;
      (*dptr).action = new char[length(temp)];
      StringCopy(temp, (*dptr).action);
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
      cout << (*dptr).color << '\t';
      cout << (*dptr).rank << '\t';
      cout << (*dptr).action << '\t' << '\t';
      cout << (*dptr).location << endl;
      dptr++;
   }
}

void StringCopy(const char* strA, char* strB) 
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
   card* tptr;
   card* uptr = unshuff;
   card* sptr = shuff;
   //copy all cards into shuffled deck
   for(int i = 0; i < 108; i++)
   {
      CopyCard(*uptr, *sptr);
      cout << "gothere";
      delete[] (*sptr).location;
      (*sptr).location = new char[9];
      StringCopy("Shuffled", (*sptr).location);
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
   
void InitializePlayer(player* init)
{
   for(int i = 0; i < 4; i++)
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
      init++;
   }
}

void LoadPlayers(player* list)
{
   char * temp;
   temp = new char[30];
   char idChar;
   ifstream players;
   //get filename
   cout << "What is the name of the player file? ";
   cin >> temp;
   char * filename;
   filename = new char[length(temp)];
   StringCopy(temp, filename);
   players.open(filename);
   delete[] filename;
   filename = NULL;

   for( int i = 0; i < 4; i++)
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
   cout << endl;
}

void DealCards(card* deck, card* disc, card* draw)
{
   card* cptr = deck;
   card* drptr = draw;
   for(int i = 0; i < 28; i++)
   {
      cptr++;  
   }
   //deal first discard card
   CopyCard(*cptr, *disc);
   delete[] (*disc).location;
   (*disc).location = new char[8];
   StringCopy("Discard", (*disc).location);
   cptr++;
   //move the remainder of cards to draw pile
   
   for( int i = 29; i < 108; i++)
   {
      CopyCard(*cptr, *drptr);
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

int length(char* string)
{
   int i = 0;
   while(*string != '\0')
   {
      string++;
    	i++;
   }
   return i+1;
}
