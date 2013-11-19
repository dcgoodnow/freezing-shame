#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "person.h"

class employee : public person 
{
   public:
      employee();
      employee(const employee&);
      ~employee();
      bool setID(int*);
      void setTitle(char*);
      bool setSalary(int);
      int* getID() const;
      char* getTitle() const;
      int getSalary() const;
      void print() const;

   private:
      int* id;
      char* title;
      int salary;
};

#endif
