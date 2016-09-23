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
	int board[3][3];

	do {
		while (printBoard(b), !checkWin(&board)) {
			userMove(&board);
		}

		switch(checkWin(&board)) {
		case TIE: cout << "Tie!";
			 break;
		case XPLAYER: cout << "X wins!";
			 break;
		case OPLAYER: cout << "O wins!";
			 break;
		}


	} while (inputChar("Play another game?(y/n):") == 'y');

	return 0;


}


char inputChar(char* prompt) {
	char input;

	cout << prompt;

	while (cin >> input || cin.peek()) {
		cout << "Enter valid input type: ";
		cin.ignore(1000);
		cin.clear();
	}

	return char;
}
