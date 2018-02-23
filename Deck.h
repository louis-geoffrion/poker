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
	void show_all();
	Card* flip();
	void take(Card*);
private:
	/* data */
	std::stack<Card*> deck;
	std::vector<Card*> space;	
};
#endif /* ifndef SYMBOL */
