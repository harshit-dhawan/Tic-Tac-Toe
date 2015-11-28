#include<string>
#ifndef TICTACTOEGAME_H_
#define TICTACTOEGAME_H_
using namespace std;
class TicTacToeGame {
public:
	TicTacToeGame();
	virtual ~TicTacToeGame();
    //This plays the game
    void playGame(int);

private:

    //Gets input from the user
    int getXCoord();
    int getYCoord();
    //Gets Player Names;
    string getPlayerName();
   // string getPlayer2();
    //Places a marker. If it returns false, it couldnt place!
    bool placeMarker(int x, int y, char currentPlayer);

    //Returns true if the current player won!
    bool checkForVictory(char currentPlayer);

    //Empties the board
    void clearBoard();
    // Prints the board
    void printBoard();

    //This stores the board state
    char board[3][3];
};

#endif /* TICTACTOEGAME_H_ */
