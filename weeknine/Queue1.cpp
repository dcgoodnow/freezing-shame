#include "Queue.h"

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
bool full() const;
bool clear();
bool operator==(const Queue&) const;
friend ostream& operator<<(ostream&, const Queue&);
