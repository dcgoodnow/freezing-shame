
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
#include <fstream>
#include "uno.h"
#include "string.h"

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
   char * mainTemp;
   mainTemp = new char[30];
   InitializeDeck(unshuffled);
   InitializeDeck(shuffled);
   InitializeDeck(discard);
   InitializeDeck(draw);

   
   //Load deck
   LoadDeck(unshuffled);
   //get filename
   cout << "What is the name of the player file? ";
   cin >> mainTemp;
   char * filename;
   filename = new char[length(mainTemp)];
   StringCopy(mainTemp, filename);
   //Load players
   ifstream pfile;
   pfile.open(filename);
   delete[] filename;
   filename = NULL;
   int numpl;
   pfile >> numpl;
   player * players;
   players = new player[numpl];
   InitializePlayer(players, numpl);
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
               for(int i = 0; i < numpl; i ++)
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
   DeleteDeck(unshuffled);
   DeleteDeck(shuffled);
   DeleteDeck(discard);
   DeleteDeck(draw);
   delete[] unshuffled;
   delete[] shuffled;
   delete[] discard;
   delete[] draw;
   DeletePlayers(players, numpl);
   delete[] players;
   return 0;
}

