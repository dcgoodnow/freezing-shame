class card {
   public:
      card(char c = 'c', int r = -1, const char* a = "Action", const char* l = "Location");
//      card(char, int, const char*, const char*);
      card(const card&);
      ~card();
      card operator=(const card&);
      void SetColor(char);
      void SetRank(int);
      void SetAction(const char*);
      void SetLocation(const char*);
      char GetColor() const;
      int GetRank() const;
      char* GetAction() const;
      char* GetLocation() const;
      void print() const;
      void CopyCard(card);
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
      player operator=(const player&);
      void SetName(char*);
      char* GetName() const;
      void SetID(int*);
      int* GetID() const;
      void SetHand(card*);
      card* GetHand() const;
      void print() const;

   private:
      char* name;
      int* id;
      card* hand;
};
