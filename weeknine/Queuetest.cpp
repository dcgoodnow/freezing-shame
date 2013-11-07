#include <iostream>
#include "Queue.h"
#include "Queue2.cpp"

int main()
{
   Queue q1;
   for(int i = 0; i < 8; i++)
   {
      q1.enqueue(i);
   }
   cout << q1;
   int temp;
   for(int i = 0; i < 7; i++)
   {
      q1.dequeue(temp);
   }
   cout << endl << q1;
   for(int i = 0; i <10; i++)
   {
      q1.enqueue(i);
   }
   cout << endl << q1 << endl;
   Queue q2(q1);
   cout << q2 << endl;
   Queue q3;
   q3.enqueue(3);
   q3 = q2;
   cout << q3 << endl;
}
