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

bool card::operator<(const card& c)
{
   if((*this).color < c.color)
      return true;
   return false;
}

bool operator>(const card& a, const card& b)
{
   if(a.color > b.color)
      return true;
   return false;
}

ostream& operator<<(ostream& os, const card& c)
{
   os << c.getColor() << '\t';
   os << c.getRank() << '\t';
   os << c.getAction() << '\t';
   os << c.getLocation() <<  endl;
   return os;
}

istream& operator>>(istream& is, card& c)
{
   char *tempArr;
   tempArr = new char[30];
   StringCopy("basic", tempArr);
   is >> tempArr;
   if(tempArr[0] == 'r' || tempArr[0] == 'R' ||
      tempArr[0] == 'b' || tempArr[0] == 'B' ||
      tempArr[0] == 'y' || tempArr[0] == 'Y' ||
      tempArr[0] == 'g' || tempArr[0] == 'G')
   {
      c.color = tempArr[0];
      is >> tempArr;
      if(tempArr[0] >= '0' && tempArr[0] <= '9')
      {
         c.rank = tempArr[0]-48;
      }
      else
      {
         c.action = tempArr;
      }
   }
   else
   {
      c.action = tempArr;
   }
   return is;
   delete[] tempArr;
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


ostream& operator<<(ostream& os, const player& p)
{
   os << p.getName() << endl;
   int* iptr = p.getID();
   for(int i = 0; i < 5; i++)
   {
      os << iptr[i];
   }
   os << endl;
   card* cptr = p.getHand();
   for(int i = 0; i < 7; i++)
   {
      os << cptr[i];
   }
   return os;
}

istream& operator>>(istream& is, player& p)
{
   char * temp;
   temp = new char[30];
   char idChar;
   int* iptr;
   iptr = new int[5];
   is >> p.name;
   for( int j = 0; j < 5; j ++)
   {
      //load each integer into temporary character
      is >> idChar;
      //convert to integer, store in array
      p.id[j] = idChar-48;
   }
   
   delete[] temp;
   temp = NULL;
   delete[] iptr;
   iptr = NULL;
   return is;
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
      cout << *cptr;
      cptr++;
   }
}

