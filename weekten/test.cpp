#include "listA.h"
#include "listA.cpp"
#include <iostream>

using namespace std;

int main()
{
   List l1;

   l1.insertAfter('a');
   for(int i = 0; i < 9; i++)
   {
      l1.insertAfter(i+48);
   }
   cout << l1 <<endl;
}
