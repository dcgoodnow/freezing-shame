#include <iostream>
#include "string.h"
#include "list.h"
#include "unoclass.h"
#include <fstream>
#include "list.cpp"
#include "stdlib.h"

using namespace std;

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
      cout << randA << endl;
      shuff.enqueue(temp);
   }
   unshuff.remove(temp);
   cout << temp;
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

void LoadPlayers(queue<player>& list, ifstream& players, int numplayers)
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
      list.enqueue(tempP);
   }
}

int main()
{
   list<card> unshuffled;
   unshuffled = LoadDeck(unshuffled);
   PrintDeck(unshuffled);
   unshuffled.gotoBeginning();
   card temp;
   unshuffled.getCursor(temp);
   queue<card> shuffled;
   ShuffleDeck(unshuffled, shuffled);
   PrintDeck(shuffled);
   WriteDeck(shuffled, "foo");
   queue<player> players;
   ifstream inPlayers;
   inPlayers.open("players.txt");
   //LoadPlayers(players, inPlayers, 6);
   player test;
   players.enqueue(test);  
   return 0;
}
