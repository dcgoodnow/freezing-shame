#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

template typename<T>
class queue;

template typename<T>
class node
{
	private:
		node(T, node*);
		T data;
		Node* next;
		friend class queue;
};

template typename<T>
class queue
{
   public:
      queue();
      queue(const queue&);
      ~queue();
      bool enqueue(T);
      bool dequeue(T&);
      bool empty() const;
      bool full() const;
      bool clear();
      queue& operator=(const queue&);
      friend ostream& operator<<(ostream&, const queue&);
      bool operator==(const queue&) const;
   private:
      Node* front;
      Node* back;
};

#endif
