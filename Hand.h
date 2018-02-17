#include <vector>
#include "Card.h"
#ifndef TEXAS_H 
#define TEXAS_H 
class Hand
{
public:
	Hand();
	~Hand();
	void TakeCard(Card*);
private:
	/* data */
	std::vector<Card*> Cards;
};
#endif /* ifndef SYMBOL */
