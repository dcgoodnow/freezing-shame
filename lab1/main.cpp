#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
   ifstream source;
   ofstream dest;

   source.open(argv[1]);
   dest.open(argv[2]);

   while(!source.eof())
   {
      dest.put(source.get());
   }

}
