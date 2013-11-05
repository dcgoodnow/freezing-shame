#include <iostream>
#include "Stack.h"
#include "Stack2.cpp" 

int main ()
{
   Stack<int> s1(15);
   s1.push(5);
   s1.print();
   for(int i = 0; i < 14; i++)
   {
      s1.push(i);
   }
   Stack<int> s2;
   s2 = s1;
   s2.print();

}
