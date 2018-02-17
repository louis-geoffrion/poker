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
	void AddHand(int);
	void RemoveHand(int);
private:
	/* data */
	std::vector<Card*> Table;	
	std::vector<Hand*> Hands; 
};


#endif /* ifndef SYMBOL */
