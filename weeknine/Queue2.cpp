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
   if(q.rear < q.front)
   {
      for(int i = q.front%q.maxSize; i <= q.rear+q.maxSize; i++)
      {
         data[i%maxSize] = q.data[i%maxSize];
      }
   }
   else
   {
      for(int i = q.front; i <= q.rear; i++)
      {
         data[i] = q.data[i];
      }
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
   if(q.rear < q.front)
   {
      for(int i = q.front%q.maxSize; i <= q.rear+q.maxSize; i++)
      {
         data[i%maxSize] = q.data[i%maxSize];
      }
   }
   else
   {
      for(int i = q.front; i <= q.rear; i++)
      {
         data[i] = q.data[i];
      }
   }
   return *this;
}

bool Queue::enqueue(int toQueue)
{
   if(!full())
   {
      if(front != -1)
      {
         rear = (rear+maxSize+1);
         rear %= maxSize;
         data[rear] = toQueue;
         return true;
      }
      front++;
      rear++;
      data[front] = toQueue;
      return true;
   }
   return false;
}
bool Queue::dequeue(int& d)
{
   if(!empty())
   {
      d = data[front];
      front = (front+maxSize+1);
      front %= maxSize;
      return true;
   }
   return false;
}
bool Queue::empty() const
{
   if(front == -1)
      return true;
   return false;
}
bool Queue::full() const
{
   if(front == 0 && rear == maxSize -1) 
      return true;
   if(front == rear+1)
      return true;
   return false;
}
bool Queue::clear()
{
   front = rear = -1;
}
bool Queue::operator==(const Queue& q) const
{
   if(maxSize != q.maxSize || 
      (rear+maxSize)%maxSize - front != (q.rear+q.maxSize)%q.maxSize - q.front)
   {
      return false;
   }
   for(int i = rear; i < front; i++)
   {
      i = (i+maxSize)%maxSize;
      if(data[i] != q.data[i])
         return false;
   }
   return true;
}
ostream& operator<<(ostream& os, const Queue& q)
{
   if(q.empty())
   {
      os << "EMPTY";
      return os;
   }
   os << "[" << q.data[q.front] << "] ";
   if(q.rear < q.front)
   {
      for(int i = (q.front+1)%q.maxSize; i <= q.rear+q.maxSize; i++)
      {
         os << q.data[i%q.maxSize] << ' ';
      }
   }
   else
   {
      for(int i = q.front+1; i <= q.rear; i++)
      {
         os << q.data[i] << ' ';
      }
   }
   return os;
}
