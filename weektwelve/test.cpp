#include "uno.h"
#include <iostream>
#include "string.h"

int main()
{
   card * loadc;
   loadc = new card[108];
   LoadDeck(loadc);
   card* sorted = new card[108];
   for(int i = 0; i < 108; i++)
   {
      loadc[i].print();
   }
   sorted = SortCardsRank(loadc, 108);
   
   sorted = SortCardsColor(sorted, 108);
   for(int i = 0; i < 108; i++)
   {
      sorted[i].print();
   }
   return 0;
}
