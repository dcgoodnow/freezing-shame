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
		
	card second( 1 , "Unshuffled" );
	second.print();

		
	// Declare card with parametrized constructor
	
	card third( 2 , 'G' , "Action" , "Location" );
	third.print();

	// Initialize a card with the copy constructor
		
	card fourth( second );
	fourth.print();

		
	// Test the setters

	first.setRank( 3 );
	first.setColor( 'B' );
	first.setLocation( "Joe" );
	first.setAction( "DrawTwo" );

	// Test the getters
		
	cout << endl;
	cout << third.getRank() << endl;
	cout << third.getColor() << endl;
	cout << third.getLocation() << endl;
	cout << third.getAction() << endl;

	// Declare a card pointer
		
	card* miniDeck = NULL;

	// What constructor is called here?
		
	miniDeck = new card[ 4 ];

	// Loop through the deck

	for( int i = 0 ; i < 4 ; i++ )
	{
	
		// Test the copy card member function
		
		miniDeck[ i ].copyCard( fourth );
		miniDeck[ i ].print();
	}

	// What function is called here?
	
	delete[] miniDeck;
	miniDeck = NULL;
	
	// Test const; should other functions be called also?

	const card five (5, 'G', "Bob", "Action");
	five.print();
	cout << five.getRank() << endl;
	cout << five.getColor() << endl;
	cout << five.getLocation() << endl;
	cout << five.getAction() << endl;



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

	int* tempID = new int[5];
	
	for( int i = 0 ; i < 8 ; i++ )
	{
		// store an id into tmpID

		for (int j = 0; j < 5; j++)
			tempID[j] = i+j;


		allPlayers[ i ].setName( "Bob" );
		allPlayers[ i ].setID( tempID );
		allPlayers[ i ].print();

	}


	// Test the getters
	
	cout << allPlayers[0].getName() << endl;
	cout << allPlayers[0].getID() << endl;

	int* idPtr = allPlayers[0].getID();

	for( int i = 0 ; i < 5 ; i++ )
		{

			cout << idPtr[ i ];

		}

	// What function is called here?
	
	delete[] allPlayers;
	allPlayers = NULL;

	// Return End
	
	return 0;

}
