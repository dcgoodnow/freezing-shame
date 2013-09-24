
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
   card * unshuffled;
   unshuffled = new card [108];
   card * shuffled;
   shuffled = new card[108];
   card * discard;
   discard = new card[108];
   card * draw;
   draw = new card[108];
   player * players;
   players = new player[4];
   char * mainTemp;
   mainTemp = new char[30];
   InitializeDeck(unshuffled);
   InitializeDeck(shuffled);
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
            
            case '3':
            {
               PrintDeck(shuffled);
               break;
            }

            //Write shuffled deck to file
            case '4':
            {
               char * name;
               cout <<"What would you like to name the file?" << endl; 
               cin  >> mainTemp;
               name = new char[length(mainTemp)];
               StringCopy(mainTemp, name);
               WriteDeck(shuffled, name);
               break;
            }
            
            case '5':
            {
               player *pptr = players;
               for(int i = 0; i < 4; i ++)
               {
                  PrintPlayer(*pptr);
                  pptr++;
               }
               break;
            }
            
            case '6':
            {
               DealCards(shuffled, discard, draw);
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

