#include "Board.h"

Board::Board(int NumPlayers)
{	// Initialized with number of players
	for (int i = 0; i < NumPlayers; i++) {
		Hands.push_back(new Hand());
	}
}
