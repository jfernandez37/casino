//Programmer: Joseph Fernandez
//Date: 12/6/20
#ifndef CARD_H
#define CARD_H

struct aCard{//holds the information of cards
	int num;//value of the card
	char pic[4];//suit of the card
};
class card{
	private:
		aCard cards[52];//the full card deck
		const char spade[4] = "\xe2\x99\xa0";//spade character
		const char club[4] = "\xe2\x99\xa3";//club character
		const char heart[4] = "\xe2\x99\xa5";//club character
		const char diamond[4] = "\xe2\x99\xa6";//club character
		int nextCard = 0;//index for the next card for printing
	public:
		card();//constructor which sets the deck
		void resetNextCard(){nextCard = 0;}//resets the value of the next card
		void getPokerHand(aCard[]);//gets the poker hand from the deck
		void pokerRedraw(aCard[]);//redraws from the deck
		void hit(aCard[], int&, int);//hits in blackjack
		void getBlackJackHands(aCard[], aCard[]);//gets the first for cards for blackjack
		void shuffleCard();//shuffles the deck
		aCard getCard();//gets the next card from the deck for printing
		void swap(aCard &, aCard &);//swaps two cards
		void cardBlank(const char[], int&);//prints blank card for black jack computer
		void cardAce(const char[], int &);//each prints the correct card line by line
		void cardTwo(const char[], int &);
		void cardThree(const char[], int &);
		void cardFour(const char[], int &);
		void cardFive(const char[], int &);
		void cardSix(const char[], int &);
		void cardSeven(const char[], int &);
		void cardEight(const char[], int &);
		void cardNine(const char[], int &);
		void cardTen(const char[], int &);
		void cardJack(const char[], int &);
		void cardQueen(const char[], int &);
		void cardKing(const char[], int &);
		void display(int, aCard[]);//displays the correct amount of cards
};
#endif
