/////////////////////////////////////////////////////////////
//
// \class Texas 
// \brief Texas Holdem structure and funcions
// Texas Holdem Class
// Offers all functionality to run a game of texas holdem
// Contains a deck of cards and a board at which players sit
// Each players cards are stored on the board. See board class
// Number of players can be initialized in the construcor
// currently supports checking of Flush and straight
//
/////////////////////////////////////////////////////////////

#include "Deck.h"
#include "Board.h"
#include "Hand.h"

#ifndef TEXAS_H 
#define TEXAS_H 
class Texas
{
public:
	Texas(int);		// Pass number of inital players 
	~Texas();
	void Deal();	
	void Flop();
	void Turn();
	void River();
	void Shuffle();
	void Reset();
	void ShowTable();
	void ShowHand(int);		// Pass player number 
	void CheckStraight();
	void CheckFlush();
	void ValidateFlush();
	void ValidateStraight();
private:
	/* data */
	void Flip();
	Deck* TxDeck;
	Board* TxBoard;
	int Players;
	int NumCardsDown;
};

#endif /* ifndef SYMBOL */
/*
	Texas game needs to hold the cards on the board
	also needs to hold the cards the players are dealt. 
	Needs a deck
*/
