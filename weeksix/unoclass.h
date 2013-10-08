class card {
   public:
      void init();
      void SetColor(char);
      void SetRank(int);
      void SetAction(char*);
      void SetLocation(char*);
      char GetColor();
      int GetRank();
      char* GetAction();
      char* GetLocation();
      void print();
      void CopyCard(card&);
   private:
      char color;
      int rank;
      char* action;
      char* location;
};

class player {
   public:
      void init();
      void SetName(char*);
      char* GetName();
      void SetID(int*);
      int* GetID();
      void SetHand(card*);
      card* GetHand();
      void print();

   private:
      char* name;
      int* id;
      card* hand;
};
