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
   for(int i = 0; i<108; i++)
   {
      cout << i << '\t';
      deck[i].print();
   }
}

void ShuffleDeck(card* unshuff, card* shuff)
{
   //copy all cards into shuffled deck
   for(int i = 0; i < 108; i++)
   {
      unshuff[i].CopyCard(shuff[i]);
      shuff[i].SetLocation("Shuffled");
   }
   srand(time(NULL));
   card temp;
   int randA, randB;
   for(int i = 0; i < 1000; i++)
   {
      
      randA = rand()%108;
      randB = rand()%108;
      shuff[randA].CopyCard(temp);
      shuff[randB].CopyCard(shuff[randA]);
      temp.CopyCard(shuff[randB]);
   }
}

void WriteDeck(const card* deck, const char* filename)
{
   //open file
   ofstream shufDeck;
   shufDeck.open(filename);
   //write each card to a file
   for(int i = 0; i < 108; i++)
   {
      shufDeck << deck[i].GetColor() << '\t';
      shufDeck << deck[i].GetRank()<< '\t';
      shufDeck << deck[i].GetAction() << '\n';
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
   card* tempc = new card[7];
   card* home = tempc;
   for(int i = 0; i < numpl; i++)
   {
      for(int j = 0; j < 7; j++)
      {
         deck[i*7+j].CopyCard(*tempc);
         (*tempc).SetLocation(deck[i*7+j].GetLocation());
         tempc++;
      }
      tempc = home;
      players[i].SetHand(tempc);
   }
   tempc = home;
   delete[] tempc;
   tempc = NULL;

   //deal first discard card
   disc[0].CopyCard(deck[numpl*7]);
   disc[0].SetLocation("Discard");

   //move the remainder of cards to draw pile
   for( int i = numpl*7+1; i < 108; i++)
   {
      draw[i-(numpl*7+1)].CopyCard(deck[i]);

      //set new location
      draw[i-(numpl*7+1)].SetLocation("Draw");
   }
}

//determine how to stop sorting
card* SortCardsColor(card* toSort, int num)
{
   bool swapped = true;
   while(swapped)
   {
      swapped = false;
      for(int i = 0; i < num-1; i++)
      {
         if((toSort[i].GetColor()) > (toSort[i+1].GetColor()))
         {
            toSort[i].Swap(toSort[i+1]);
            swapped = true;
         }
      }
   }
   return toSort;
}
