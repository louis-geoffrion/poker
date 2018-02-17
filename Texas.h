#include "Deck.h"

class Texas
{
public:
	Texas(int);
	~Texas();
	void Deal();	
private:
	/* data */
	Deck* TxDeck;
	Board* TxBoard;
};

/*
	Texas game needs to hold the cards on the board
	also needs to hold the cards the players are dealt. 
	Needs a deck
*/