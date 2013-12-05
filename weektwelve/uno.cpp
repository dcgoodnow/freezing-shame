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

list<card> LoadDeck(list<card>& load)
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
   card def;
   card tempC;

   for(int i = 0; i < 108; i++)
   {
      tempC = def;
      unoDeck >> tempC;
      load.insertAfter(tempC);
   }
   unoDeck.close();
   return load;
}

const void PrintDeck(list<card>& deck)
{
   deck.gotoBeginning();
   card temp;
   for(int i = 0; i<108; i++)
   {
      cout << i+1 << '\t';
      deck.getCursor(temp);
      cout << temp;
      deck.gotoNext();
   }
}

const void PrintDeck(queue<card> deck)
{
   queue<card> tempD = deck;
   card temp;
   int i = 0;
   while(!tempD.empty())
   {
      cout << ++i << '\t';
      tempD.dequeue(temp);
      cout << temp;
   }
}

void ShuffleDeck(list<card>& unshuff, queue<card>& shuff)
{
   srand(time(NULL));
   card temp;
   int randA;
   for(int i = 107; i > 0; i--)
   {
      randA = rand()%(i+1);
      //if(randA == 0)
       //  randA = 1;
      unshuff.gotoBeginning();
      for(int j = 0; j < randA; j++)
      {
         if(!unshuff.gotoNext())
         {
            unshuff.gotoBeginning();
         }
      }
      unshuff.remove(temp);
      shuff.enqueue(temp);
   }
   unshuff.remove(temp);
   shuff.enqueue(temp);
}

void WriteDeck(const queue<card>& deck, const char* filename)
{
   queue<card> tempD = deck;
   //open file
   ofstream shufDeck;
   shufDeck.open(filename);
   card temp;
   //write each card to a file
   for(int i = 0; i < 108; i++)
   {
      tempD.dequeue(temp);
      shufDeck << i+1 << '\t';
      shufDeck << temp.getColor() << '\t';
      shufDeck << temp.getRank()<< '\t';
      shufDeck << temp.getAction() << '\n';
   }
}

void LoadPlayers(list<player>& roster, ifstream& players, int numplayers)
{
   char * temp;
   temp = new char[30];
   char idChar;
   int* iptr;
   iptr = new int[5];
   int* home = iptr;
   player tempP;
   for( int i = 0; i < numplayers; i++)
   {
      //get player name
      players >> temp;
      tempP.setName(temp);
      for( int j = 0; j < 5; j ++)
      {
         //load each integer into temporary character
         players >> idChar;
         //convert to integer, store in array
         *iptr = idChar-48;
         iptr++;
      }
      iptr = home;
      tempP.setID(iptr);
      roster.insertAfter(tempP);
   }
}

void PrintPlayers(list<player> roster ) const
{
   player temp;
   roster.gotoBeginning();
   roster.getCursor(temp);
   cout << temp;
   while(roster.gotoNext())
   {
      roster.getCursor(temp);
      cout << temp;
   }
}

void DealCards(queue<card> deck,stack<card>& disc, queue<card>& draw, list<player>& roster, int numpl)
{
   player tempP;
   card tempC;
   roster.gotoBeginning();
   for(int i = 0; i < numpl; i++)
   {
      roster.getCursor(tempP);
      for(int j = 0; j < 7; j++)
      {
         deck.dequeue(tempC);
         tempP.addCard(tempC);
      }
      cout << tempP;
      roster.replace(tempP);
      roster.gotoNext();
   }

   //deal first discard card
   deck.dequeue(tempC);
   disc.push(tempC);

   //move the remainder of cards to draw pile
   draw = deck;
}
