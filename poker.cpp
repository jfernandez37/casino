//Programmer: Joseph Fernandez
//Date: 12/6/20

#include <iostream>
#include <cstring>
#include "poker.h"
using namespace std;

poker::poker(){//constructor
	seedBal = 0;
}

void poker::playPoker(){//main function which plays the game
	char play = 'a';//for the users choice if they want to play
	cout << "Welcome to the Casino Poker Game!" << endl;
	while (seedBal < 1){//sets the seed balance
		cout << "Please enter an amount of money to play with: " << endl;
		cin >> seedBal;
		if(seedBal < 1){
			cout << "Please enter an amount one dollar or greater." << endl;
		}
	}
	while(play != 'n' && play != 'N' && play != 'y' && play != 'Y'){//asks the user if tey want to play or not
	cout << "Do you want to play a game of poker? (Y,N): ";
	cin >> play;
	if(play != 'n' && play != 'N' && play != 'y' && play != 'Y'){
		cout << "Please choose either \"Y\" or \"N\" to continue" << endl;
	}
	}
	while(play == 'Y' || play =='y'){//runs if the user wants to play
		bet = seedBal+1;//to set the bet correctly
		while(bet > seedBal){//makes sure that the bet is less than the seed bal
			cout << "How much would you like to bet: ";
			cin >> bet;
			if(bet > seedBal){
				cout << "The bet that you entered is less then the amount you have. Please try again." << endl;
			}
		}
		shuffleCard();//shuffles the deck
		getPokerHand(hand);//gets the hand from the card class
		display(5, hand);//displays the hand
		pokerRedraw(hand);//asks the user if they want to redraw their cards or not
		display(5, hand);//displays the hand after redrawing
		checkWin();//checks if the user has won
		resetNextCard();//resets the next card in the deck
		endingBal = seedBal + bet;//adds or subtracts what the user has won or lost
		cout << "Your initial balance was: $" << seedBal << endl;
		cout << "Your current balance is: $" << endingBal << endl;
		seedBal = endingBal;//sets the seed balance to the new balance
		if(bet > 0){//runs if the user has won money
			cout << "You win $" << bet << endl;
		}
		else{//runs if the user has lost money
			cout << "You lose $" << bet << endl;
		}
		do{//asks if the user would like to play again
			cout << "Would you like to play again? (Y, N):";
			cin >> play;
			if(play != 'n' && play != 'N' && play != 'y' && play !='Y'){
				cout << "Please choose either \"Y\" or \"N\"." << endl;
			}
		}while(play != 'n' && play != 'N' && play != 'y' && play != 'Y');
		resetNextCard();//resets the next card
	}
}

bool poker::jPair(){//checks for a pair of jacks or higher
	for(int i = 0; i < 4; i++){
		if(hand[i].num == hand[i+1].num && (hand[i].num > 10 || hand[i].num ==1)){
				return true;
				}
	}
	return false;
}

bool poker::twoPair(){//checks for two pairs
	for(int i = 0; i < 2; i++){
		if((hand[i].num == hand[i+1].num && hand[i+2].num == hand[i+3].num)|| (hand[0].num == hand[1].num && hand[3].num == hand[4].num)){
			return true;
		}
	}
	return false;
}

bool poker::triple(){//checks for three of a kind
	for(int i = 0; i < 3; i++){
		if(hand[i].num == hand[i+1].num && hand[i].num == hand[i+2].num){
			return true;
		}
	}
	return false;
}

bool poker::straight(){//checks for a straight
	if(hand[0].num == 1){
		if(hand[1].num +1 == hand[2].num && hand[2].num + 1 == hand[3].num && hand[3].num +1 == hand[4].num && hand[4].num == 13){
			return true;
		}
	}
	else if(hand[0].num + 1 == hand[1].num && hand[1].num +1 == hand[2].num && hand[2].num + 1 == hand[3].num && hand[3].num + 1 == hand[4].num){
		return true;
	}
	return false;
}

bool poker::flush(){//checks for a flush
	if(strcmp(hand[0].pic, hand[1].pic) == 0 && strcmp(hand[1].pic, hand[2].pic) == 0 && strcmp(hand[2].pic, hand[3].pic) == 0 && strcmp(hand[3].pic, hand[4].pic) == 0){
		return true;
	}
	else{
		return false;
	}
}

bool poker::fullHouse(){//checks for a full house
	if(hand[0].num == hand[1].num && hand[0].num == hand[2].num && hand[3].num == hand[4].num){
		return true;
	}
	else if(hand[0].num == hand[1].num && hand[2].num == hand[3].num && hand[4].num == hand[3].num){
		return true;
	}
	return false;
}

bool poker::fourCard(){//checks for a four of a kind
	for(int i = 0; i < 2; i++){
		if(hand[i].num ==hand[i+1].num && hand[i].num == hand[i+2].num && hand[i].num == hand[i+3].num){
			return true;
		}
	}
	return false;
}

bool poker::straightFlush(){//checks for a straight flush
	if(straight() && flush()){
		return true;
	}
	else{
		return false;
	}
}

bool poker::royalStraightFlush(){//checks for a royal straight flush
	int min = 14;
	if(hand[0].num != 1){
		min = hand[0].num;
	}
	for(int i = 1; i < 5; i++){
		if(hand[i].num < min && hand[i].num != 1){
			min = hand[i].num;
		}
	}
	if(min == 10 && straightFlush()){
		return true;
	}
	else{
		return false;
	}
}
void poker::checkWin(){//checks if the user has won and sets the bet accordingly
	sortHand();//sort the hand
	if(royalStraightFlush()){
		cout << "Royal Straight Flush!" << endl;
		bet = bet * 10000;
	}
	else if(straightFlush()){
		cout << "Straight Flush!" << endl;
		bet = bet*1000;
	}
	else if(fourCard()){
		cout << "Four of a kind!" << endl;
		bet = bet*20;
	}
	else if(fullHouse()){
		cout << "Full House!" << endl;
		bet = bet*10;
	}
	else if(flush()){
		cout << "Flush" << endl;
		bet = bet*8;
	}
	else if(straight()){
		cout << "Straight" << endl;
		bet = bet*6;
	}
	else if(triple()){
		cout << "Three of a kind" << endl;
		bet = bet*4;
	}
	else if(twoPair()){
		cout << "Two Pair" << endl;
		bet = bet*2;
	}
	else if(jPair()){
		cout << "Pair of Jack or Higher" << endl;
		bet = bet;
	}
	else{
		cout << "Nothing" << endl;
		bet = bet*-1;
	}
}

void poker::sortHand(){//sorts the hand in order
	int min;
	for(int i = 0; i < 4; i++){
		min = i;
		for(int j = i; j < 5; j++){
			if(hand[j].num <= hand[min].num){
				min = j;
			}
		}
			swap(hand[i], hand[min]);
	}
}

