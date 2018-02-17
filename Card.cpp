#include "Card.h"
#include <string>
#include <iostream>
#include <iostream>

Card::Card(int value, string suit)
{
	Number = value;
	Suit   = suit;
}

void Card::Show()
{
	cout << Number << " of " << Suit << endl;
}

Card::~Card()
{
}
