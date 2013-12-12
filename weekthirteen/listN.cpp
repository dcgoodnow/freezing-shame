#include "listN.h"

Node::Node(int c, Node* n)
{
   data = c; 
   next = n;
}

ListN::ListN(int s)
{
   head = NULL;
   cursor = NULL;
}

ListN::ListN(const ListN& l)
{
   Node* stmp = l.head;

   //create first node
   Node* dtmp = new Node(stmp->data, stmp->next);
   head = dtmp;
   if(l.cursor == stmp)
      cursor = dtmp;

   //copy the remaining nodes, including the cursor
   while(stmp->next != NULL)
   {
      stmp = stmp->next;
      dtmp->next = new Node(stmp->data, stmp->next);
      dtmp = dtmp->next;
      if(l.cursor == stmp)
         cursor = dtmp;
   }

}

ListN::~ListN()
{
   Node* tmp;
   if(!empty())
   {
      gotoBeginning();

      //loop through all nodes and delete them
      while(cursor != NULL)
      {
         tmp = cursor;
         cursor = cursor->next;
         delete tmp;
      }
   }
}

bool ListN::gotoBeginning()
{
   if(!empty())
   {
      cursor = head;
      return true;
   }
   return false;
}

bool ListN::gotoEnd()
{
   if(!empty())
   {
      //loop until last node is found
      while(cursor->next != NULL)
      {
         cursor = cursor->next;
      }
      return true;
   }
   return false;
}

bool ListN::gotoNext()
{
   if(!empty() && cursor->next != NULL)
   {
      cursor = cursor->next;
      return true;
   }
   return false;
}

bool ListN::gotoPrior()
{
   if(cursor == head)
      return true;
   if(!empty())
   {
      //start at beginning and move through nodes until next node is cursor
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

bool ListN::insertAfter(int c)
{
   if(!empty() && !full())
   {
      //create a node with the next address from the cursor's next address
      Node* tmp = new Node(c, cursor->next);
      cursor->next = tmp;

      //move cursor to new node
      cursor = tmp;
      return true;
   }
   if(empty())
   {
      //create first node
      cursor = new Node(c, NULL);
      head = cursor;
      return true;
   }
   return false;
}

bool ListN::insertBefore(int c)
{
   if(!empty() && !full())
   {
      //create a copy of the current node
      Node* tmp = new Node(cursor->data, cursor->next);

      //replace current node data with new data and location of new(old) node
      cursor->data = c;
      cursor->next = tmp;
      return true;
   }
   if(empty())
   {
      //create first node
      cursor = new Node(c, NULL);
      head = cursor;
      return true;
   }
   return false;
}

bool ListN::remove(int& c)
{
   if(!empty())
   {
      c = cursor->data;
      Node* tmp = cursor;
      
      //use this if the in focus node is not the tail of the list
      if(cursor->next != NULL)
      {
         Node* tmp2 = cursor->next;
         gotoPrior();
         delete tmp;
         tmp = NULL;
         cursor->next = tmp2;
      }
      //use this if the cursor is on the tail
      else
      {
         //check if this is the only node 
         if(cursor == head)
         {
            delete cursor;
            //set to empty
            cursor = NULL;
            head = NULL;
         }
         else
         {
            gotoPrior();
            cursor->next = NULL;
            delete tmp;
            tmp = NULL;
         }
      }
      return true;
   }
   return false;
}

bool ListN::replace(int c)
{
   if(!empty())
   {
      cursor->data = c;
      return true;
   }
   return false;
}

bool ListN::getCursor(int& c) const
{
   if(!empty())
   {
      c = cursor->data;
      return true;
   }
   return false;
}

bool ListN::empty() const
{
   //cursor is set to null any time all nodes are deleted
   if(cursor == NULL)
      return true;
   else
      return false;
}

bool ListN::full() const
{
   return false;
}

bool ListN::clear()
{
   if(!empty())
   {
      gotoBeginning();
      Node* tmp = NULL;

      //loop until last node
      while(cursor != NULL)
      {
         tmp = cursor;
         cursor = cursor->next;
         delete tmp;
      }

      //set cursor to show that list is empty
      cursor = NULL;
      head = NULL;
      return true;
   }
   return false;
}

ListN& ListN::operator=(const ListN& l)
{
   if(!l.empty())
   {
      //delete previous list (clear automatically checks for an empty list)
      clear();
      Node* stmp = l.head;
      Node* dtmp = new Node(stmp->data, stmp->next);
      head = dtmp;
      if(l.cursor == stmp)
         cursor = dtmp;

      //copy and link all nodes, checking for cursor at each node
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

ostream& operator<<(ostream& os, const ListN& l) 
{
   if(!l.empty())
   {
      //output head node
      Node* tmp = l.head;
      os << '{' << tmp->data << "} ";
      tmp = tmp->next;
      
      //loop through all nodes
      while(tmp != NULL)
      {
         //output brackets around data if cursor node
         if(tmp == l.cursor)
            os << '[' << tmp->data <<"] ";

         //otherwise simply output data
         else
            os <<tmp->data << ' ';
         tmp = tmp->next;
      }
   }

   //if the list is empty
   else
      os << "EMPTY";
   return os;
}

bool ListN::operator==(const ListN& l) const
{
   if(empty() ^ l.empty())
      return false;
   if(empty() && l.empty())
      return true;
   Node* tmp1 = head;
   Node* tmp2 = l.head;

   //loop through all nodes checking various conditions of similarity
   while(tmp1 != NULL && tmp2 != NULL)
   {
      if(tmp1->data != tmp2->data)
         return false;
      if(cursor == tmp1 && l.cursor != tmp2)
         return false;
      if(tmp1->next == NULL && tmp2->next == NULL)
         return true;
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
   }
   //if the loop completes before returning to the function caller, the lists 
   //are of different lengths
   return false;
}
