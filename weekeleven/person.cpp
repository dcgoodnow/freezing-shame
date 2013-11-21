#include "person.h"
#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;

person::person()
{
   first = new char[30];
   last = new char [30];
   age = 0;
   ssn = new int[9];
   cout << "Person Constructing..." << endl;
}

person::person(const person& p)
{
   first = new char[30];
   int i = 0;
   while(p.first[i] != '\0')
   {
      first[i] = p.first[i];
      i++;
   }
   first[i] = '\0';
   last = new char[30];
   i = 0;
   while(p.last[i] != '\0')
   {
      last[i] = p.last[i];
      i++;
   }
   last[i] = '\0';
   age = p.age;
   ssn = new int[9];
   for(i = 0; i < 9; i++)
   {
      ssn[i] = p.ssn[i];
   }
   cout << "Person Constructing..." << endl;
}

person::~person()
{
   delete[] first;
   first = NULL;
   delete[] last;
   last = NULL;
   delete[] ssn;
   ssn = NULL;
   age = 0;
}

void person::setFirst(const char* n) 
{
   int i = 0; 
   while(n[i] != '\0')
   {
      first[i] = n[i];
      i++;
   }
   first[i] = '\0';
}

void person::setLast(const char* n)
{
   int i = 0; 
   while(n[i] != '\0')
   {
      last[i] = n[i];
      i++;
   }
   last[i] = '\0';
}

bool person::setAge(int n)
{
   if(n >= 0 && n <= 120)
   {
      age = n;
      return true;
   }
   return false;
}

void person::setSSN(const int* s)
{
   for(int i = 0; i < 9; i++)
   {
      ssn[i] = s[i];
   }
}

char* person::getFirst() const
{
   return first;
}

char* person::getLast() const
{
   return last;
}

int person::getAge() const 
{
   return age;
}

int* person::getSSN() const 
{
   return ssn;
}

void person::print() const
{
   cout << last << ", " << first << endl;
   cout << "Age: " << age << endl;
   cout << "SSN: ";
   for(int i = 0; i < 3; i++)
   {
      cout << ssn[i];
   }
   cout << '-';
   for(int i = 3; i < 5; i++)
   {
      cout << ssn[i];
   }
   cout << '-';
   for(int i = 5; i < 9; i++)
   {
      cout << ssn[i];
   }
   cout << endl;
}

void person::read(ifstream& file)
{
   char temp;
   char* tempStr = new char[30];
   file >> temp;
   file.get(tempStr, 30, ':');
   StringCopy(tempStr, first);
   file >> temp;
   file.get(tempStr, 30, ':');
   StringCopy(tempStr, last);
   file >> temp;
   file >> age;
   file >> temp;
   int* tempSSN = new int[10];
   file.get(tempStr, 30, ':');
   for(int i = 0; i < 9; i++)
   {
      tempSSN[i] = tempStr[i] - 48;
   }
   setSSN(tempSSN);
}
