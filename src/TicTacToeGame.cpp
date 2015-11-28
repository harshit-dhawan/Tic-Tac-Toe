#include "TicTacToeGame.h"
#include "cpuMove.h"
#include<iostream>
using namespace std;
TicTacToeGame::TicTacToeGame() {
	// TODO Auto-generated constructor stub

}

TicTacToeGame::~TicTacToeGame() {
	// TODO Auto-generated destructor stub
}

//The game!
void TicTacToeGame::playGame(int mark)
{
    clearBoard();
    cpuMove CPU;
    char player1 = 'X';
    char player2 = 'O';

    string player2name=getPlayerName();
    string player1name;
    if(mark==1){

        cout<<"\n1. Easy \n2. Hard"<<endl;
        int inp;
        cin>>inp;
        if(inp==1)
            CPU.setEasy(true);
        else
            CPU.setEasy(false);

        player1name="Computer";
    }
    else if(mark==2)
        player1name=getPlayerName();
    string Winner;

    char currentPlayer = player1;
    bool isDone = false;

    int x, y;

    int turn = 0;

    //Inner game loop
    while (isDone == false) {

       if(mark==2){  //For two player mode
            //Print Player Name
            if(currentPlayer==player2)
                cout<<endl<<player2name<<"'s chance";
            else
               cout<<endl<<player1name<<"'s chance";

            printBoard();
            //Print out the board each time we loop
			x = getXCoord();
			y = getYCoord();
       }

        else{ //For 1 player mode
                //Get the coordinates of where the user wants to place a marker
            if(currentPlayer==player2){
              //Print out the board each time we loop
                printBoard();


                x = getXCoord();
                y = getYCoord();
            }
            else{
                CPU.cpuMoveinit(board, turn);
                x =CPU.getCPUx();
                y =CPU.getCPUy();
                cout<<"Computer marked at "<<x+1<<", "<<y+1<<endl;
            }
        }
        //Try to place a marker
        if (placeMarker(x, y, currentPlayer) == false) {
            //If we failed to place a marker, tell him he failed!
            cout << "That spot is occupied!\n";
        } else {
            //Otherwise, we successfully did this turn!
            turn++;
            //See if the player won!
            if(turn>2){     //No need to check these until turn is greater than 2
                if (checkForVictory(currentPlayer) == true) {
                    //Deciding Winner name
                    if(currentPlayer==player1)
                        Winner=player1name;
                    else
                        Winner=player2name;

                    //Printing Greetings
                    printBoard();
                    cout << "The game is over! " << Winner << " has won!\n";
                    isDone = true;
                } else if (turn == 9) {
                    //Tie game!
                    printBoard();
                    cout << "Its a tie game!\nWell Done both "<<player1name<<" and "<<player2name<<endl;
                    isDone = true;
                }
            }

            // Switch players
            if (currentPlayer == player1) {
                currentPlayer = player2;

            } else {
                currentPlayer = player1;
            }
        }
    }
}



int TicTacToeGame::getXCoord()
{
    bool isInputBad = true;

    int x;

    while (isInputBad == true) {
        cout << "Enter the X coordinate: ";
        cin >> x;


        //To Check if cin isn't failing
        if(cin.fail() != 0)
           {
               cin.clear();
               cin.ignore(10000,'\n');
           }


        if (x < 1 || x > 3) {
            cout << "Invalid Coordinate!\n";
        } else {
            isInputBad = false;
        }
    }
    return x - 1;
}

int TicTacToeGame::getYCoord()
{
    bool isInputBad = true;

    int y;

    while (isInputBad == true) {
        cout << "Enter the Y coordinate: ";
        cin >> y;
        //To Check if cin isn't failing
        if(cin.fail() != 0)
           {
               cin.clear();
               cin.ignore(10000,'\n');
           }

        if (y < 1 || y > 3) {
            cout << "Invalid Coordinate!\n";
        } else {
            isInputBad = false;
        }
    }
    return y - 1;
}

string TicTacToeGame::getPlayerName(){
    string player1;
    cout<<"Enter Your Name"<<endl;
    cin>>player1;
    return player1;
}
/**
string TicTacToeGame::getPlayer2(){
    string player2;
    cout<<"Enter name of player 2"<<endl;
    cin>>player2;
    return player2;
}
**/
bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer)
{
    //Return false if Board is already filled up
    if (board[y][x] != ' ') {
        return false;
    }

    board[y][x] = currentPlayer;
    return true;
}

bool TicTacToeGame::checkForVictory(char currentPlayer)
{
    //Check the rows
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true; //We won!
        }
    }

    //Check the columns
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true; //We won!
        }
    }

    //Check top left diagonal
    if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true; //We won!
    }

    //Check top right diagonal
    if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
        return true; //We won!
    }

    return false;
}

void TicTacToeGame::clearBoard()
{
    //Empties the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToeGame::printBoard()
{
    cout << endl;
    cout << " |1 2 3|\n";
    for (int i = 0; i < 3; i++) {
        cout << " -------\n";
        cout << i+1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
    }
    cout << " -------\n";
}
