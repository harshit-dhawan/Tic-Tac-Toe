#include <iostream>
#include "miscellaneous.h"
#include "TicTacToeGame.h"
using namespace std;
int main() {
	   char input;
	    bool isDone = false;
	    //declaring object
	    TicTacToeGame game;
	    miscellaneous misc;

	    //Welcome Screen
	    misc.printWelcomeScreen();
        //Choice variable for 1 player mode or two player mode
        int ch=3;
        while(ch!=2 && ch!=1){
            if(ch!=3)
                cout<<"\nWrong Choice, Try Again"<<endl;
            cout<<"Select a choice:-\n1. Player vs Computer\n2. Player vs Player"<<endl;
            cin>>ch;
            if(cin.fail() != 0 )
            {
               cout << "\nHey! That's not valid input! Try again.\n\n";
               cin.clear();//Clears Error Flag
               cin.ignore(10000,'\n');//skips to the next newline (to ignore anything else on the same line as the non-number so that it does not cause another parse failure)
           }
        }
	    //Outer Game Loop
	    while (isDone == false) {
	        //this plays a game of tic tac toe!
	        game.playGame(ch);
	        // We have to see if they want to play again!
	        cout << "Would you like to play again? (Y/N): ";
	        cin >> input;
	        if (input == 'N' || input == 'n') {
	            isDone = true;
	        }
	    }

	    return 0;
}
