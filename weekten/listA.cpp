#include "listA.h"

List::List(int s)
{
   size = s;
   data = new char[size];
   cursor = 0;
   actual = 0;
}

List::List(const List& l)
{
   size = l.size;
   data = new char[size];
   actual = l.actual;
   cursor = l.cursor;
   for(int i = 0; i < actual; i++)
   {
      data[i] = l.data[i];
   }
}

List::~List()
{
   delete[] data;
   cursor = 0;
   actual = 0;
}

bool List::gotoBeginning()
{
   cursor = 0;
   return true;
}

bool List::gotoEnd()
{
   if(!empty())
   {
      cursor = actual - 1;
      return true;
   }
   return false;
}

bool List::gotoNext()
{
   if(cursor == actual-1 || empty())
      return false;
   cursor++;
   return true;
}

bool List::gotoPrior()
{
   if(cursor == 0 || empty())
      return false;
   cursor--;
   return true;
}

bool List::insertAfter(char c)
{
   if(empty())
   {
      data[cursor] = c;
      actual++;
      return true;
   }
   else if(!full()) 
   {
      if(cursor != size -1)
      {
         char tmp;
         for( int i = actual; i > cursor+1; i--)
         {
            data[i] = data[i-1];
         }
         cursor++;
         data[cursor] = c;
         actual++;
         return true;
      }
   }
   
   return false;
}

bool List::insertBefore(char c)
{
   if(empty())
   {
      data[cursor] = c;
      actual++;
      return true;
   }
   else if(!full())
   {
      for( int i = actual; i > cursor; i--)
      {
         data[i] = data[i-1];
      }
      data[cursor] = c;
      actual++;
      return true;
      
   }
   return false;
}

bool List::remove(char& c)
{
   if(empty())
      return false;
   c = data[cursor];
   for(int i = cursor; i < actual-1; i++)
   {
      data[i] = data[i+1];
   }
   actual--;
   return true;
}

bool List::replace(char c)
{
   if(!empty())
   {
      data[cursor] = c;
      return true;
   }
   return false;
}

bool List::getCursor(char& c) const
{
   if(!empty())
   {
      c = data[cursor];
      return true;
   }
   return false;
}

bool List::empty() const
{
   if(actual == 0)
      return true;
   return false;
}

bool List::full() const
{
   if(actual == size)
      return true;
   else
      return false;
}

bool List::clear()
{
   if(empty())
      return false;
   cursor = 0;
   actual = 0;
   return true;
}

List& List::operator=(const List& l)
{
   if(this != &l)
   {
      delete[] data;
      size = l.size;
      data = new char[size];
      actual = l.actual;
      cursor = l.cursor;
      for(int i = 0; i < actual; i++)
      {
         data[i] = l.data[i];
      }
   }
   return *this;
}

ostream& operator<<(ostream& os, const List& l)
{
   if(l.empty())
   {
      os << "EMPTY";
      return os;
   }
   for(int i = 0; i <= l.cursor -1; i++)
   {
      os << l.data[i] << ' ';
   }
   os << '[' << l.data[l.cursor] << "] ";
   for(int i = l.cursor+1; i < l.actual; i++)
   {
      os << l.data[i] << ' ';
   }
   return os;
}


bool List::operator==(const List& l) const
{
   if(empty() ^ l.empty())
      return false;
   if(empty() && l.empty())
      return true;
   if(actual != l.actual ||
      size != l.size     ||
      cursor != l.cursor   )
      return false;
   for(int i = 0; i < actual; i++)
   {
      if(data[i] != l.data[i])
      {
         return false;
      }
   }
   return true;
}
//NEED TO TEST, DETERMINE ANY OTHER SPECIAL CASES
