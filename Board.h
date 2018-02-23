#include <vector>
#include "Hand.h"
#include "Card.h"
#ifndef BOARD_H 
#define BOARD_H 
class Board
{
public:
	Board(int);
	~Board();
	void AddHand();
	void RemoveHand(int);
	void GiveCard(int,Card*);
	Card* TakeCard(int);
	void TableFlip(Card*);
	Card* TakeTableCard();
	void ShowHand(int);
	void ShowTableCard(int);
	bool StraightPoss();
	bool FlushPoss();
	vector<int> CheckFlush();
	vector<int> CheckStraight();
private:
	/* data */
	std::vector<Card*> Table;	
	std::vector<Hand*> Hands; 
};


#endif /* ifndef SYMBOL */
