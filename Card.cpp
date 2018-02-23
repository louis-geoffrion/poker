#include "Card.h"
#include <iostream>

Card::Card(int value, char suit)
{
	Number = value;
	Suit   = suit;
}

void Card::Show()
{
	cout << "| "<< Number <<  Suit << " | " ;
}

Card::~Card()
{
}
int Card::QNumber(){
	return Number;
}
char Card::QSuit(){
	return Suit;
}
