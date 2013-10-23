///////////////////////////////////////////////////////////////////////////////
// #includes go here
///////////////////////////////////////////////////////////////////////////////
#include "uno.h"
#include <iostream>
#include "string.h"

using namespace std;

int main()
{

	/////////////////////////////////////////////////////////////////////////
	//
	// Card Testing
	// 
	/////////////////////////////////////////////////////////////////////////

	// Declare card with default constructor
	
	card first;
	first.print();

	// Declare card with default constructor and passed parameters
		
	card second( 'r' , 3 );
	second.print();

		
	// Declare card with parametrized constructor
	
	card third('G', 2 , "Action", "Shuffled");
	third.print();

	// Initialize a card with the copy constructor
		
	card fourth( second );
	fourth.print();

		
	// Test the setters

	first.SetRank( 3 );
	first.SetColor( 'B' );
	first.SetLocation( "Joe" );
	first.SetAction( "DrawTwo" );

	// Test the getters
		
	cout << endl;
	cout << third.GetRank() << endl;
	cout << third.GetColor() << endl;
	cout << third.GetLocation() << endl;
	cout << third.GetAction() << endl;

	// Declare a Card pointer
		
	card* miniDeck = NULL;

	// What constructor is called here?
		
	miniDeck = new card[ 4 ];

	// Loop through the deck

	for( int i = 0 ; i < 4 ; i++ )
	{
	
		// Test the copy card member function
		
		miniDeck[ i ].CopyCard( fourth );
		miniDeck[ i ].print();
	}

	// What function is called here?
	
	delete[] miniDeck;
	miniDeck = NULL;
	
	// Test const; should other functions be called also?

	const card five ('G', 5, "Bob", "Action");
	five.print();
	cout << five.GetRank() << endl;
	cout << five.GetColor() << endl;
	cout << five.GetLocation() << endl;
	cout << five.GetAction() << endl;



	/////////////////////////////////////////////////////////////////////////
	//
	// Player Testing
	// 
	/////////////////////////////////////////////////////////////////////////

	// Declare a Player pointer
	
	player* allPlayers = NULL;

	// What constructor is called here?
	
	allPlayers = new player[ 8 ];

	// Test the setters

	int*  tempID = new int[5];
	
	for( int i = 0 ; i < 8 ; i++ )
	{
		// store an id into tmpID

		for (int j = 0; j < 5; j++)
			tempID[j] = i+j;


		allPlayers[ i ].SetName( "Bob" );
		allPlayers[ i ].SetID( tempID );
		allPlayers[ i ].print();

	}


	// Test the getters
	
	cout << allPlayers[0].GetName() << endl;
	cout << allPlayers[0].GetID() << endl;

	// What function is called here?
	
	delete[] allPlayers;
	allPlayers = NULL;

	// Return End
	
	return 0;

}
