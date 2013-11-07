#include <iostream>
#include "Queue.h"
#include "Queue2.cpp"

int main()
{
   Queue q1;
   q1.enqueue(1);
   q1.enqueue(2);
   q1.enqueue(3);
   q1.enqueue(3);
   q1.enqueue(3);
   q1.enqueue(3);
   cout << q1;
   int temp;
   for(int i = 0; i < 3; i++)
   {
      q1.dequeue(temp);
   }
}
