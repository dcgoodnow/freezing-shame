
const int CARD_LENGTH = 25;

struct card
{
   char color;
   int rank;
   char action[15];
   char location[20];
};


struct player
{
   char name[20];
   int id[5];
   card hand[7];
};
/**
  *Name: PrintMenu
  *Purpose: Prints user menu
  *Args: none
  *Retval: none, prints menu 
**/
void PrintMenu(); 

/**
  *Name:    LoadDeck
  *Purpose: loads unshuffled deck from a  file
  *Args:    array for deck to be loaded into
  *Retval:  loads array
**/
void LoadDeck(card[]);

/**
  *Name:    Print Deck
  *Purpose: prints deck of cards
  *Args:    array of 108 cards 
  *retval:  none, prints deck to screen
**/
void PrintDeck(card[]);

/**
  *Name:    String Copy
  *Purpose: Copies one c-style string to another location
  *Args:    StrA (string to be copied), StrB (location to be copied to)
  *retval:  none
**/
void StringCopy(char[], char[]);

/**
  *Name:    Shuffle Deck
  *Purpose: moves the unshuffled deck to shuffled deck in random order
  *Args:    array of 108 unshuffled cards, array of 108 cards to store shuffled deck
  *Retval:  moves shuffled deck into shuffled array by pointer
**/
void ShuffleDeck(card[], card[]);

/**
  *Name:    WriteDeck
  *Purpose: Writes shuffled deck to file
  *Args:    array of 108 cards
  *Retval:  none
**/
void WriteDeck(card[], char[]);

/*
 * Name:    Initialize Deck
 * Purpose: Initialize all cards in deck to generic values
 * Args:    array of 108 cards
*/
void InitializeDeck(card[]);

/**
  *Name:    Initialize player
  *Purpose: initializes player to generic values
  *Args:    array of 4 players
  *Retval:  none
**/
void InitializePlayer(player[]);

/**
 * Name:    Load Players
 * Purpose: Loads player information from the specified player file
 * Args:    array of 4 players
*/
void LoadPlayers(player[]);

/*
 * Name:    Print Player
 * Purpose: Prints all player information to console
 * Args:    Player struct to be printed
*/
void PrintPlayer(player);

/*
 * Name:    Copy Card
 * Purpose: copies all card data from one card to another
 * Args:    card to copy from, card to be copied (by reference)
*/
void CopyCard(card, card&);

/*
 * Name:    Deal Cards
 * Purpose: moves cards to proper card arrays
 * Args:    shuffled deck of 108 cards, array of four players, deck of 108 discard cards
 *          deck of 108 draw cards
*/
void DealCards(card[], player[], card[], card[]);
