#include "Stack.h"

template <typename T>
Stack<T>::Stack(int s)
{
   maxSize = s;
   data = new T[maxSize];
   top = -1;
   actual = 0;
}

template <typename T>
Stack<T>::Stack(const Stack& s)
{
   maxSize = s.maxSize;
   data = new T[maxSize];
   for(int i = 0; i < maxSize; i++)
   {
      data[i] = s.data[i];
   }
   top = s.top;
   actual = s.actual;
}

template <typename T>
Stack<T>::~Stack()
{
   delete[] data;
   data = NULL;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& s)
{
   maxSize = s.maxSize;
   delete[] data;
   data = new T[maxSize];
   for(int i = 0; i < maxSize; i++)
   {
      data[i] = s.data[i];
   }
   top = s.top;
   actual = s.actual;
}

template <typename T>
bool Stack<T>::push(T toPush)
{
   if(!full())
   {
      top++;
      data[top] = toPush;
      return true;
   }
   return false;
}

template <typename T>
bool Stack<T>::pop(T& popper)
{
   if(!empty())
   {
      popper = data[top];
      top--;
      return true;
   }
   return false;
}

template <typename T>
bool Stack<T>::empty() const
{
   if(top < 0)
      return true;
   return false;
}

template <typename T>
bool Stack<T>::full() const
{
   if(top >= maxSize - 1)
      return true;
   return false;
}

template <typename T>
bool Stack<T>::clear()
{
   top = -1;
}

template <typename T>
void Stack<T>::print() const
{
   for(int i = 0; i < maxSize; i++)
   {
      cout << data[i] << endl;
   }
}
