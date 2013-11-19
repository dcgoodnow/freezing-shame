#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee : public person 
{
   public:
      employee();
      employee(const employee&);
      ~employee();
      void setID(int*);
      void setTitle(char*);
      void setSalary(int);
      int* getID() const;
      char* getTitle(char*) const;
      int getSalary() const;

   private:
      int* id;
      char* title;
      int salary;
}

#endif
