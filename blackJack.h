//Programmer: Joseph Fernandez
//Date: 12/6/20

#include "card.h"
#ifndef BLACKJACK_H
#define BLACKJACK_H

class blackJack : public card{
	private:
		aCard playHand[11];//holds the players hand
		aCard compHand[11];//holds the computers hand
		aCard compDisplay[11];//for displaying the first card and then the correct amount of blanks
		int playVal[11];//holds the card values for the players hand
		int compVal[11];//holds the card values for the computers hand
		int playTot;//holds the total of the players values
		int compTot;//holds the total of the computers values
		int playCount;//counts how many cards the player has
		int compCount;//counts how many cards the computer has
		bool insurance = false;//holds whether or not the player wants insurance
		int seedBal;//holds the seed balance
		int bet;//holds the players bet
		int endingBal;//holds the balance after the bet
	public:
		blackJack();//constructor
		void playBlackJack();//plays the game an runs the correct functions
		void playComp();//plays for the computer
		void checkInsurance();//checks if the computers hand allows for insurance
		int checkOver();//checks to see if either of the hands has gone over 21
		int checkBlackJack();//checks to see if there is a black jack
		int checkWin();//checks after the user decides to stay
		bool compCheck();//to decide if the computer should play
		void setValPlay(int);//sets the card values for the player
		void setValComp();//sets the card values for the computer
};
#endif
