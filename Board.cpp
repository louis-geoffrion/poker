#include "Board.h"
#include <vector>
#include <algorithm>
#include <iostream>

Board::Board(int NumPlayers){	// Initialized with number of players
	for (int i = 0; i < NumPlayers; i++) {
		Hands.push_back(new Hand());
	}
}

void Board::AddHand(){
	Hands.push_back(new Hand());	
}

void Board::RemoveHand(int PlayerNum){
	Hands.erase(Hands.begin() + PlayerNum);
}	

void Board::GiveCard(int PlayerNum, Card* card){
	Hands[PlayerNum] -> TakeCard(card);
}

Card* Board::TakeCard(int PlayerNum){
	Card* holder = Hands[PlayerNum]-> GiveCard();
	Hands.pop_back();
	return holder;
}	

void Board::TableFlip(Card* FlipIt){
	Table.push_back(FlipIt);
}

void Board::ShowHand(int PlayerNum){
	Hands[PlayerNum] -> ShowHand();
}

Card* Board::TakeTableCard(){
	Card* Holder = NULL;
	Holder = Table.back();
	Table.pop_back();
	return Holder;
}
void Board::ShowTableCard(int CardNum){
	Table[CardNum]-> Show();
}
bool Board::StraightPoss(){	
	vector<int> SortedCards;
	for (int i = 0; i < 5; i++) {
		SortedCards.push_back(Table[i]->QNumber());
	}
	sort (SortedCards.begin(),SortedCards.begin()+5);
	int diff = 0;
	for (int i = 0; i < 3; i++) {
		diff = SortedCards[i+1]-SortedCards[i];
		if (diff == 1){
			diff = SortedCards[i+2]-SortedCards[i+1];
			if (diff == 1) return true; 
			else if (diff == 2) return true;
		}
		else if (diff == 2){
			diff = SortedCards[i+2]-SortedCards[i+1];
			if (diff == 1) return true;
		}			
	}
	return false;
}
bool Board::FlushPoss(){
	vector<char> SortedCards;
	for (int i = 0; i < 5; i++) {
		SortedCards.push_back(Table[i]->QSuit());
	}
	sort (SortedCards.begin(),SortedCards.begin()+5);
	for (int i = 0; i < 3; i++) {
		if (SortedCards[i] == SortedCards[i+1])
			if (SortedCards[i+1] == SortedCards[i+2])
					return true;
	}
	return false;
}
vector<int> Board::CheckFlush(){
	vector<int> Flushes;
	vector<char> SortedCards;
	Card * Holder = NULL;
	for (int i = 0; i < Hands.size(); i++) {
		for (int j = 0; j < 5; j++) {
			SortedCards.push_back(Table[j]->QSuit());
		}
		for (int j = 0; j < 2; j++) {
			Holder = Hands[i]->AccessCard(j);
			SortedCards.push_back(Holder->QSuit());
		}
		sort (SortedCards.begin(),SortedCards.begin()+7);
		for (int i = 0; i < 4; i++) {
			if (SortedCards[i] == SortedCards[i+1])
				if (SortedCards[i+1] == SortedCards[i+2])
					if (SortedCards[i+2] == SortedCards[i+3])
						Flushes.push_back(i);
		}
		for (int i = 0; i < 7; i++) {
			SortedCards.pop_back();
		}
		
	}
	for (int i = 0; i < Flushes.size(); i++) {
		cout << "Player "<< Flushes.back() << " Has a Flush" << endl;
		Flushes.pop_back();
		
	}
	return Flushes;
}

vector<int> Board::CheckStraight(){
	vector<int> Straights;
	vector<int> Cards;
	Card * Holder = NULL;
	int increment = 0;
	int duplicates =0;
	int diff = 0;
	for (int PNum = 0;PNum < Hands.size();PNum++){
		for (int i = 0; i < 5; i++) {
			Cards.push_back(Table[i]->QNumber());
		}
		for (int i = 0; i < 2; i++) {
			Holder = Hands[PNum]->AccessCard(i);
			Cards.push_back(Holder->QNumber());
		}
		sort(Cards.begin(),Cards.begin()+7);
		for (int i = 6; i > 0; i--) {
			diff = Cards[i]-Cards[i-1];
			if (diff == 0){
				Cards.erase(Cards.begin()+i);
				duplicates++;
			}
		}
		for (int i = 0; i < 3 - duplicates; i++) {
			for (int j = 0; j < 4; j++) {
				diff = Cards[i+j+1]-Cards[i+j];
				if (diff == 1)
					increment ++;	
			}
			if (increment == 4)
				Straights.push_back(PNum);
			increment =0;
		}
		for (int i = 0; i < 7 - duplicates; i++) {
			Cards.pop_back();	
		}
		duplicates = 0;
	}
	for (int i = 0; i < Straights.size(); i++) {
		cout << "Player " << Straights[i] << "Has a straight" << endl;
		
	}
	return Straights;
}

vector<pair<int,int> > Board::CheckPairs(){
	vector<pair<int,int> > Pairs;
	vector<int> Cards;
	Card * Holder = NULL;
	int PNum = 0;
	for (int i = 0; i < 5; i++) {
		Cards.push_back(Table[i]->QNumber());
	}
	for (int i = 0; i < 2; i++) {
		Holder = Hands[PNum]->AccessCard(i);
		Cards.push_back(Holder->QNumber());
	}
	return Pairs;
}
