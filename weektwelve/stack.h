#ifndef __STACK_H
#define __STACK_H
#include <iostream>
using namespace std;


template <typename T>
class stack{
   public:
      stack(int = 10);
      stack(const stack&);
      ~stack();
      stack<T>& operator=(const stack&);
      bool push(T);
      bool pop(T&);
      bool empty() const;
      bool full() const;
      bool clear();
      void print() const;
   private:
      int maxSize;
      int top;
      int actual;
      T* data;
};

#endif
