#include "Hand.h"

Hand::Hand()
{
}

void Hand::TakeCard(Card* card)
{
	Cards.push_back(card);
}
Card* Hand::GiveCard()
{
	Card* holder = Cards.back();
	Cards.pop_back();
	return holder;
}
void Hand::ShowHand(){
	for (int i = 0; i < 2; i++) {
		Cards[i] -> Show();
	}
}

Card* Hand::AccessCard(int CardNum){
	return Cards[CardNum];
}
