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
	vector<int> SortedCards;
	Card * Holder = NULL;
	for (int i = 0; i < Hands.size(); i++) {
		for (int j = 0; j < 5; j++) {
			SortedCards.push_back(j);//Table[j]->QNumber());
			cout << "Add table card" << j << endl;
		}
		for (int j = 0; j < 2; j++) {
			Holder = Hands[i]->AccessCard(j);
			SortedCards.push_back(Holder->QNumber());
			cout << "add hand card " << j << endl;
		}
		sort (SortedCards.begin(),SortedCards.begin()+7);
		int diff = 0;
		int duplicates = 0;
		for (int h = 0;h  < SortedCards.size()-1-duplicates; h++) {
			if (SortedCards[h+1]-SortedCards[h]);
			else {
				SortedCards.erase(SortedCards.begin()+h);	
				duplicates++;
				h--;
			}
		}
		cout << "removed duplicates" << endl;
		for (int k = 0; k < 3-duplicates; k++) {
			diff = SortedCards[k+1]-SortedCards[k];
			if (diff == 1){
				cout << "1st card matches" << endl;
				diff = SortedCards[k+2]-SortedCards[k+1];
				if (diff == 1) {
					cout << "2nd card matches" << endl;
					diff = SortedCards[k+3]-SortedCards[k+2];
					if (diff == 1){
						cout << "3rd card matches" << endl;
						diff = SortedCards[k+4]-SortedCards[k+3];
						if (diff == 1){
							Straights.push_back(i);
							cout << "4th and 5th card match" << endl;
						}
					}
				}
			}
		}
		for (int l = 0; l < 7; l++) {
			SortedCards.pop_back();
		}
			
	}
	for (int i = 0; i < Straights.size(); i++) {
		cout << "Player " <<  Straights[i] << " has a straight" <<  endl;
	}
	return Straights;
}

