#include "listN.h"

Node::Node(char c, Node* n)
{
   data = c; 
   next = n;
}

List::List(int s)
{
   head = NULL;
   cursor = NULL;
}

List::~List()
{
   Node* tmp;
   if(!empty())
   {
      gotoBeginning();
      while(cursor != NULL)
      {
         tmp = cursor;
         cursor = cursor->next;
         delete tmp;
      }
   }
}

bool List::gotoBeginning()
{
   if(!empty())
   {
      cursor = head;
      return true;
   }
   return false;
}

bool List::gotoEnd()
{
   if(!empty())
   {
      while(cursor->next != NULL)
      {
         cursor = cursor->next;
      }
      return true;
   }
   return false;
}

bool List::gotoNext()
{
   if(!empty() && cursor->next != NULL)
   {
      cursor = cursor->next;
      return true;
   }
   return false;
}

bool List::gotoPrior()
{
   if(!empty())
   {
      Node* tmp = head;
      while(tmp->next != cursor)
      {
         tmp = tmp->next;
      }
      cursor = tmp;
      return true;
   }
   return false;
}

bool List::insertAfter(char c)
{
   if(!empty() && !full())
   {
      Node* tmp = new Node(c, cursor->next);
      cursor->next = tmp;
      return true;
   }
   if(empty())
   {
      cursor = new Node(c, NULL);
      head = cursor;
      return true;
   }
   return false;
}

bool List::insertBefore(char c)
{
   if(!empty() && !full())
   {
      Node* tmp = new Node(cursor->data, cursor->next);
      cursor->data = c;
      return true;
   }
   if(empty())
   {
      cursor = new Node(c, NULL);
      head = cursor;
      return true;
   }
   return false;
}

bool List::remove(char& c)
{
   if(!empty())
   {
      c = cursor->data;
      Node* tmp = cursor;
      if(cursor->next != NULL)
      {
         Node* tmp2 = cursor->next;
         gotoPrior();
         delete tmp;
         tmp = NULL;
         cursor->next = tmp2;
      }
      else
      {
         gotoPrior();
         cursor->next = NULL;
         gotoBeginning();
         delete tmp;
      }
      return true;
   }
   return false;
}

bool List::replace(char c)
{
   if(!empty())
   {
      cursor->data = c;
      return true;
   }
   return false;
}

bool List::getCursor(char& c) const
{
   if(!empty())
   {
      c = cursor->data;
      return true;
   }
   return false;
}

bool List::empty() const
{
   if(cursor == NULL)
      return true;
   else
      return false;
}

bool List::full() const
{
   return true;
}

bool List::clear()
{
   if(!empty())
   {
      gotoBeginning();
      Node* tmp = NULL;
      while(cursor != NULL)
      {
         tmp = cursor;
         cursor = cursor->next;
         delete tmp;
      }
      cursor = NULL;
      head = NULL;
      return true;
   }
   return false;
}

List& List::operator=(const List& l)
{
   if(!l.empty())
   {
      clear();
      Node* stmp = l.head;
      Node* dtmp = new Node(stmp->data, stmp->next);
      head = dtmp;
      if(l.cursor == stmp)
         cursor = dtmp;
      while(stmp->next != NULL)
      {
         stmp = stmp->next;
         dtmp->next = new Node(stmp->data, stmp->next);
         dtmp = dtmp->next;
         if(l.cursor == stmp)
            cursor = dtmp;
      }
   }
   return *this;
}

ostream& operator<<(ostream& os, const List& l) 
{
   if(!l.empty())
   {
      Node* tmp = l.head;
      os << '{' << tmp->data << "} ";
      tmp = tmp->next;
      while(tmp != NULL)
      {
         if(tmp == l.cursor)
            os << '[' << tmp->data <<"] ";
         else
            os <<tmp->data << ' ';
         tmp = tmp->next;
      }
   }
   else
      os << "EMPTY";
   return os;
}

