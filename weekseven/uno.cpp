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
   int tempint;

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
      (*dptr).SetColor(*temp);

      //load rank
      unoDeck >> tempint;
      (*dptr).SetRank(tempint);

      //delete previous location array and create new properly sized array
      (*dptr).SetLocation("Unshuffled");
      //move to next card
      dptr++;
   }

   //load in the fifth row (action cards)
   for(int i = 76; i < 100; i++)
   {
      //load color
      unoDeck >> temp;
      (*dptr).SetColor(*temp);

      //load action
      unoDeck >> temp;
      (*dptr).SetAction(temp);

      //delete old location and load new location
      (*dptr).SetLocation("Unshuffled");
      dptr++;
   }

   //load in the sixth row (wild cards)
   for(int i = 100; i < 108; i++)
   {
      //load action
      unoDeck >> temp;
      (*dptr).SetAction(temp);
      //load new location
      (*dptr).SetLocation("Unshuffled");
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
      (*dptr).print();
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
      (*uptr).CopyCard(*sptr);
      (*sptr).SetLocation("Shuffled");
      uptr++;
      sptr++;
   }
   srand(time(NULL));
   card temp;
   temp.init();
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
      (*sptr).CopyCard(temp);
      (*tptr).CopyCard(*sptr);
      temp.CopyCard(*tptr);
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
      shufDeck << (*deck).GetColor() << '\t';
      shufDeck << (*deck).GetRank()<< '\t';
      shufDeck << (*deck).GetAction() << '\n';
      deck++;
   }
}

void InitializeDeck(card* deck)
{
   //initialize values for each card
   for( int i = 0; i < 108; i++)
   {
      (*deck).init();
      deck++;
   }
}
   
void InitializePlayer(player* init, int num)
{
   player* pptr = init;
   for(int i = 0; i < num; i++)
   {
      (*pptr).init();
      pptr++;
   }
}

void LoadPlayers(player* list, ifstream &players, int numplayers)
{
   char * temp;
   temp = new char[30];
   char idChar;
   int* iptr;
   iptr = new int[5];
   int* home = iptr;
   for( int i = 0; i < numplayers; i++)
   {
      //get player name
      players >> temp;
      (*list).SetName(temp);
      for( int j = 0; j < 5; j ++)
      {
         //load each integer into temporary character
         players >> idChar;
         //convert to integer, store in array
         *iptr = idChar-48;
         iptr++;
      }
      iptr = home;
      (*list).SetID(iptr);
      list++;
   }
}

void DealCards(card* deck, card* disc, card* draw, player* players, int numpl)
{
   card* cptr = deck;
   card* drptr = draw;
   player* pptr = players;
   card* hptr;
   pptr = players;
   card* tempc = new card[7];
   card* home = tempc;
   for(int i = 0; i < 7; i++)
   {
      (*tempc).init();
      tempc++;
   }
   tempc = home;
   for(int i = 0; i < numpl; i++)
   {
      for(int j = 0; j < 7; j++)
      {
         (*cptr).CopyCard(*tempc);
         (*tempc).SetLocation((*cptr).GetLocation());
         tempc++;
         cptr++;
      }
      tempc = home;
      (*pptr).SetHand(tempc);
      pptr++;
   }
   for(int i = 0; i < 7; i++)
   {
      (*tempc).del();
      tempc++;
   }
   tempc = home;
   delete[] tempc;
   //deal first discard card
   (*disc).CopyCard(*cptr);
   (*disc).SetLocation("Discard");
   cptr++;

   //move the remainder of cards to draw pile
   for( int i = numpl*7+1; i < 108; i++)
   {
      (*drptr).CopyCard(*cptr);

      //set new location
      (*drptr).SetLocation("Draw");
      
      cptr++;
      drptr++;
   }
}

void DeleteDeck(card* deck)
{
   card *dptr = deck;
   for(int i = 0; i < 108; i++)
   {
      (*dptr).del();
      dptr++;
   }
}

void DeletePlayers(player* list, int num)
{
   player *pptr = list;
   for(int i = 0; i < num; i++)
   {
      (*pptr).del();
      pptr++;
   }
}
