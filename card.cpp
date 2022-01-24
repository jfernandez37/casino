//Programmer: Joseph Fernandez
//Date: 12/6/20

#include "card.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

card::card(){//sets a deck of 52 cards not shuffled
	for(int i = 0; i < 51; i++){
		if(i < 13){//sets the spades cards
			cards[i].num = i+1;
			strcpy(cards[i].pic, spade);
		}
		else if(i < 26){//sets the club cards
			cards[i].num = i%13 + 1;
			strcpy(cards[i].pic, club);
		}
		else if(i < 39){//sets the hearts cards
			cards[i].num = i%13 + 1;
			strcpy(cards[i].pic, heart);
		}
		else{//sets the diamond cards
			cards[i].num = i%13 + 1;
			strcpy(cards[i].pic, diamond);
		}
	}
}

void card::shuffleCard(){//shuffles the deck of cards
	int r;//holds the random number
	srand(time(0));
	srand((unsigned)time(NULL));
	for (int i = 0; i < 51; i++){
		r = rand()%51 + 0;//generates a random number
		swap(cards[i], cards[r]);//swaps the index card with random card
	}
}

void card::swap(aCard &x, aCard &y){//swaps two cards
	int holdI;
	char holdC[4];
	holdI = x.num;
	strcpy(holdC, x.pic);
	x.num = y.num;
	strcpy(x.pic, y.pic);
	y.num = holdI;
	strcpy(y.pic, holdC);
}

aCard card::getCard(){//gets the next card from the deck
	nextCard++;
	return cards[nextCard-1];
}

void card::cardBlank(const char pic[], int &x){//prints a blank card for the computer in blackjack
	if(x==1)
	cout << "---------";
	else if(x > 1 && x < 11)
	cout << "|" << setw(8) << "|";
	else
	cout << "---------";
}

void card::cardAce(const char pic[], int &x){//each of the card functions prints a card line by line until all cards are printed
	if(x ==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "A" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(8) << "|";
	else if(x==4)
	cout << "|" << setw(8) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(8) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "A" << "|";
	else
	cout << "---------";
}

void card::cardTwo(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "2" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(8) << "|";
	else if(x==4)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(8) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==9)
	cout << "|" << setw(8) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "2" << "|";
	else
	cout << "---------";
}

void card::cardThree(const char pic[], int &x){
	if(x == 1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "3" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==4)
	cout << "|" << setw(8) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "3" << "|";
	else
	cout << "---------";
}

void card::cardFour(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "4" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x>3 && x < 9)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "4" << "|";
	else
	cout << "---------";
}

void card::cardFive(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "5" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==4)
	cout << "|" << setw(8) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "5" << "|";
	else
	cout << "---------";
}

void card::cardSix(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "6" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==4)
	cout << "|" << setw(8) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "6" << "|";
	else
	cout << "---------";
}

void card::cardSeven(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "7" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==4)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "7" << "|";
	else
	cout << "---------";
}

void card::cardEight(const char pic[],int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "8" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==4)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==5)
	cout << "|" << setw(8) << "|";
	else if(x==6)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==7)
	cout << "|" << setw(8) << "|";
	else if(x==8)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "8" << "|";
	else
	cout << "---------";
}

void card::cardNine(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "9" << setw(7) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==4)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==5)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==6)
	cout << "|" << setw(8) << "|";
	else if(x==7)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==8)
	cout << "|" << setw(8) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "9" << "|";
	else
	cout << "---------";
}

void card::cardTen(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << "10" << setw(6) << "|";
	else if(x==3)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==4)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==5)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==6)
	cout << "|" << setw(8) << "|";
	else if(x==7)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==8)
	cout << "|" << setw(6) << pic << setw(4) << "|";
	else if(x==9)
	cout << "|" << setw(4) << pic << setw(5) << pic << setw(3) << "|";
	else if(x==10)
	cout << "|" << setw(7) << "10" << "|";
	else
	cout << "---------";
}

void card::cardJack(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << pic << "J" << setw(6) << "|";
	else if(x>2 && x<10)
	cout << "|" << setw(8) << "|";
	else if(x==10)
	cout << "|" << setw(6) << "J" << pic << "|";
	else
	cout << "---------";
}

void card::cardQueen(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << pic << "Q" << setw(6) << "|";
	else if(x>2&&x<10)
	cout << "|" << setw(8) << "|";
	else if(x==10)
	cout << "|" << setw(6) << "Q" << pic << "|";
	else
	cout << "---------";
}

void card::cardKing(const char pic[], int &x){
	if(x==1)
	cout << "---------";
	else if(x==2)
	cout << "|" << pic << "K" << setw(6) << "|";
	else if(x>2 && x<10)
	cout << "|" << setw(8) << "|";
	else if(x==10)
	cout << "|" << setw(6) << "K" << pic << "|";
	else
	cout << "---------";
}

void card::display(int count, aCard hand[]){//displays the given amount of cards
	aCard tmp[count];//to hold the cards that need to printed
	int x = 1;//holds which line the print function needs to print for each card
	for(int i = 0; i < count; i++){//sets the cards which will be printed
		tmp[i] = hand[i];
	}
	for(int j = 0; j < 11; j++){//for each line of the cards
	for(int i = 0; i < count; i++){//prints the line of each card in the same row
		switch(tmp[i].num){//prints the correct card
			case 0:
				cardBlank(tmp[i].pic, x);
				break;
			case 1:
				cardAce(tmp[i].pic, x);
				break;
			case 2:
				cardTwo(tmp[i].pic, x);
				break;
			case 3:
				cardThree(tmp[i].pic, x);
				break;
			case 4:
				cardFour(tmp[i].pic, x);
				break;
			case 5:
				cardFive(tmp[i].pic, x);
				break;
			case 6:
				cardSix(tmp[i].pic, x);
				break;
			case 7:
				cardSeven(tmp[i].pic, x);
				break;
			case 8:
				cardEight(tmp[i].pic, x);
				break;
			case 9:
				cardNine(tmp[i].pic, x);
				break;
			case 10:
				cardTen(tmp[i].pic, x);
				break;
			case 11:
				cardJack(tmp[i].pic, x);
				break;
			case 12:
				cardQueen(tmp[i].pic, x);
				break;
			case 13:
				cardKing(tmp[i].pic, x);
				break;
			default:
				cout << "printing error on switch in display" << endl;
				break;
		}
	}
	cout << endl;
	x++;//goes to the next line to print
	}
}

void card::getPokerHand(aCard hand[]){//sets the starting hand for the user
	for(int i = 0; i < 5; i++){
		hand[i].num = cards[i].num;
		strcpy(hand[i].pic, cards[i].pic);
	}
}

void card::pokerRedraw(aCard hand[]){//redraws a poker hand
	int option = -1;
	for(int i = 0; i < 5; i++){//runs for each card in the hand
		while(option != 0 && option != 1){
			if(hand[i].num <=10 && hand[i].num > 1){//prints the correct number for the card
				cout << hand[i].num;
			}
			else if(hand[i].num == 1){
				cout << "A";
			}
			else if(hand[i].num == 11){
				cout << "J";
			}
			else if(hand[i].num == 12){
				cout << "Q";
			}
			else{
				cout << "K";
			}
			cout << hand[i].pic << ": Hold(1) or Redraw(0)?" ;//asks the user if they want to redraw the card or hold it
			cin >> option;
			if(option != 0 && option != 1){
				cout << "Invalid option. Please try again." << endl;
			}
		}
		if(option == 0){//redraws the card if the user decides to
			hand[i].num = cards[i+6].num;
			strcpy(hand[i].pic, cards[i+6].pic);
		}
		option = -1;
	}
}

void card::getBlackJackHands(aCard player[], aCard computer[]){
	for(int i = 0; i < 2; i++){//sets the hand for the player
		player[i].num = cards[i].num;
		strcpy(player[i].pic, cards[i].pic);
	}
	for(int i = 0; i < 2; i++){//sets the hand for the computer
		computer[i].num = cards[i+2].num;
		strcpy(computer[i].pic, cards[i+2].pic);
	}
}

void card::hit(aCard hand[], int &count1, int count2){//gives a card to the correct deck and adds 1 to the amount of cards they have in their hand
	hand[count1].num = cards[count1 + count2].num;
	strcpy(hand[count1].pic, cards[count1 + count2].pic);
	count1++;
}
