#ifndef PERSON_H
#define PERSON_H

class person
{
   public:
      person();
      person(const person&);
      ~person();
      void setFirst(const char*);
      void setLast(const char*);
      bool setAge(int);
      void setSSN(const int*);
      char* getFirst() const;
      char* getLast() const;
      int getAge() const;
      int* getSSN() const;
      void print() const;

   protected:
      char* first;
      char* last;
      int age;

   private:
      int* ssn;

};
#endif
