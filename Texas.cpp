#include "Texas.h"
#include "Board.h"
#include "Deck.h"
#include <iostream> 

Texas::Texas(int NumPlayStart){
	TxBoard = new Board(NumPlayStart);
	TxDeck = new Deck();
	Players = NumPlayStart;
	NumCardsDown = 0;
}

void Texas::Deal(){
	for (int i = 0; i < 5; i++) {
		TxDeck -> shuffle();
	}
	for (int i = 0; i < 2; i++) {
		for (int i = 0; i < Players; i++) {
			TxBoard -> GiveCard(i,TxDeck -> flip());
		}
	}
}
void Texas::Flop(){
	for (int i = 0; i < 3; i++) {
		Flip();
	}
	NumCardsDown = 3;
}
void Texas::Turn(){
	Flip();
	NumCardsDown ++;
}
void Texas::River(){
	Flip();
	NumCardsDown ++;
}
void Texas::Flip(){
	TxBoard -> TableFlip(TxDeck -> flip());
}
void Texas::Shuffle(){
	TxDeck -> shuffle();
}
void Texas::Reset(){
	Card* Holder = NULL;
	 for (int i = 0; i <2; i++) {
	 	for (int i = 0; i < Players; i++) {
			Holder = TxBoard -> TakeCard(i);							
			TxDeck -> take(Holder);
	 	}
	 }
	 for (int i = 0; i < 5; i++) {
	 	Holder = TxBoard -> TakeTableCard();
		TxDeck -> take(Holder);
	 }
	 NumCardsDown = 0;
}
void Texas::ShowTable(){
	std::cout << endl;
	for (int i = 0; i < NumCardsDown; i++) {
		TxBoard -> ShowTableCard(i);	
	}
	std::cout << endl;
	std::cout << endl;
}

void Texas::ShowHand(int PlayerNum){
	TxBoard-> ShowHand(PlayerNum);
	cout << endl;
}
void Texas::CheckStraight(){
	if (TxBoard->StraightPoss())
		cout << "Straight Open" << endl;
	else cout << "Straight Impossible" << endl;
}
void Texas::CheckFlush() {
	if (TxBoard -> FlushPoss())
		cout << "Flush Possible" << endl;
	else cout << "Flush Impossible" << endl;
}
void Texas::ValidateFlush(){
	vector<int> Flushes = TxBoard->CheckFlush();
}
void Texas::ValidateStraight(){
	vector<int> Flushes = TxBoard->CheckStraight();
}
