
/*****************************************
 *Name: Daniel Goodnow
 *
 *
 *
 *Project two
 *
 *
 *
 *Last Updated: 9/11/2013
*****************************************/
#include "uno.h"
#include <iostream>
#include "string.h"
#include "list.h"
#include "stack.h"
#include "queue.h"


using namespace std;

int main()
{
   //initialize objects and vars
   char userResponse;
   bool running = true;
   list<card> unshuffled;
   queue<card> shuffled;
   queue<card> draw;
   stack<card> discard;
   char * mainTemp;
   mainTemp = new char[30];

   
   //Load deck
   LoadDeck(unshuffled);
   //get filename
   cout << "What is the name of the player file? ";
   cin >> mainTemp;
   //Load players
   ifstream pfile;
   pfile.open(mainTemp);
   int numpl;
   
   //get amount of players
   do
   {
      cout << "How many players are there? ";
      cin >> numpl;

      //check for within normal range
      if(numpl >= 10 || numpl <= 2)
         cout << endl << "Number out of range, please try again" << endl;
   }while(numpl >= 10 && numpl <= 2);

   //initialize player objects
   player * players;
   players = new player[numpl];

   //load players
   LoadPlayers( players, pfile, numpl);
   pfile.close();

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
            
            //print deck
            case '3':
            {
               PrintDeck(shuffled);
               break;
            }

            //Write shuffled deck to file
            case '4':
            {
               cout <<"What would you like to name the file?" << endl; 
               cin  >> mainTemp;
               WriteDeck(shuffled, mainTemp);
               break;
            }
            
            case '5':
            {
               for(int i = 0; i < numpl; i ++)
               {
                  cout << players[i];
               }
               break;
            }
            
            case '6':
            {
               DealCards(shuffled, discard, draw, players, numpl);
               break;
            }

            case '7':
            {
               for(int i = 0; i < numpl; i++)
               {
                  SortCardsColor(players[i].getHand(), 7);
               }
               break;
            }

            case '8':
            {
               for(int i = 0; i < numpl; i++)
               {
                  SortCardsRank(players[i].getHand(), 7);
               }
               break;
            }

            case '9':
            {
               for(int i = 0; i < numpl; i++)
               {
                  SortCardsRank(players[i].getHand(), 7);
               }
               for(int i = 0; i < numpl; i++)
               {
                  SortCardsColor(players[i].getHand(), 7);
               }
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
   delete[] unshuffled;
   delete[] shuffled;
   delete[] discard;
   delete[] draw;
   delete[] players;
   delete[] mainTemp;
   return 0;
}

