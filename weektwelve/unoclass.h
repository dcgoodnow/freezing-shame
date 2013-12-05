#include <iostream>
#include "list.h"
using namespace std;
class card {
   public:
      card(int r = -1, const char* l = "Location");
      card(int, char, const char*, const char*);
      card(const card&);
      ~card();
      card operator=(const card&);
      friend ostream& operator<<(ostream&, const card&);
      friend istream& operator>>(istream&, card&);
      bool operator<(const card&);
      friend bool operator>(const card&, const card&);
      void setColor(char);
      void setRank(int);
      void setAction(const char*);
      void setLocation(const char*);
      char getColor() const;
      int getRank() const;
      char* getAction() const;
      char* getLocation() const;
      void print() const;
      void copyCard(card);
      void Swap(card&);
   private:
      char color;
      int rank;
      char* action;
      char* location;
};

class player {
   public:
      player();
      player(const player&);
      ~player();
      player operator=(const player&);
      friend ostream& operator<<(ostream&, player&);
      friend istream& operator>>(istream&, player&);
      void setName(const char*);
      char* getName() const;
      void setID(int*);
      int* getID() const;
      bool removeCard(card&);
      bool addCard(card);

   private:
      char* name;
      int* id;
      list<card> hand;
};
