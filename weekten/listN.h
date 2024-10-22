#ifndef __LIST_H_
#define __LIST_H_
#include <iostream>

using namespace std;

class List;

class Node{
	private:
		Node(char, Node*);
		char data;
		Node* next;
		friend class List;
                friend ostream& operator<<(ostream&, const List&);
};

class List{
        public:
                List(int = 0);
                List(const List&);
                ~List();
		bool gotoBeginning();
		bool gotoEnd();
		bool gotoNext();
                bool gotoPrior();
		bool insertAfter(char);
		bool insertBefore(char);
                bool remove(char&);
		bool replace(char);
		bool getCursor(char&) const;
                bool empty() const;
                bool full() const;
                bool clear();
		List& operator=(const List&);
                friend ostream& operator<<(ostream&, const List&);
                bool operator==(const List&) const;
        private:
		Node* head;
		Node* cursor;
};

#endif
