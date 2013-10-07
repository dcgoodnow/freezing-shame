#include "unoclass.h"
#include "string.h"
#include <iostream>

using namespace std;

void card::SetColor(char c)
{
   if(c == 'c' ||
      c == 'r' ||
      c == 'g' ||
      c == 'b' ||
      c == 'y')
   {
      color = c;
   }
   else 
      color = 'c';
}

void card::SetRank(int r)
{
   if( r >= 1 || r <= 9)
   {
      rank = r;
   }
   else
      rank = -1;
}

void card::SetAction(char* a)
{
   delete[] action;
   action = new char[length(a)];
   StringCopy(a, action);
}

void card::SetLocation(char* a)
{
   delete[] location;
   location = new char[length(a)];
   StringCopy(a, location);
}

char card::GetColor()
{
   return color;
}

int card::GetRank()
{
   return rank;
}

char* card::GetAction()
{
   return action;
}

char* card::GetLocation()
{
   return location;
}

void card::print()
{
   cout << color << '\t';
   cout << rank << '\t';
   cout << action << '\t';
   cout << location <<  endl;
}


