class card {
   public:
      card(int r = -1, const char* l = "Location");
      card(int, char, const char*, const char*);
      card(const card&);
      ~card();
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
      player(const char*, const int*, card*);
      player(const player&);
      ~player();
      void setName(const char*);
      char* getName() const;
      void setID(int*);
      int* getID() const;
      void setHand(card*);
      card* getHand() const;
      void print() const;

   private:
      char* name;
      int* id;
      card* hand;
};
