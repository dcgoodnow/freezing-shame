#include "uno.h"
#include "unoclass.h"
#include <iostream>
#include "string.h"
#include "list.h"
#include "stack.h"


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
   player tempPlayer;

   
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
   list<player> players;

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
            //print players 
            case '5':
            {
               PrintPlayers(players);
               break;
            }
            
            case '6':
            {
               DealCards(shuffled, discard, draw, players, numpl);
               break;
            }

            case '7':
            {
               players.gotoBeginning();
               for(int i = 0; i < numpl; i++)
               {
                  players.getCursor(tempPlayer);
                  tempPlayer.SortCardsColor();
                  players.replace(tempPlayer);
                  players.gotoNext();
               }
               break;
            }

            case '8':
            {
               players.gotoBeginning();
               for(int i = 0; i < numpl; i++)
               {
                  players.getCursor(tempPlayer);
                  tempPlayer.SortCardsRank();
                  players.replace(tempPlayer);
                  players.gotoNext();
               }
               break;
            }

            case '9':
            {
               players.gotoBeginning();
               for(int i = 0; i < numpl; i++)
               {
                  players.getCursor(tempPlayer);
                  tempPlayer.SortCardsRank();
                  players.replace(tempPlayer);
                  players.gotoNext();
               }
               players.gotoBeginning();
               for(int i = 0; i < numpl; i++)
               {
                  players.getCursor(tempPlayer);
                  tempPlayer.SortCardsColor();
                  players.replace(tempPlayer);
                  players.gotoNext();
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
   delete[] mainTemp;
   return 0;
}

