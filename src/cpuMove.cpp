#include "cpuMove.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
cpuMove::cpuMove() {
	// TODO Auto-generated constructor stub
x=y=0;
}

cpuMove::~cpuMove() {
	// TODO Auto-generated destructor stub
}
void cpuMove::setEasy(bool flag){
easy=flag;/**<  */
}
void cpuMove::putRandom(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]==' '){
                x=j;
                y=i;
                break;
            }
        }
    }

}
inline int cpuMove::getRandom(int range){
	srand( (unsigned)time( NULL  ) );
	int randumnum=rand()%range;
	return randumnum+1;
}
void cpuMove::cpuMoveinit(char board[3][3], int turn) {

	if(turn < 4){//code for turn 1 and 3
		if(turn == 0){
			//Occupying center spot to reduce opponent chance of winning
			x=y=1;
		}
		else if(turn == 2){

			//in case user makes an adjacent move


			if(board[0][1] == 'O'){
				y=0;
				//Since we have two choices for x
				switch(getRandom(2)){
				case 1: x=0; break;
				case 2: x=2; break;
				}
			}
			if(board[1][0] == 'O'){
				x=0;
				//Since we have two choices for x
				switch(getRandom(2)){
				case 1: y=0; break;
				case 2: y=2; break;
				}
			}
			if(board[2][1] == 'O'){

				x=2;
				//Since we have two choices for x
				switch(getRandom(2)){
				case 1: y=0; break;
				case 2: y=2; break;
				}
			}
			if(board[1][2] == 'O'){

				x=2;
				//Since we have two choices for x
				switch(getRandom(2)){
				case 1: y=0; break;
				case 2: y=2; break;
				}
			}

			//in case user makes corner moves
			if(board[0][0] == 'O' || board[2][2] == 'O'){
				switch(getRandom(2)){
				case 1: x=0; y=2; break;
				case 2: x=2; y=0; break;
				}
			}
			if(board[0][2] == 'O'|| board[2][0] == 'O'){
				switch(getRandom(2)){
				case 1: x=0; y=0; break;
				case 2: x=2; y=2; break;
				}
			}

		}
	}//end of if

	if(turn >= 4){
		//Since now there are enough marks on board so we have to check winning or loosing move
        if(!(easy && getRandom(10)%2)){
            bool flag1=checkWinningmove(board);
            if(!flag1){

                bool flag2=checkVulnerability(board);
                    if(!flag2){
                        putRandom(board);
                    }
            }
        }
        else{
            putRandom(board);
        }


	}
}


bool cpuMove::checkWinningmove(char board[3][3]){
	//function are in order of probable cases
	//check top right to bottom left diagonal
	if(board[2][0]=='X' && board[1][1]=='X' && board[0][2]==' '){
		x=2; y=0;
		return true;
	}

	if(board[2][0]==' ' && board[1][1]=='X' && board[0][2]=='X'){
		x=0; y=2;
		return true;
	}

	if(board[2][0]=='X' && board[1][1]==' ' && board[0][2]=='X'){
	//this is a useless if
		x=1; y=1;
		return true;
	}

	//check top left to bottom right diagonal
	if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]==' '){
		x=2; y=2;
		return true;
	}

	if(board[0][0]==' ' && board[1][1]=='X' && board[2][2]=='X'){
		x=0; y=0;
		return true;
	}

	if(board[0][0]=='X' && board[1][1]==' ' && board[2][2]=='X'){
	//this is a useless if
		x=1; y=1;
		return true;
	}


	//check rows
	for(int i=0; i<3; i++){
        if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]==' '){
		x=2; y=i;
		return true;
        }

        if(board[i][0]==' ' && board[i][1]=='X' && board[i][2]=='X'){
		x=0; y=i;
		return true;
        }

        if(board[i][0]=='X' && board[i][1]==' ' && board[i][2]=='X'){

		x=1; y=i;
		return true;
        }
	}

	//check columns
	for(int i=0; i<3; i++){

        if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]==' '){
		x=i; y=2;
		return true;
        }

        if(board[0][i]==' ' && board[1][i]=='X' && board[2][i]=='X'){
		x=i; y=0;
		return true;
        }

        if(board[0][i]=='X' && board[1][i]==' ' && board[2][i]=='X'){

		x=i; y=1;
		return true;
        }
	}
	return false;

}

bool cpuMove::checkVulnerability(char board[3][3]){
//function are in order of probable cases

	//check top right to bottom left diagonal
	if(board[2][0]=='O' && board[1][1]=='O' && board[0][2]==' '){
		x=2; y=0;
		return true;
	}

	if(board[2][0]==' ' && board[1][1]=='O' && board[0][2]=='O'){
		x=0; y=2;
		return true;
	}

	if(board[2][0]=='O' && board[1][1]==' ' && board[0][2]=='O'){
	//this is a useless if
		x=1; y=1;
		return true;
	}

	//check top left to bottom right diagonal
	if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]==' '){
		x=2; y=2;
		return true;
	}

	if(board[0][0]==' ' && board[1][1]=='O' && board[2][2]=='O'){
		x=0; y=0;
		return true;
	}

	if(board[0][0]=='O' && board[1][1]==' ' && board[2][2]=='O'){
	//this is a useless if
		x=1; y=1;
		return true;
	}




	//check rows
	for(int i=0; i<3; i++){
        if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]==' '){
		x=2; y=i;
		return true;
        }

        if(board[i][0]==' ' && board[i][1]=='O' && board[i][2]=='O'){
		x=0; y=i;
		return true;
        }

        if(board[i][0]=='O' && board[i][1]==' ' && board[i][2]=='O'){

		x=1; y=i;
		return true;
        }
	}

	//check columns
	for(int i=0; i<3; i++){
        if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]==' '){
		x=i; y=2;
		return true;
        }

        if(board[0][i]==' ' && board[1][i]=='O' && board[2][i]=='O'){
		x=i; y=0;
		return true;
        }

        if(board[0][i]=='O' && board[1][i]==' ' && board[2][i]=='O'){

		x=i; y=1;
		return true;
        }
	}

	return false;
}

int cpuMove::getCPUx(){
	return x;
}

int cpuMove::getCPUy(){
	return y;
}
