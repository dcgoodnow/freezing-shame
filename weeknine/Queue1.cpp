#include "Queue.h"
#include <iostream>

Queue::Queue(int size)
{
   maxSize = size;
   data = new int[maxSize];
   front = -1;
   rear = -1;
}

Queue::Queue(const Queue& q)
{
   maxSize = q.maxSize;
   data = new int[maxSize];
   front = q.front;
   rear = q.rear;
   for(int i = 0; i < rear; i++)
   {
      data[i] = q.data[i];
   }
}
Queue::~Queue()
{
   delete[] data;
}
Queue& Queue::operator=(const Queue& q)
{
   
   maxSize = q.maxSize;
   delete[] data;
   data = new int[maxSize];
   front = q.front;
   rear = q.rear;
   for(int i = 0; i < rear; i++)
   {
      data[i] = q.data[i];
   }
}
bool Queue::enqueue(int toQueue)
{
   if(!full())
   {
      for(int i = front; i >= 0; i++)
      {
         data[i+1] = data[i];
      }
      front++;
      data[0] = toQueue;
      return true;
   }
   return false;
}
bool Queue::dequeue(int& popper)
{
   if(!empty())
   {
      popper = data[front];
      front--;
   }
}
bool Queue::empty() const
{
   if(front == -1)
      return true;
   return false;
}
bool Queue::full() const
{
   if(rear == maxSize -1)
      return true;
   return false;
}
bool Queue::clear()
{
   front = -1;
   rear = -1;
}
bool Queue::operator==(const Queue& q) const
{
   if(front != q.front)
   {
      return false;
   }
   for(int i = 0; i <= front; i++)
   {
      if(data[i] != q.data[i])
         return false;
   }
   return true;
}
ostream& operator<<(ostream& os, const Queue& q)
{
   os << '[' << q.data[q.front] << "] ";
   for(int i = q.front - 1; i >= 0; i --)
   {
      os << q.data[i] << ' ';
   }
   os << endl;
   return os;
}
