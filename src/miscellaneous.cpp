#include<iostream>
#include "miscellaneous.h"
using namespace std;
miscellaneous::miscellaneous() {
	// TODO Auto-generated constructor stub

}

miscellaneous::~miscellaneous() {
	// TODO Auto-generated destructor stub
}

int miscellaneous::printWelcomeScreen(){
    int ch;

    //For Printing "Tic Tac Toe" In a Stylish Way.
    cout<<endl<<" _____ _        _____             _____           "<<endl<<"/__   (_) ___  /__   \\__ _  ___  /__   \\___   ___ "<<endl;
    cout<<"  / /\\| |/ __|   / /\\/ _` |/ __|   / /\\/ _ \\ / _ \\"<<endl<<" / /  | | (__   / / | (_| | (__   / / | (_) |  __/"<<endl;
    cout<<" \\/   |_|\\___|  \\/   \\__,_|\\___|  \\/   \\___/ \\___|"<<endl<<endl;

    //Print Choices
    cout<<"1. Play Game "<<"2. How to Play "<<"3. Credits "<<endl;
    cout<<endl<<"Enter Your Choice"<<endl;
    cin>>ch;
     if(cin.fail() != 0)
   {
       cout << "Hey! That's not valid input! Try again.\n\n";
       cin.clear();//Clears Error Flag
       cin.ignore(10000,'\n');//skips to the next newline (to ignore anything else on the same line as the non-number so that it does not cause another parse failure)
   }
   choiceSelection(ch);
   return 0;
}

int miscellaneous::choiceSelection(int ch){
    switch(ch){
    case 1: break;
    case 2: showHelp();break;
    case 3: showCredits();break;
    default: {
            cout<<"Wrong Choice dude!! Use your keyboard Properly next time"<<endl;
            printWelcomeScreen();
            break;
            }
    }
    return 0;
}

void miscellaneous::showHelp(){
    //Print Help Text
cout<<"X always goes first."<<endl<<"Players alternate placing Xs and Os on the board until either"<<endl<<"(a) one player has three in a row, horizontally, vertically or diagonally; or "<<endl<<"(b) all nine squares are filled."<<endl<<"If a player is able to draw three Xs or three Os in a row, that player wins."<<endl<<"If all nine squares are filled and neither player has three in a row, the game is a draw."<<endl;
printWelcomeScreen();
}

void miscellaneous::showCredits(){
    //Print Credits
cout<<"Created By:- \nBaishali Sarkar \nMoumita Maiti \nPuja Gupta \nVikas Kumar  "<<endl;
printWelcomeScreen();
}
