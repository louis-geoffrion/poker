#include <stack>
#include <iostream>
#include <stdlib.h> //For random nums
#include <time.h>	//For random nums
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <stack>
Deck::Deck()
{
	Card* crdptr = NULL;
	char suits[] = {'C','S','H','D'};
	for (int i = 0; i < 4; i++) { for (int j = 1; j < 15; j++) {
				deck.push(new Card(j,suits[i]));	
			}
	}
}
void Deck::show_all()
{
	for (int i = 0; i < 56; i++){
	   space.push_back(deck.top());
	   deck.top()->Show();
	   deck.pop();
	}
	for (int i= 0; i< 56; i++){
		deck.push(space.back());
		space.pop_back();
	}
}

Card* Deck::flip()
{
	Card* flipped = deck.top();
	deck.pop();
	return flipped; 
}
		
void Deck::shuffle()
{
	for (int i = 0; i<56; i++){
		space.push_back(deck.top());
		deck.pop();
	}
	srand( time(NULL));
	int RandNum = 0;
	for (int i = 0; i<55; i++){
		RandNum = rand() % (56-i);
		deck.push(space[RandNum]);
		space.erase(space.begin() + RandNum);
	}	
	deck.push(space.back());
	space.pop_back();

}
void Deck::take(Card* card){
	deck.push(card);
}
