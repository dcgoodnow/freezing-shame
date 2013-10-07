class card {
   public:
      void SetColor(char);
      void SetRank(int);
      void SetAction(char*);
      void SetLocation(char*);
      char GetColor();
      int GetRank();
      char* GetAction();
      char* GetLocation();
      void print();
   private:
      char color;
      int rank;
      char* action;
      char* location;
};
