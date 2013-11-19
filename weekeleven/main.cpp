#include "person.h"
#include "person.cpp"
#include <iostream>

int main()
{
   person me;
   me.setFirst("danny");
   me.setLast("goodnow");
   me.setAge(20);
   int* a = new int[9];
   for(int i = 0; i < 9; i++)
   {
      a[i] = i;
   }
   me.setSSN(a);

   me.print();
   return 0;
}
