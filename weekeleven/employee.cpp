#include "employee.h"
#include <iostream>
#include "string.h"

using namespace std;

employee::employee()
{
   id = new int[5];
   title = new char[30];
   salary = 0;
   cout << "Employee Constructing..." << endl;
}

employee::employee(const employee& e)
{
   first = new char[30];
   int i = 0;
   while(e.first[i] != '\0')
   {
      first[i] = e.first[i];
      i++;
   }
   first[i] = '\0';
   last = new char[30];
   i = 0;
   while(e.last[i] != '\0')
   {
      last[i] = e.last[i];
      i++;
   }
   last[i] = '\0';
   age = e.age;
   setSSN(e.getSSN());
   id = new int[5];
   for(int i=0; i < 5; i++)
      id[i] = e.id[i];
   title = new char[30];
   int j = 0;
   while(e.title[j] != '\0')
   {
      title[j] = e.title[j];
      j++;
   }
   title[j] = '\0';
   salary = e.salary;
   cout << "Employee Constructing..." << endl;
}

employee::~employee()
{
   delete[] id;
   id = NULL;
   delete[] title;
   title = NULL;
}


bool employee::setID(int* t)
{
   //prevent user from passing in bad IDs
   for(int i = 0; i < 5; i++)
   {
      if(t[i] < 0 || t[i] > 9)
         return false;
   }
   for(int i = 0; i < 5; i++)
   {
      id[i] = t[i];
   }
   return true;
}

void employee::setTitle(const char* t)
{
   int i = 0;
   while(t[i] != '\0')
   {
      title[i] = t[i];
      i++;
   }
   title[i] = '\0';
}

bool employee::setSalary(int s)
{
   if(s < 0)
      return false;
   salary = s;
   return true;
}

int* employee::getID() const
{
   return id;
}

char* employee::getTitle() const
{
   return title;
}

int employee::getSalary() const
{
   return salary;
}

void employee::print() const
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
   cout << "Title: " << title << endl;
   cout << "ID: ";
   for(int i = 0; i < 5; i++)
   {
      cout << id[i];
   }
   cout << endl;
   cout << "Salary: " << salary << endl;
}

void employee::read(ifstream& file)
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
   int* tempSSN = new int[9];
   file.get(tempStr, 30, ':');
   for(int i = 0; i < 9; i++)
   {
      tempSSN[i] = tempStr[i] - 48;
   }
   setSSN(tempSSN);
   file >> temp;
   file.get(tempStr, 30, ':');
   for(int i = 0; i < 5; i++)
   {
      id[i] = tempStr[i] - 48;
   }
   file >>temp;
   file.get(tempStr, 30, ':');
   StringCopy(tempStr, title);
   file >> temp;
   file >> salary;
}
