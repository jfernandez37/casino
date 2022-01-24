//Programmer: Joseph Fernandez
//Date: 11/29/20

#include <iostream>
#include "card.h"
#include "poker.h"
#include "blackJack.h"
using namespace std;

int main(){
	char choice = 'a';//for the user to choose which game they would like to play
	poker pDeck;
	blackJack bDeck;
	while(choice != 'q' && choice != 'Q'){//makes sure that the user does not want to quit
		do{//runs until the user has chosen a valid choice
			cout << "Would you like to play Poker (p), black jack (b), or quit (q): ";
			cin >> choice;
			if(choice != 'q' && choice != 'Q' && choice != 'p' && choice != 'P' && choice != 'b' && choice != 'B'){
				cout << "Please choose \"p\", \"b\", or \"q\" to continue." << endl;
			}
		}while(choice != 'q' && choice != 'Q' && choice != 'p' && choice != 'P' && choice != 'b' && choice != 'B');
		if(choice == 'p' || choice == 'P'){//runs if the user wants to play poker
			pDeck.playPoker();
		}
		else if(choice =='b' || choice == 'B'){//runs if the user wants to play black jack
			bDeck.playBlackJack();
		}
	}
	return 0;
}
