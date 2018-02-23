#include <string>
#ifndef CARD_H
#define CARD_H
using namespace std;
class Card
{
public:
	Card(int,char);
	~Card();
	void Show();
	int QNumber();
	char QSuit(); 
private:
	/* data */
	int Number;
	char Suit;
};

#endif /* ifndef SYMBOL */
