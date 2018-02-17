#include "Hand.h"

Hand::Hand()
{
}

Hand::TakeCard(Card* card)
{
	Cards.push_back(card);
}

