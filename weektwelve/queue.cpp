#include "queue.h"

template <typename T>
node<T>::node(T c, node<T>* n)
{
   data = c; 
   next = n;
}

template <typename T>
queue<T>::queue()
{
   front = NULL;
   back = NULL;
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
}

template <typename T>
bool queue<T>::empty() const
{
   if(front == NULL && back == NULL)
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




