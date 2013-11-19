#include "employee.h"
#include <iostream>

using namespace std;

employee::employee()
{
   id = new int[5];
   title = new char[30];
   salary = 0;
}

employee::employee(const employee& e)
{
   id = new int[5];
   for(int i=0; i < 5; i++)
      id[i] = e.id[i];
   title = new char[30];
   int j = 0;
   while(e.title != '\0')
   {
      title[j] = e.title[j];
      j++;
   }
   title[j] = '\0';
   salary = e.salary;
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

void employee::setTitle(char* t)
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
