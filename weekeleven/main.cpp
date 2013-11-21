#include "employee.h"
#include "student.h"
#include <iostream>
#include <fstream>

int main()
{
   std::ifstream inFile;
   inFile.open("persons");
   student s;
   employee e;
   char temp;
   for(int i =0; i < 18; i++)
   {
      inFile >> temp; 
      if(temp == 'e')
      {
         e.read(inFile);
         e.print();
      }
      if(temp == 's')
      {
         s.read(inFile);
         s.print();
      }
      std::cout << "===========================" << std::endl;

   }

   employee e2;
   e2.setFirst("Foo");
   e2.setLast("Bar");
   e2.setAge(21);
   int* intArr = new int[10];
   for(int i = 0; i < 10; i++)
   {
      intArr[i] = i;
   }
   e2.setSSN(intArr);
   e2.setTitle("Master");
   e2.setID(intArr);
   e2.setSalary(100000);
   e2.print();

   student s2;
   s2.setFirst("Joe");
   s2.setLast("Bob");
   s2.setAge(78);
   s2.setSSN(intArr);
   s2.setNSHE(intArr);
   s2.setMajor("Business...");
   s2.setGPA(3.4);
   s2.print();
   return 0;
}
