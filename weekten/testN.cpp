#include <iostream>
#include "listN.cpp"

int main()
{
   List l1;
   l1.insertAfter('a');
   cout << l1 << endl;
   for(int i = 0; i < 10; i++)
   {
      l1.insertAfter(i+48);
   }
   l1.insertBefore('b');
   cout << l1 << endl;
   char t;
   l1.getCursor(t);
   cout << t << endl;
   l1.gotoPrior();
   l1.remove(t);
   cout << l1 << endl;
   l1.replace('d');
   cout << l1 << endl;
   l1.gotoBeginning();
   l1.insertBefore('l');
   cout << l1 << endl;
   l1.gotoEnd();
   l1.insertAfter('e');
   cout << l1 << endl;
   List l2;
   l2.insertBefore('z');
   cout << l2 << endl;
   l2 = l1;
   cout << l2 << endl;
   List l3;
   for(int i = 0; i < 250; i++)
   {
      l3.insertAfter('w');
   }
   l3.clear();
   List l4(l2);
   cout << l4 << endl;
   l4.gotoBeginning();
   l4.gotoPrior();
   l4.getCursor(t);
   cout << t << endl;
   l4.gotoNext();
   cout << l4 << endl;
   l4 = l2;
   if(l4 == l2)
      cout << "not working" << endl;
}
