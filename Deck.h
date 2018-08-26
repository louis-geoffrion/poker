/////////////////////////////////////////////////////////////
//
// \class Deck
// \brief A container of 52 cards, can be suffled and dealt
//
// The Deck class can be used to model a deck of cards. 
// This Deck operates as if it is a LIFO stack. 
// It is possible to shuffle this deck and to take the top card. 
// When a card is taken from the top of the deck it must be 
// returned using take(), this card will be put on top of the deck. 
//
/////////////////////////////////////////////////////////////

#include <vector>
#include <stack>
#include "Card.h"
#ifndef DECK_H 
#define DECK_H 
class Deck
{
public:
	Deck();
	~Deck();
	void shuffle();
	void show_all();		// Used generally for debugging purpse
	Card* flip();				// Removes card from top of deck
	void take(Card*);		// Removes card from top of deck 
private:
	/* data */
	std::stack<Card*> deck;
	std::vector<Card*> space;		// Used in shuffle operations
};
#endif /* ifndef SYMBOL */
