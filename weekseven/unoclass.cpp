#include "unoclass.h"
#include "string.h"
#include <iostream>

using namespace std;

card::card()
{
   color = 'c';
   rank = -1;
   action = new char[6];
   location = new char[9];
   StringCopy("Action", action);
   StringCopy("Location", location);
}

card::card(const card& c)
{
   color = c.color;
   rank = c.rank;
   SetAction(c.action);
   SetLocation(c.location);
}

card::~card()
{
   color = 'c';
   rank = -1;
   delete[] action;
   action = NULL;
   delete[] location;
   location = NULL;
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

void card::SetAction(const char* a)
{
   delete[] action;
   action = new char[length(a)];
   StringCopy(a, action);
}

void card::SetLocation(const char* a)
{
   delete[] location;
   location = new char[length(a)];
   StringCopy(a, location);
}

char card::GetColor()const 
{
   return color;
}

int card::GetRank() const 
{
   return rank;
}

char* card::GetAction() const 
{
   return action;
}

char* card::GetLocation() const 
{
   return location;
}

void card::print() const 
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

player::player()
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
}

//FIX SETHAND FN TO WORK HERE VVV
player::player(const player& p)
{
   SetName(p.name);
   SetID(p.id);
}

player::~player()
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

char* player::GetName() const 
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

int* player::GetID() const 
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

card* player::GetHand() const 
{
   return hand;
}

void player::print() const
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


