#include "uno.h"
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include <fstream>
using namespace std;
void PrintMenu()
{
   cout << "======================================" << endl;
   cout << "Welcome to Uno Shuffler!" << endl;
   cout << "What would you like to do?" << endl;
   cout << "1. Shuffle the deck" << endl;
   cout << "2. Print unshuffled deck" << endl;
   cout << "3. Print shuffled deck" << endl;
   cout << "4. Write shuffled deck to file" << endl;
   cout << "5. Print players to screen" << endl;
   cout << "6. Deal shuffled cards" << endl;
   cout << "7. Sort players hands by color" << endl;
   cout << "8. Sort players hands by rank" << endl;
   cout << "9. Sort players hands by color and rank" << endl;
   cout << "Enter q to quit the program" <<endl;
}

void LoadDeck(card* load)
{
   char * temp;
   temp = new char[30];

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
   card test;

   for(int i = 0; i < 108; i++)
   {
      unoDeck >> load[i];
   }
   unoDeck.close();
   return;
}

void PrintDeck(card* deck)
{
   for(int i = 0; i<108; i++)
   {
      cout << i << '\t';
      cout << deck[i];
   }
}

void ShuffleDeck(card* unshuff, card* shuff)
{
   //copy all cards into shuffled deck
   for(int i = 0; i < 108; i++)
   {
      shuff[i].copyCard(unshuff[i]);
      shuff[i].setLocation("Shuffled");
   }
   srand(time(NULL));
   card temp;
   int randA, randB;
   for(int i = 0; i < 1000; i++)
   {
      
      randA = rand()%108;
      randB = rand()%108;
      temp.copyCard(shuff[randA]);
      shuff[randA].copyCard(shuff[randB]);
      shuff[randB].copyCard(temp);
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
      shufDeck << deck[i].getColor() << '\t';
      shufDeck << deck[i].getRank()<< '\t';
      shufDeck << deck[i].getAction() << '\n';
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
      (*list).setName(temp);
      for( int j = 0; j < 5; j ++)
      {
         //load each integer into temporary character
         players >> idChar;
         //convert to integer, store in array
         *iptr = idChar-48;
         iptr++;
      }
      iptr = home;
      (*list).setID(iptr);
      list++;
   }
}

void DealCards(card* deck, card* disc, card* draw, player* players, int numpl)
{
   card* tempc = new card[7];
   for(int i = 0; i < numpl; i++)
   {
      for(int j = 0; j < 7; j++)
      {
         tempc[j].copyCard(deck[i*7+j]);
         tempc[j].setLocation(deck[i*7+j].getLocation());
      }
      players[i].setHand(tempc);
   }
   delete[] tempc;
   tempc = NULL;

   //deal first discard card
   disc[0].copyCard(deck[numpl*7]);
   disc[0].setLocation("Discard");

   //move the remainder of cards to draw pile
   for( int i = numpl*7+1; i < 108; i++)
   {
      draw[i-(numpl*7+1)].copyCard(deck[i]);

      //set new location
      draw[i-(numpl*7+1)].setLocation("Draw");
   }
}

card* SortCardsColor(card* toSort, int num)
{
   bool swapped = true;
   while(swapped)
   {
      swapped = false;
      for(int i = 0; i < num-1; i++)
      {
         if(toSort[i] > toSort[i+1])
         {
            toSort[i].Swap(toSort[i+1]);
            swapped = true;
         }
      }
   }
   return toSort;
}

card* SortCardsRank(card* toSort, int num)
{
   bool swapped = true;
   while(swapped)
   {
      swapped = false;
      for(int i = 0; i < num-1; i++)
      {
         if((toSort[i].getRank()) > (toSort[i+1].getRank()))
         {
            toSort[i].Swap(toSort[i+1]);
            swapped = true;
         }
      }
   }
   return toSort;
}
