/*Tic Tac Toe*/

#include <iostream>

#define TIE = 1;
#define XPLAYER = 2;
#define OPLAYER = 3;


int checkWin(int** board);
int userMove(int** board);
int printBoard(int** board);
char inputChar(char** prompt);

using namespace std;

int main() {
	char board[3][3];
	int xwins, owins, ties;

	do {
		while (printBoard(&b), !checkWin(&board)) {
			userMove(&board);
		}

		switch(checkWin(&board)) {
		case TIE: cout << "Tie!";
			 ties++;
			 break;
		case XPLAYER: cout << "X wins!";
			 xwins++;
			 break;
		case OPLAYER: cout << "O wins!";
			 owins++;
			 break;
		}




	} while (inputChar("Play another game?(y/n):") == 'y');

	return 0;


}


int checkWin(int board[][3]) {
	
}


char inputChar(char* prompt) {
	char input;

	cout << prompt;

	while (cin >> input || cin.peek()) {
		cout << "Enter valid input: ";
		cin.ignore(1000);
		cin.clear();
	}

	return char;
}
