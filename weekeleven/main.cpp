#include "person.cpp"
#include "employee.cpp"
#include <iostream>

int main()
{
   employee me;
   me.setFirst("danny");
   me.setLast("goodnow");
   me.setAge(20);
   int* a = new int[9];
   for(int i = 0; i < 9; i++)
   {
      a[i] = i;
   }
   me.setSSN(a);
   me.setTitle("Badass");
   me.setSalary(1000000000);
   for(int i = 0; i < 5; i++)
   {
      a[i] = i;
   }
   me.setID(a);
   person p1;
   p1.setFirst("blah");
   p1.setLast("foo");
   person p2(p1);
   p2.print();
   employee you(me);
   you.print();
   return 0;
}
