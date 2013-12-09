#ifndef __LIST_H_
#define __LIST_H_
#include <iostream>

using namespace std;

template <typename T>
class list;

template <typename T>
class queue;


template <typename T>
class node{
   private:
      node(T , node<T>*);
      T data;
      node<T>* next;
      friend class list<T>;
      friend class queue<T>;
};

template <typename T>
class list{
   public:
      list(int = 0);
      list(const list<T>&);
      ~list();
      bool gotoBeginning();
      bool gotoEnd();
      bool gotoNext();
      bool gotoPrior();
      bool insertAfter(T);
      bool insertBefore(T);
      bool remove(T&);
      bool replace(T);
      bool getCursor(T&) const;
      bool empty() const;
      bool full() const;
      bool clear();
      list& operator=(const list&);
      bool operator==(const list<T>& l) const;
   private:
         node<T>* head;
         node<T>* cursor;
};

template <typename T>
class queue{
   public:
      queue();
      queue(const queue<T>&);
      ~queue();
      bool enqueue(T);
      bool dequeue(T&);
      bool empty() const;
      bool full() const;
      bool clear();
      queue& operator=(const queue<T>&);
   private:
      node<T>* front;
      node<T>* back;
};

#include "list.cpp"

#endif
