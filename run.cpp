#include <iostream>
#include "Deck.h"
#include "Texas.h"
#include <string>
using namespace std;
void BuildScreen(Texas*);
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
	BuildScreen(Game);
	cout << "Press 1 to see the flop";
	cin >> flop ;
	system("clear");
	Game -> Flop();	
	BuildScreen(Game);	
	cout  <<  "Press 1 to see the turn" << endl;
	flop = 0;
	cin >> flop;
	flop = 0;
	system("Clear");
	Game -> Turn();
	BuildScreen(Game);
	cout << "Turn" << endl;
	cout << "Press 1 to see the river" << endl;
	flop = 0;
	cin >> flop;
	system("Clear");
	Game -> River();
	BuildScreen(Game);
	cout << "River" << endl;
	Game -> CheckStraight();
	Game -> CheckFlush();	
	Game -> ValidateFlush();
	Game -> ValidateStraight();
}
void BuildScreen (Texas* Game) {
	cout << "TEXAS HOLDEM" << endl << endl;
	Game -> ShowTable();
	Game -> ShowHand(1);
	cout << endl << endl;
}
