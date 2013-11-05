#include "Stack.h"
#include <iostream>

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
      for(int i = actual-1; i >= 0; i--)
      {
         data[i+1] = data[i];
      }
      data[0] = toPush;
      actual++;
      return true;
   }
   return false;
}

template <typename T>
bool Stack<T>::pop(T& popper)
{
   if(!empty())
   {
      popper = data[0];
      for(int i = 1; i < actual; i++)
      {
         data[i-1] = data[i];
      }
      actual--;
      return true;
   }
   return false;
}

template <typename T>
bool Stack<T>::empty() const
{
   if(actual == 0)
      return true;
   return false;
}
template <typename T>
bool Stack<T>::full() const
{
   if(actual == maxSize)
      return true;
   return false;
}
template <typename T>
bool Stack<T>::clear()
{
   actual = 0;
}
template <typename T>
void Stack<T>::print() const
{
   if(empty())
   {
      cout << "EMPTY" << endl;
      return;
   }
   cout << '[' << data[0] << "] ";
   for(int i = 1; i < actual; i++)
   {
      cout << data[i] << ' ';
   }
   cout << endl;
}
