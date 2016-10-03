/*Tic Tac Toe*/

#include <iostream>

#define TIE = 1;
#define XPLAYER = 2;
#define OPLAYER = 3;

struct Move;

int checkWin(int** board, Move* m);
Move userMove(int** board);
int printBoard(int** board);
char inputChar(char** prompt, bool isolated);

using namespace std;

int main() {
	char board[3][3];
	int xwins, owins, ties, moves;
	Move m;

	do {
		moves = 0;
		while (printBoard(&b), !checkWin(board, &m) && move < 9) {
			m = userMove(&board);
			moves++;
		}

		switch(checkWin(&board) || moves == 9) {
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


	} while (inputChar("Play another game?(y/n):", true) == 'y');

	return 0;


}


struct Move {
	int x, y, player;
};

int checkWin(int board[][3], Move* m) {
	int c, counters[4];

	for (c=0; c<3; c++) {
		counters[0] += board[m->x][c]==player;
		counters[1] += board[c][m->y]==player;
		counters[2] += board[c][c]==player;
		counters[3] += board[c][2-c]== player;
	}

	for (c=0; c<4; c++)
		if (counters[c]==3)
			return player;

	return NULL;
}

Move userMove(int board[][3]) {
	Move m;
	bool valid = false;
	
	while (!valid) {
		m.x = inputChar("Enter move:",false)-96;
		valid = m.x > 0 && m.x < 4;
		m.y = inputChar("",true)-48;
		valid = valid && m.x > 0 && m.x < 4;
	}

	return m;
}


char inputChar(char* prompt) {
	char input;

	cout << prompt;

	while (cin >> input || (isolated && cin.peek())) {
		cout << "Enter valid input: ";
		cin.ignore(1000);
		cin.clear();
	}

	return char;
}
