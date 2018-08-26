/////////////////////////////////////////////////////////////
//
// \class Card
// \brief A card with a suit and number value
//
// This class represents a card. 
// Card is created with value (number/suit) in constructor
//
/////////////////////////////////////////////////////////////


#include <string>
#ifndef CARD_H
#define CARD_H
using namespace std;
class Card
{
public:
	Card(int,char);
	~Card();
	void Show();			// Prints Number and Suit to console
	int QNumber();		// Returns Number value
	char QSuit();			// Returns Suit
private:
	/* data */
	int Number;
	char Suit;
};

#endif /* ifndef SYMBOL */
