#include <iostream>
#include "uno.h"
#include "unoclass.h"
#include "list.h"
#include "stack.h"
using namespace std;


int main()
{
   list<card> unshuffled;
   LoadDeck(unshuffled);
   PrintDeck(unshuffled);
   unshuffled.gotoBeginning();
   card temp;
   unshuffled.getCursor(temp);
   queue<card> shuffled;
   ShuffleDeck(unshuffled, shuffled);
   PrintDeck(shuffled);
   WriteDeck(shuffled, "foo");
   list<player> players;
   ifstream inPlayers;
   inPlayers.open("players.txt");
   LoadPlayers(players, inPlayers, 6);
   PrintPlayers(players);
   stack<card> discard(108);
   queue<card> drawPile;
   DealCards(shuffled, discard, drawPile, players, 6);
   PrintPlayers(players);
   player test;
   unshuffled.replace(temp);
   players.gotoBeginning();
   for(int i = 0; i < 6; i++)
   {
      players.getCursor(test);
      test.SortCardsColor();
      players.replace(test);
      players.gotoNext();
   }
   PrintPlayers(players);
   players.gotoBeginning();
   for(int i = 0; i < 6; i++)
   {
      players.getCursor(test);
      test.SortCardsRank();
      players.replace(test);
      players.gotoNext();
   }
   PrintPlayers(players);

   return 0;
}
