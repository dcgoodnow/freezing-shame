
template <typename T>
node<T>::node(T c, node<T>* n)
{
   data = c; 
   next = n;
   if(true);
}

template <typename T>
list<T>::list(int s)
{
   head = NULL;
   cursor = NULL;
}

template <typename T>
list<T>::list(const list<T>& l)
{
   if(l.empty())
   {
      head = NULL;
      cursor = NULL;
   }
   else
   {
      node<T>* stmp = l.head;

      //create first node
      node<T>* dtmp = new node<T>(stmp->data, stmp->next);
      head = dtmp;
      if(l.cursor == stmp)
         cursor = dtmp;

      //copy the remaining nodes, including the cursor
      while(stmp->next != NULL)
      {
         stmp = stmp->next;
         dtmp->next = new node<T>(stmp->data, stmp->next);
         dtmp = dtmp->next;
         if(l.cursor == stmp)
            cursor = dtmp;
      }
   }
}

template <typename T>
list<T>::~list()
{
   node<T>* tmp;
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

template <typename T>
bool list<T>::gotoBeginning()
{
   if(!empty())
   {
      cursor = head;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::gotoEnd()
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

template <typename T>
bool list<T>::gotoNext()
{
   if(!empty() && cursor->next != NULL)
   {
      cursor = cursor->next;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::gotoPrior()
{ if(cursor == head)
      return true;
   if(!empty())
   {
      //start at beginning and move through nodes until next node is cursor
      node<T>* tmp = head;
      while(tmp->next != cursor)
      {
         tmp = tmp->next;
      }
      cursor = tmp;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::insertAfter(T c)
{
   if(!empty() && !full())
   {
      //create a node with the next address from the cursor's next address
      node<T>* tmp = new node<T>(c, cursor->next);
      cursor->next = tmp;

      //move cursor to new node
      cursor = tmp;
      return true;
   }
   if(empty())
   {
      //create first node
      cursor = new node<T>(c, NULL);
      head = cursor;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::insertBefore(T c)
{
   if(!empty() && !full())
   {
      //create a copy of the current node
      node<T>* tmp = new node<T>(cursor->data, cursor->next);

      //replace current node data with new data and location of new(old) node
      cursor->data = c;
      cursor->next = tmp;
      return true;
   }
   if(empty())
   {
      //create first node
      cursor = new node<T>(c, NULL);
      head = cursor;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::remove(T& c)
{
   if(!empty())
   {
      c = cursor->data;
      node<T>* tmp = cursor;
      
      //use this if the in focus node is not the tail of the list
      if(cursor->next != NULL)
      {
         if(cursor == head)
         {
            cursor = cursor->next;
            head = cursor;
            delete tmp;
            tmp = NULL;
         }
         else
         {
            node<T>* tmp2 = cursor->next;
            gotoPrior();
            delete tmp;
            tmp = NULL;
            cursor->next = tmp2;
         }
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
            gotoBeginning();
            delete tmp;
            tmp = NULL;
         }
      }
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::replace(T c)
{
   if(!empty())
   {
      cursor->data = c;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::getCursor(T& c) const
{
   if(!empty())
   {
      c = cursor->data;
      return true;
   }
   return false;
}

template <typename T>
bool list<T>::empty() const
{
   //cursor is set to null any time all nodes are deleted
   if(cursor == NULL)
      return true;
   else
      return false;
}

template <typename T>
bool list<T>::full() const
{
   return false;
}

template <typename T>
bool list<T>::clear()
{
   if(!empty())
   {
      gotoBeginning();
      node<T>* tmp = NULL;

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

template <typename T>
list<T>& list<T>::operator=(const list<T>& l)
{
   if(!l.empty())
   {
      //delete previous list (clear automatically checks for an empty list)
      clear();
      node<T>* stmp = l.head;
      node<T>* dtmp = new node<T>(stmp->data, stmp->next);
      head = dtmp;
      if(l.cursor == stmp)
         cursor = dtmp;

      //copy and link all nodes, checking for cursor at each node
      while(stmp->next != NULL)
      {
         stmp = stmp->next;
         dtmp->next = new node<T>(stmp->data, stmp->next);
         dtmp = dtmp->next;
         if(l.cursor == stmp)
            cursor = dtmp;
      }
   }
   return *this;
}

template <typename T>
ostream& operator<<(ostream& os, const list<T>& l) 
{
   if(!l.empty())
   {
      //output head node
      node<T>* tmp = l.head;
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

template <typename T>
bool list<T>::operator==(const list<T>& l) const
{
   if(empty() ^ l.empty())
      return false;
   if(empty() && l.empty())
      return true;
   node<T>* tmp1 = head;
   node<T>* tmp2 = l.head;

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

template <typename T>
queue<T>::queue()
{
   front = NULL;
   back = NULL;
}

template <typename T>
queue<T>::queue(const queue<T>& q)
{
   if(q.empty())
   {
      front = NULL;
      back = NULL;
   }
   else
   {
      node<T>* tmpS = q.front;;
      node<T>* tmpD;
      front = new node<T>(q.front->data, q.front->next);
      back = front;
      tmpD = front;
      tmpS = tmpS->next;
      while(back->next != NULL)
      {
         tmpD = new node<T>(tmpS->data, tmpS->next);
         back->next = tmpD;
         back = tmpD;
         tmpS = tmpS->next;
      }
   }
}

template <typename T>
queue<T>::~queue()
{
   node<T>* tmp;
   if(!empty())
   {

      //loop through all nodes and delete them
      while(front != NULL)
      {
         tmp = front;
         front = front->next;
         delete tmp;
      }
   }
   front = NULL;
   back = NULL;
}

template <typename T>
bool queue<T>::enqueue(T toQueue)
{
   if(empty())
   {
      front = new node<T>(toQueue, NULL);
      back = front;
      return true;
   }
   node<T>* tmp = new node<T>(toQueue, NULL);
   back->next = tmp;
   back = tmp;
   return true;
}

template <typename T>
bool queue<T>::dequeue(T& t)
{
   if(empty())
      return false;
   t = front->data;
   node<T>* tmp = front;
   front = front->next;
   delete tmp;
   tmp = NULL;
   return true;
}

template <typename T>
bool queue<T>::empty() const
{
   if(front == NULL)  
      return true;
   return false;
}

template <typename T>
bool queue<T>::full() const
{
   return false;
}

template <typename T>
bool queue<T>::clear()
{
   node<T>* tmp;
   if(!empty())
   {
      //loop through all nodes and delete them
      while(front != NULL)
      {
         tmp = front;
         front = front->next;
         delete tmp;
      }
   }
   front = NULL;
   back = NULL;
   return true;
}

template <typename T>
queue<T>& queue<T>::operator=(const queue& q)
{
   clear();
   if(q.empty())
      return *this;
   node<T>* tmpS = q.front;;
   node<T>* tmpD;
   front = new node<T>(q.front->data, q.front->next);
   back = front;
   tmpD = front;
   tmpS = tmpS->next;
   while(back->next != NULL)
   {
      tmpD = new node<T>(tmpS->data, tmpS->next);
      back->next = tmpD;
      back = tmpD;
      tmpS = tmpS->next;
   }
   return *this;
}

