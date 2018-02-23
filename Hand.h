#include <vector>
#include "Card.h"
#ifndef HAND_H 
#define HAND_H 
class Hand
{
public:
	Hand();
	~Hand();
	void TakeCard(Card*);
	Card* GiveCard();
	void ShowHand();
	Card* AccessCard(int);
private:
	/* data */
	std::vector<Card*> Cards;
};
#endif /* ifndef SYMBOL */
