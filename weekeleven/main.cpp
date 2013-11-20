#include "person.cpp"
#include "student.cpp"
#include <iostream>

int main()
{
   student me;
   me.setFirst("danny");
   me.setLast("goodnow");
   me.setAge(20);
   int* a = new int[9];
   for(int i = 0; i < 9; i++)
   {
      a[i] = i;
   }
   me.setSSN(a);
   me.setMajor("Badass");
   me.setGPA(3.9);
   for(int i = 0; i < 10; i++)
   {
      a[i] = i;
   }
   me.setNSHE(a);
   me.print();
   person p1;
   p1.setFirst("blah");
   p1.setLast("foo");
   person p2(p1);
   p2.print();
   return 0;
}
