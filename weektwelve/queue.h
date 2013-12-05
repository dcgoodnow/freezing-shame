#ifndef __QUEUE_H
#define __QUEUE_H
#include <iostream>

using namespace std;

template <typename T>
class queue;

template <typename T>
class node{
   private:
      node(T, node<T>*);
      T data;
      node<T>* next;
      friend class queue<T>;
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
      friend ostream& operator<<(ostream&, const queue<T>&);
      bool operator==(const queue<T>&) const;
   private:
      node<T>* front;
      node<T>* back;
};

#endif
