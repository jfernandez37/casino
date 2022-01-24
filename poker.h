//Programmer: Joseph Fernandez
//Date: 12/6/20

#include "card.h"
#ifndef POKER_H
#define POKER_H
class poker: public card{
	private:
		aCard hand[5];//the players hand
		int seedBal;//holds the starting balance
		int endingBal;//holds the ending balance
		int bet;//holds the user's bet
	public:
		poker();//constructor
		void playPoker();//the main function which runs all of the other functions
		void checkWin();//checks if the user has won or not and changes the bet accordingly
		bool jPair();//checks for a pair of jacks or higher
		bool twoPair();//checks for two pairs
		bool triple();//checks for a triple
		bool straight();//checks for a straight
		bool flush();//checks for a flush
		bool fullHouse();//checks for a flush
		bool fourCard();//checks for four
		bool straightFlush();//checks for a straight flush
		bool royalStraightFlush();//checks for a royal straight flush
		void sortHand();//sorts the hand to check for a win or not
};

#endif
