#include "unoclass.h"
#include "string.h"
#include <iostream>

using namespace std;

void card::init()
{
   color = 'c';
   rank = -1;
   action = new char[6];
   location = new char[9];
   StringCopy("Action", action);
   StringCopy("Location", location);
}

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

void card::CopyCard(card &dest)
{
   //copy all aspects of the card
   dest.SetColor(color);
   dest.SetRank(rank);
   dest.SetAction(action);
}

void card::del()
{
   delete[] action;
   action = NULL;
   delete[] location;
   location = NULL;
}

void player::init()
{
   name = new char[5];
   StringCopy("Name", name);
   id =  new int[5];
   int* iptr = id;
   for(int i = 0; i < 5; i++)
   {
      iptr = 0;
      iptr++;
   }
   hand = new card[7];
   card* cptr = hand;
   for(int i = 0; i < 7; i++)
   {
      (*cptr).init();
      cptr++;
   }
}

void player::del()
{
   delete[] name;
   name = NULL;
   delete[] id;
   id = NULL;
   card* cptr = hand;
   for(int i = 0; i <7; i++)
   {
      (*cptr).del();
      cptr++;
   }
   delete[] hand;
   hand = NULL;
}
void player::SetName(char* n)
{
   delete[] name;
   name = new char[length(n)];
   StringCopy(n, name);
}

char* player::GetName()
{
   return name;
}

void player::SetID(int* n)
{
   int* iptr = id;
   for(int i = 0; i < 5; i++)
   {
      *iptr = *n;
      n++;
      iptr++;
   }
}

int* player::GetID()
{
   return id;
}

void player::SetHand(card* h)
{
   card* cptr = hand;
   for( int i = 0; i < 7; i++)
   {
      (*cptr).init();
      (*h).CopyCard(*cptr);
      (*cptr).SetLocation(name);
      cptr++;
      h++;
   }
}

card* player::GetHand()
{
   return hand;
}

void player::print()
{
   cout << name << endl;
   int* iptr = id;
   for(int i = 0; i < 5; i++)
   {
      cout << *iptr;
      iptr++;
   }
   cout << endl;
   card* cptr = hand;
   for(int i = 0; i < 7; i++)
   {
      (*cptr).print(); 
      cptr++;
   }
}


