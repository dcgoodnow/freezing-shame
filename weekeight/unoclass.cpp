#include "unoclass.h"
#include "string.h"
#include <iostream>

using namespace std;

card::card(int r, const char* l )
{
   color = 'c';
   rank = r;
   action = new char[20];
   location = new char[20];
   StringCopy("action", action);
   StringCopy(l, location);
}

card::card(int r, char c, const char* a, const char* l)
{
   setColor(c);
   setRank(r);
   action = new char[20];
   StringCopy(a, action);
   location = new char[20];
   StringCopy(l, location);
}

card::card(const card& c)
{
   color = c.color;
   rank = c.rank;
   action = new char[20];
   setAction(c.action);
   location = new char[20];
   setLocation(c.location);
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

card card::operator=(const card& orig)
{
    if(this != &orig)	
    {
        color = orig.color;
        rank = orig.rank;
        setAction(orig.action);
        setLocation(orig.location);
    }
    return *this;
}

void card::setColor(char c)
{
   if(c == 'c' || c == 'C' ||
      c == 'r' || c == 'R' ||
      c == 'g' || c == 'G' ||
      c == 'b' || c == 'B' ||
      c == 'y' || c == 'Y')
   {
      color = c;
   }
   else 
      color = 'c';
}

void card::setRank(int r)
{
   if( r >= 1 || r <= 9)
   {
      rank = r;
   }
   else
      rank = -1;
}

void card::setAction(const char* a)
{
   StringCopy(a, action);
}

void card::setLocation(const char* a)
{
   StringCopy(a, location);
}

char card::getColor()const 
{
   return color;
}

int card::getRank() const 
{
   return rank;
}

char* card::getAction() const 
{
   return action;
}

char* card::getLocation() const 
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

void card::copyCard(card orig)
{
   //copy all aspects of the card
   color = orig.color;
   rank = orig.rank;
   setAction(orig.action);
   setLocation(orig.location);
   
}
void card::Swap(card& c)
{
  card temp;
  temp.copyCard(c);
  c.copyCard(*this);
  copyCard(temp);
}


/***********************
  *
  *Player Functions
  *
  *
***********************/
player::player()
{
   name = new char[25];
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

player::player(const char* n, const int* i, card* h)
{
   name = new char[30];
   StringCopy(n, name);
   id = new int[5];
   for(int j = 0; j < 5; j++)
   {
      id[j] = i[j];
   }
   hand = NULL;
   setHand(h);
}

player::player(const player& p)
{
   name = new char[25];
   setName(p.name);
   setID(p.id);
   hand = NULL;
   setHand(p.hand);
}

player::~player()
{
   delete[] name;
   name = NULL;
   delete[] id;
   id = NULL;
   delete[] hand;
   hand = NULL;
}

player player::operator=(const player& orig)
{
   if(this != &orig)
   {
      StringCopy(name, orig.name);
      setID(orig.id);
      setHand(orig.hand);
   }
   return *this;
}

void player::setName(const char* n)
{
   StringCopy(n, name);
}

char* player::getName() const 
{
   return name;
}

void player::setID(int* n)
{
   int* iptr = id;
   for(int i = 0; i < 5; i++)
   {
      *iptr = *n;
      n++;
      iptr++;
   }
}

int* player::getID() const 
{
   return id;
}

void player::setHand(card* h)
{
   if(hand == NULL)
   {
      hand = new card[7];
   }
   card* cptr = hand;
   
   for( int i = 0; i < 7; i++)
   {
      (*cptr).copyCard(*h);
      (*cptr).setLocation(name);
      cptr++;
      h++;
   }
}

card* player::getHand() const 
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

