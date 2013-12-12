#include "listA.h"

List::List(int s)
{
   size = s;
   data = NULL;
   data = new int[size];
   cursor = 0;
   actual = 0;
}

List::List(const List& l)
{
   size = l.size;
   data = NULL;
   data = new int[size];
   actual = l.actual;
   cursor = l.cursor;
   
   //copy all elements
   for(int i = 0; i < actual; i++)
   {
      data[i] = l.data[i];
   }
}

List::List(ListN& l)
{
   l.gotoBeginning();
   size = 0;
   while(l.gotoNext())
   {
      size++;
   }
   size++;
   data = new int[size];
   actual = size;
   
   //copy all elements
   l.gotoBeginning();
   int i = 0;
   int temp;
   l.getCursor(temp);
   data[i] = temp;
   i++;
   while(l.gotoNext())
   {
      l.getCursor(temp);
      data[i] = temp;
      i++;
   }
   cursor = 0;

}

List::~List()
{
   if(data != NULL)
   {
      delete[] data;
   }
   cursor = 0;
   actual = 0;
   data = NULL;
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
   //can't go to next if at maxsize or empty
   if(cursor == actual-1 || empty())
      return false;
   cursor++;
   return true;
}

bool List::gotoPrior()
{
   //can't go backwards if at beginning or empty
   if(cursor == 0 || empty())
      return false;
   cursor--;
   return true;
}

bool List::insertAfter(int c)
{
   //don't implement the cursor if starting from empty list
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
         //shift all succeeding elements down by 1
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

bool List::insertBefore(int c)
{
   if(empty())
   {
      data[cursor] = c;
      actual++;
      return true;
   }
   else if(!full())
   {
      //shuffle all elements including cursor down
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

bool List::remove(int& c)
{
   if(empty())
      return false;
   c = data[cursor];
   //shift elements up, overwriting old data at the cursor
   for(int i = cursor; i < actual-1; i++)
   {
      data[i] = data[i+1];
   }
   actual--;
   return true;
}

bool List::replace(int c)
{
   if(!empty())
   {
      data[cursor] = c;
      return true;
   }
   return false;
}

bool List::getCursor(int& c) const
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
      //remove old array
      delete[] data;
      size = l.size;
      data = new int[size];
      actual = l.actual;
      cursor = l.cursor;

      //copy all elements
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
   //print data up to cursor
   for(int i = 0; i <= l.cursor -1; i++)
   {
      os << l.data[i] << ' ';
   }

   //print cursor
   os << '[' << l.data[l.cursor] << "] ";

   //print data after cursor
   for(int i = l.cursor+1; i < l.actual; i++)
   {
      os << l.data[i] << ' ';
   }
   return os;
}


bool List::operator==(const List& l) const
{
   //check simple conditions that give immediate solution
   if(empty() ^ l.empty())
      return false;
   if(empty() && l.empty())
      return true;
   if(actual != l.actual ||
      size != l.size     ||
      cursor != l.cursor   )
      return false;
   
   //check individual data elements for equivalence
   for(int i = 0; i < actual; i++)
   {
      if(data[i] != l.data[i])
      {
         return false;
      }
   }

   //if got this far, they are the same
   return true;
}
