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
