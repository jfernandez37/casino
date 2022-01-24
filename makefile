all: casino
casino: blackJack.o poker.o casino.o card.o
	g++ blackJack.o poker.o casino.o card.o -o casino

blackJack.o: blackJack.cpp
	g++ -c blackJack.cpp 

poker.o: poker.cpp
	g++ -c poker.cpp

casino.o: casino.cpp
	g++ -c casino.cpp

card.o: card.cpp
	g++ -c card.cpp
clean:
	rm -rf *o casino
