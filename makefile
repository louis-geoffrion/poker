
all: run.o Deck.o Card.o
	g++ -o program run.o Deck.o Card.o

texas: run.o Texas.o Board.o Hand.o Deck.o Card.o
	g++ -o texas run.o Texas.o Board.o Hand.o Deck.o Card.o
	
run.o: run.cpp
	g++ -c run.cpp

Texas.o: Texas.cpp Texas.h 
	g++ -c Texas.cpp

Hand.o: Hand.h Hand.cpp
	g++ -c Hand.cpp

Board.o: Board.h Board.cpp
	g++ -c Board.cpp

Deck.o: Deck.cpp Deck.h
	g++ -c Deck.cpp

Card.o: Card.cpp Card.h
	g++ -c Card.cpp
