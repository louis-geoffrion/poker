#include <iostream>
#include "Deck.h"
#include "Texas.h"
#include <string>
using namespace std;
void BuildScreen(Texas*,int);
int main(int argc, const char *argv[])
{
	system("clear");
	cout << "Welcome to Texas Holdem" << endl;
	cout << "\n \n How many players?" << endl;
	int NumPlayers = 0;
	cin >> NumPlayers ;	
	Texas* Game = new Texas(NumPlayers);
	int flop = 0;
	Game -> Deal();
	system("clear");
	BuildScreen(Game,NumPlayers);
	cout << "Press 1 to see the flop";
	cin >> flop ;
	system("clear");
	Game -> Flop();	
	BuildScreen(Game,NumPlayers);	
	cout  <<  "Press 1 to see the turn" << endl;
	flop = 0;
	cin >> flop;
	flop = 0;
	system("Clear");
	Game -> Turn();
	BuildScreen(Game,NumPlayers);
	cout << "Turn" << endl;
	cout << "Press 1 to see the river" << endl;
	flop = 0;
	cin >> flop;
	system("Clear");
	Game -> River();
	BuildScreen(Game,NumPlayers);
	cout << "River" << endl;
	Game -> CheckStraight();
	Game -> CheckFlush();	
	Game -> ValidateFlush();
	Game -> ValidateStraight();
}
void BuildScreen (Texas* Game,int NumP) {
	cout << "TEXAS HOLDEM" << endl << endl;
	Game -> ShowTable();
	for (int i = 0; i < NumP; i++){ 
		cout << "Player " << i << " :   " ;
		Game -> ShowHand(i);
	}
	cout << endl << endl;
}
