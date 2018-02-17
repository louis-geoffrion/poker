#include "Texas.h"
#include "Board.h"
#include "Deck.h"

Texas::Texas(int NumPlayStart)
{
	TxBoard = new Board(NumPlayStart);
	TxDeck = new Deck();
}
