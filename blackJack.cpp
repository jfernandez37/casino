//Programmer: Joseph Fernandez
//Date: 12/6/20

#include "blackJack.h"
#include <iostream>
#include <cstring>
using namespace std;

blackJack::blackJack(){//sets the starting values and the blank deck other than the first card
	playCount = 2;
	compCount = 2;
	playTot = 0;
	for(int i = 1; i < 11; i++){
		compDisplay[i].num = 0;
	}
}

void blackJack::playBlackJack(){//plays the game
	char play = 'a', hs = 'a';//for user options throughout the function
	int winner = 0;//to see if there is a winner
	cout << "Welcome to Black Jack!" << endl;
	do{//gets the seed balance from the user
		cout << "Please the amount of money that you would like to play with: ";
		cin >> seedBal;
		if(seedBal < 1){
			cout << "To play, you have to enter an amount more than $1."<< endl;
		}
	}while(seedBal < 1);
	while(play != 'n' && play != 'N' && play != 'y' && play != 'Y'){//checks to see if the user wants to play
		cout << "Do you want to play a game of black jack? (Y,N): ";
		cin >> play;
		if(play != 'n' && play != 'N' && play != 'y' && play != 'Y'){
			cout << "Please choose either \"Y\" or \"N\" to continue" << endl;
		}
	}
	while(play == 'Y' || play == 'y'){//runs if the user wants to play
		bet = seedBal+1;
		while (bet > seedBal){//sets the bet and makes sure it is less than the seed balance
			cout << "How much would you like to bet: ";
			cin >> bet;
			if(bet >= seedBal){
				cout << "The bet that you entered is less than the amount you have. Please try again." << endl;
			}
		}
		shuffleCard();//shuffles the deck
		getBlackJackHands(playHand, compHand);//gets the hand for the player and the computer
		compDisplay[0].num = compHand[0].num;//sets the first card in the blank hand to the computers first card
		strcpy(compDisplay[0].pic, compHand[0].pic);
		setValComp();//sets the values for the computers hand
		winner = checkBlackJack();//checks for a black jack
		while(winner == 0){//runs while there is no winner
			display(compCount, compDisplay);//displays both hands
			display(playCount, playHand);
			if(playCount == 2 && compCount ==2){//sets the players values
				setValPlay(1);
			}
			if(playCount == 2 && compCount == 2){//checks if the player wants insurance if it is an option
				checkInsurance();
			}
			winner = checkBlackJack();//checks for a black jack after the players values are set
			while(hs != 'h' && hs != 'H' && hs != 's' && hs != 'S'){//asks the user if they would like to hit or stay
				cout << "Would you like to hit (h) or stay (s): ";
				cin >> hs;
				if(hs != 'h' && hs != 'H' && hs != 's' && hs != 'S'){
					cout << "Please choose either \"h\" or \"s\" to continue." << endl;
				}
			}
			if(hs == 'h' || hs == 'H'){//runs if the user wants to hit
				hit(playHand, playCount, compCount);//hits for the players hand
				display(compCount, compDisplay);//displays both hands
				display(playCount, playHand);
				setValPlay(playCount);//sets the players values with the new card
				winner = checkOver();//makes sure that the user hasn't gone over 21
				if(winner == 0){
					playComp();//plays for the computer
					setValComp();//sets the computers values
					winner = checkOver();//makes sure the computer is not over
				}
			}
			else{//runs if the player stays
				while(compCheck()){//computer hits until they cannot
					playComp();
					setValComp();
					winner = checkOver();
					if(winner == 0)
					display(compCount, compDisplay);
				}
				if(winner == 0){//checks for a winner
					winner = checkWin();
				}
			}
			hs = 'a';//resets the hit or stay choice
		}
		cout << "\n\n\n\n\nComputers Hand: " << endl;//prints the final hands, showint the computers hand
		display(compCount, compHand);
		cout << "Your Hand: " << endl;
		display(playCount, playHand);
		compCount = 2;
		playCount = 2;
		playTot = 0;
		if(insurance == true && winner == 1){//sets the corect balance if insurance was chosen and the user won
			seedBal = seedBal -bet;
			bet = bet*2;
		}
		if(winner == 1 && bet !=0){//player wins
			cout << "Congratulations! You win $" << bet << endl;
			cout << "Starting balance: $" << seedBal << endl;
			endingBal = seedBal + bet;
			cout << "Ending balance: $" << endingBal << endl;
			seedBal = endingBal;
		}
		else if(winner == 2){//computer wins
			cout << "Sorry, You lose $" << bet << endl;
			cout << "Starting balance: $" << seedBal << endl;
			endingBal = seedBal - bet;
			cout << "Ending Balance: $" << endingBal << endl;
			seedBal = endingBal;
		}
		else if(bet == 0){//tie
			cout << "Tie" << endl;
			cout << "Starting balance: $" << seedBal << endl;
			cout << "Ending Balance: $" << seedBal << endl;
		}
		winner = 0;//resets who won
		do{//asks the user if they would like to play again
			cout << "Would you like to play again? (Y, N): ";
			cin >> play;
			if(play != 'y' && play !='Y' && play != 'n' && play != 'N'){
				cout << "Please enter \"Y\" or \"N\" to continue." << endl;
			}
		}while(play != 'y' && play != 'Y' && play != 'n' && play != 'N');
	}
}

void blackJack::playComp(){//plays the computers hand if they can
	if(compTot <= 16){
		hit(compHand, compCount, playCount);
	}
}

void blackJack::checkInsurance(){//checks if the user can get insurance
	char choice;
	if(compHand[0].num == 1){
		do{ //asks the user if they want insurance
			cout << "Do you want insurance? (Y, N): ";
			cin >> choice;
			if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N'){
				cout << "Please enter either \"Y\" or \"N\" to continue" << endl;
			}
		}while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
		if(choice == 'y' || choice == 'Y'){
			insurance == true;
			bet = bet/2;
		}
		else{
			insurance == false;
		}
	}
}

int blackJack::checkOver(){//checks if either hand is over 21 and returns the winner if there is a hand with more than 21
	if(compTot > 21){
		return 1;
	}
	else if(playTot > 21){
		return 2;
	}
	return 0;
}

int blackJack::checkBlackJack(){//checks for a black jack
	if((compHand[0].num == 1 && compHand[1].num == 11)||(compHand[0].num == 11 && compHand[1].num == 1)){
		return 2;
	}
	else if((playHand[0].num == 1 && playHand[1].num ==11) || (playHand[1].num ==1 && playHand[0].num == 11)){
		bet = bet * 1.5;
		return 1;
	}
	return 0;
}

int blackJack::checkWin(){//checks whos deck is higher after the user decides to stay and the computer plays
	if(compTot > playTot){
		return 2;
	}
	else if(playTot > compTot){
		return 1;
	}
	bet = 0;
	return 1;
}

bool blackJack::compCheck(){//checks if the computer can play
	if(compTot <= 16){
		return true;
	}
	return false;
}

void blackJack::setValPlay(int count){//sets the players value
	for(int i = count-1; i < playCount; i++){
		if(playHand[i].num > 9){//checks for face cards
			playVal[i] = 10;
		}
		else if(playHand[i].num == 1){//user can decide if the ace is worth 1 or 11
			do{
				cout << "Would you like the ace at position " << i+1 << " to be a 1 (1) or an 11 (11): ";
				cin >> playVal[i];
				if(playVal[i] != 1 && playVal[i] != 11){
					cout << "Please enter a 1 or an 11 to continue." << endl;
				}
			}while(playVal[i] != 1 && playVal[i] != 11);
		}
		else{//runs if the card is not a face card or an ace
			playVal[i] = playHand[i].num;
		}
		playTot = playTot + playVal[i];//sets the players total to the correct value
	}
}

void blackJack::setValComp(){//sets the computers total
	compTot = 0;
	for(int i = 0; i < compCount; i++){
		if(compHand[i].num > 9){//face cards
			compVal[i] = 10;
		}
		else if(compHand[i].num == 1){//choses 11 for an ace if it can
			 if(compTot + 11 <= 21){
				 compVal[i] = 11;
			 }
			 else{
				 compVal[i] = 1;
			 }
		}
		else{
			compVal[i] = compHand[i].num;
		}
		compTot = compTot + compVal[i];//sets the correct total for the computer's hand
	}
}

