#ifndef __LISTN_H_
#define __LISTN_H_
#include <iostream>

using namespace std;

class ListN;

class Node{
	private:
		Node(int, Node*);
		int data;
		Node* next;
		friend class ListN;
                friend ostream& operator<<(ostream&, const ListN&);
};

class ListN{
        public:
                ListN(int = 0);
                ListN(const ListN&);
                ~ListN();
		bool gotoBeginning();
		bool gotoEnd();
		bool gotoNext();
                bool gotoPrior();
		bool insertAfter(int);
		bool insertBefore(int);
                bool remove(int&);
		bool replace(int);
		bool getCursor(int&) const;
                bool empty() const;
                bool full() const;
                bool clear();
		ListN& operator=(const ListN&);
                friend ostream& operator<<(ostream&, const ListN&);
                bool operator==(const ListN&) const;
                friend class List;
        private:
		Node* head;
		Node* cursor;
};

#endif
