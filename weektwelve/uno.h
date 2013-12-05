#include <fstream>
#include "unoclass.h"
#include "list.h"
#include "stack.h"
using namespace std;




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
  *Retval:  true if no errors, false if errors occur, loads array
**/
void LoadDeck(list<card>&);

/**
  *Name:    Print Deck
  *Purpose: prints deck of cards
  *Args:    array of 108 cards 
  *retval:  none, prints deck to screen
**/
void PrintDeck(list<card>);
void PrintDeck(queue<card>);


const void PrintPlayers(list<player>);

/**
  *Name:    Shuffle Deck
  *Purpose: moves the unshuffled deck to shuffled deck in random order
  *Args:    array of 108 unshuffled cards, array of 108 cards to store shuffled deck
  *Retval:  moves shuffled deck into shuffled array by pointer
**/
void ShuffleDeck(list<card>&, queue<card>&);

/**
  *Name:    WriteDeck
  *Purpose: Writes shuffled deck to file
  *Args:    array of 108 cards *Retval:  none
**/
void WriteDeck(const queue<card>&, const char* filename);

/**
 * Name:    Load Players
 * Purpose: Loads player information from the specified player file
 * Args:    array of  players, fstream object, number of players to load
*/
void LoadPlayers(list<player>, ifstream&, int);


/*
 * Name:    Deal Cards
 * Purpose: moves cards to proper card arrays
 * Args:    shuffled deck of 108 cards, array of four players, deck of 108 discard cards
 *          deck of 108 draw cards
*/
void DealCards(queue<card> deck, stack<card>&, queue<card>&, list<player>&, int);

