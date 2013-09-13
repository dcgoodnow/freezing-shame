
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
#include <iostream>
#include "uno.h"

using namespace std;

int main()
{
   char userResponse;
   bool running = true;
   card unshuffled[108];
   card shuffled[108];
   card discard[108];
   card draw[108];
   player players[4];
   InitializeDeck(unshuffled);
   InitializeDeck(discard);
   InitializeDeck(draw);
   InitializePlayer(players);

   
   //Load deck
   LoadDeck(unshuffled);
   LoadPlayers( players );

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

            //Write shuffled deck to file
            case '3':
            {
               char name[30];
               cout <<"What would you like to name the file?" << endl; 
               cin  >> name;
               WriteDeck(shuffled, name);
               break;
            }
            
            case '4':
            {
               DealCards(shuffled, players, discard, draw);
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
   return 0;
}

