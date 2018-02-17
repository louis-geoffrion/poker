#include <iostream>
#include "Deck.h"

int main(int argc, const char *argv[])
{
	Card* flipped = NULL;
	Deck* thatone = new Deck();
	thatone -> show_all();
	thatone -> shuffle();
	thatone -> show_all();
	flipped = thatone -> flip();
	std::cout << "Flip one up " << std::endl;
	flipped -> Show();
	return 0;
}
