#include <iostream>
#include <fstream>
#include "listA.h"
#include "listN.h"

using namespace std;

void BubbleSort(ListN&);
int BinarySearch(List, int);

int main() 
{
   //load in values
   cout << "What is the name of the file? ";
   char* temp = new char[30];
   cin >> temp;
   ifstream inFile;
   inFile.open(temp);
   ListN rawVals;
   int tempInt;
   while(inFile.good())
   {
      inFile >>tempInt;
      rawVals.insertAfter(tempInt);
   }
   rawVals.remove(tempInt);
   inFile.close();
   //sort the values
   BubbleSort(rawVals);
   //move values to array based list
   List sorted(rawVals);
   cout << "What number are you looking for? ";
   cin >> tempInt;

   //search for the desired number
   int result = BinarySearch(sorted, tempInt);
   if(result < 0)
      cout << "That number is not in the provided list" << endl;
   else
      cout << "The location is " << result << endl;
   

   delete[] temp;
   return 0;
}

void BubbleSort(ListN& l)
{
   bool swapped = true;
   bool notAtEnd = true;
   int temp1;
   int temp2;
   int i = 0;
   while(swapped)
   {
      swapped = false;
      l.gotoBeginning();
      l.getCursor(temp1);
      notAtEnd = l.gotoNext();
      l.getCursor(temp2);

      //swap if out of order
      if(temp1 > temp2)
      {
         l.replace(temp1);
         l.gotoPrior();
         l.replace(temp2);
         swapped = true;
      }
      //loop through list
      while(notAtEnd)
      {
         l.getCursor(temp1);
         notAtEnd = l.gotoNext();
         l.getCursor(temp2);
         //swap if out of order
         if(temp1 > temp2)
         {
            l.replace(temp1);
            l.gotoPrior();
            l.replace(temp2);
            swapped = true;
         }
      }
   }
}

int BinarySearch(List l, int n)
{
   l.gotoBeginning();
   int actual = 0;

   //get size of list
   while(l.gotoNext())
   {
      actual++;
   }
   actual++;
   l.gotoBeginning();
   
   //move cursor to middle of list
   for(int i = 0; i < actual/2-1; i++)
   {
      l.gotoNext();
      
   }
   int temp;
   l.getCursor(temp);

   //check for value not in list
   if(actual == 1 && temp != n)
      return -10000;

   //check for a match
   if(n == temp)
   {
      return actual/2;
   }

   //create list to pass to next level of recursion
   List next = l;
   int temp2;
   int modifier;
   if(n > temp)
   {
      next.gotoBeginning();

      //remove the lower half
      for(int i = 0; i < actual/2; i++)
         next.remove(temp2);

      //modifier adds the the amount of numbers removed from the lower half to the result
      if(actual <= 3)
         modifier = 1;
      else
         modifier = actual/2;
   }
   if(n < temp)
   {
      next.gotoBeginning();

      //remove upper half 
      for(int i = 0; i < actual/2; i++)
         next.gotoNext();
      for(int i = 0; i < actual/2; i++)
         next.remove(temp2);
      modifier = 0;
   }
   return modifier + BinarySearch(next, n);
}
