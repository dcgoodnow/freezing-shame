#include "student.h"
#include <iostream>
using namespace std;

student::student()
{
   nshe = new int[10];
   major = new char[30];
   gpa = 0.0;
}

student::student(const student& s)
{
   first = new char[30];
   int i = 0;
   while(s.first[i] != '\0')
   {
      first[i] = s.first[i];
      i++;
   }
   first[i] = '\0';
   last = new char[30];
   i = 0;
   while(s.last[i] != '\0')
   {
      last[i] = s.last[i];
      i++;
   }
   last[i] = '\0';
   age = s.age;
   setSSN(s.getSSN());
   nshe = new int[10];
   for(int i = 0; i < 10; i++)
   {
      nshe[i] = s.nshe[i];
   }
   major = new char[30];
   int j = 0;
   while(s.major[j] != '\0')
   {
      major[j] = s.major[j];
      j++;
   }
   gpa = s.gpa;
}

student::~student()
{
   delete[] nshe;
   nshe = NULL;
   delete[] major;
   major = NULL;
   gpa = 0.0;
}

bool student::setNSHE(int* n)
{
   for(int i = 0; i < 10; i++)
   {
      if(n[i] <0 || n[i] >9)
         return false;
   }
   for(int i = 0; i < 10; i++)
   {
      nshe[i] = n[i];
   }
   return true;
}

void student::setMajor(const char* m)
{
   int i = 0;
   while(m[i] != '\0')
   {
      major[i] = m[i];
      i++;
   }
   major[i] = '\0';
}

bool student::setGPA(double g)
{
   if(g < 0.0 || g > 4.0)
      return false;
   gpa = g;
   return true;
}

int* student::getNSHE() const
{
   return nshe;
}

char* student::getMajor() const
{
   return major;
}

double student::getGPA() const
{
   return gpa;
}

void student::print() const
{
   cout << last << ", " << first << endl;
   cout << "Age: " << age << endl;
   cout << "SSN: ";
   int* ss = new int[9];
   ss = getSSN();
   
   for(int i = 0; i < 3; i++)
   {
      cout << ss[i];
   }
   cout << '-';
   for(int i = 3; i < 5; i++)
   {
      cout << ss[i];
   }
   cout << '-';
   for(int i = 5; i < 9; i++)
   {
      cout << ss[i];
   }
   cout << endl;
   cout << "NSHE ID: ";
   for(int i = 0; i < 10; i++) 
   {
      cout << nshe[i];
   }
   cout << endl;
   cout << "Major: " << major << endl;
   cout << "GPA: " << gpa << endl;
}
