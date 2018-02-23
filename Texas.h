#include "Deck.h"
#include "Board.h"
#include "Hand.h"

#ifndef TEXAS_H 
#define TEXAS_H 
class Texas
{
public:
	Texas(int);
	~Texas();
	void Deal();	
	void Flop();
	void Turn();
	void River();
	void Shuffle();
	void Reset();
	void ShowTable();
	void ShowHand(int);
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