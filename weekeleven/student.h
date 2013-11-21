#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <fstream>

class student : public person 
{
   public:
      student();
      student(const student&);
      ~student();
      bool setNSHE(int*);
      void setMajor(const char*);
      bool setGPA(double);
      int* getNSHE() const;
      char* getMajor() const;
      double getGPA() const;
      void print() const;
      void read(std::ifstream&);

   private:
      int* nshe;
      char* major;
      double gpa;
};

#endif
