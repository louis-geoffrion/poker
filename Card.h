#include <string>
#ifndef CARD_H
#define CARD_H
using namespace std;
class Card
{
public:
	Card(int,string);
	~Card();
	void Show();
private:
	/* data */
	int Number;
	string Suit;
};

#endif /* ifndef SYMBOL */
