/*Tic Tac Toe*/

#include <iostream>

#define TIE = 1;
#define XPLAYER = 2;
#define OPLAYER = 3;

struct Move;

int checkWin(int** board, Move* m);
int userMove(int** board, Move* m);
int printBoard(int** board);
char inputChar(char** prompt, bool isolated);

using namespace std;

int main() {
	char board[3][3];
	int xwins, owins, ties, moves;
	Move m;

	m.player = 0;

	do {
		moves = 0;
		while (printBoard(&board), !checkWin(board, &m) && move < 9) {
			userMove(&board, &m);
			moves++;
		}

		switch(checkWin(&board, &m) || moves == 9) {
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

int userMove(int board[][3], Move* m) {
	bool valid = false;
	
	if (m->player == XPLAYER) m->player = OPLAYER;
	else m->player = XPLAYER;


	while (!valid) {
		m->x = inputChar("Enter move:",false)-96;
		valid = m->(x > 0) && m->(x < 4);
		m->y = inputChar("",true)-48;
		valid = valid && m->(x > 0) && m->(x < 4);
	}

	board[m->x][m->y] = player;

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

int printboard(char board[][3]) {
	int x,y;
	char template = {' ','a', 'b', 'c'
			,'1','\0','\0','\0'
			,'2','\0','\0','\0'
			,'3','\0','\0','\0'}

	for (x=0; x<3; x++) {
		for (y=0; y<3; y++) {
			cout << 
		}
	}

}
