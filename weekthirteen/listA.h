#ifndef __LIST_H_
#define __LIST_H_
#include <iostream>
#include "listN.h"

using namespace std;

class List{
        public:
                List(int = 10);
                List(const List&);
                List(ListN&);
                ~List();
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
		List& operator=(const List&);
                friend ostream& operator<<(ostream&, const List&);
                bool operator==(const List&) const;
        private:
                int size;
		int actual;
                int cursor;
                int *data;
};

#endif
