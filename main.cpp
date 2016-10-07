/*Tic Tac Toe*/

#include <iostream>


//Player codes
#define TIE 1
#define XPLAYER 2
#define OPLAYER 3

//Stores info about moves
struct Move {
	int x=0,y=0,player=0;
};

//Functions
int checkWin(char board[][3], Move* m);
int userMove(char board[][3], Move* m);
int printBoard(char board[][3]);
char inputChar(char* prompt, bool isolated);
int clearBoard(char board[][3]);


using namespace std;


//Main
int main() {
	char board[3][3];
	int xwins, owins, ties, moves;
	int win;
	Move m;

	char* prompt = "Play another game?(y/n):";


	//Main loop
	do {
		//Setup
		moves = 0;
		clearBoard(board);
		//Print board and take moves as long as no winner or tie
		while (printBoard(board), !(win=checkWin(board, &m)) && moves < 9) {
			userMove(board, &m);
			moves++;
		}

		//If Tie, set code
		if (!win && moves == 9)
			win = TIE;

		//Display winner
		switch(win) {
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

		//Display scores
		cout << "X wins:" << xwins << "\tO wins:" << owins << '\n';


	} while (inputChar(prompt, true) == 'y'); //Play as long as user wants

	return 0;


}


//Check for wins, return code of winner
//Takes last move so that it only checks possible wins
int checkWin(char board[][3], Move* m) {
	int c, counters[4] = {0};
	
	/*Add to counters of instances of player mark for possible
	winning row and column and both diagonals*/
	for (c=0; c<3; c++) {
		counters[0] += board[m->x][c]==m->player;
		counters[1] += board[c][m->y]==m->player;
		counters[2] += board[c][c]==m->player;
		counters[3] += board[c][2-c]==m->player;
	}
	
	//If any counter reached 3 in a row, return winner
	for (c=0; c<4; c++)
		if (counters[c]==3)
			return m->player;

	//Other wise, no winner
	return NULL;
}


//Take and record user move, writes to move struct
int userMove(char board[][3], Move* m) {
	bool valid = false;
	
	//Switch turn
	if (m->player == XPLAYER) m->player = OPLAYER;
	else m->player = XPLAYER;

	//Continue taking input until valid input given
	while (!valid) {
		m->x = inputChar("Enter move:",false)-97;
		valid = (m->x >= 0) && (m->y < 3);
		if (valid) {
			m->y = inputChar("",true)-49;
			valid = valid && ((m->x >= 0) && (m->y < 3));
		}
		if (valid)
			valid = (board[m->x][m->y]==' ');
	}

	//Record move on board
	board[m->x][m->y] = m->player;

	return 0;
}


//Get a character
char inputChar(char* prompt, bool isolated) {
	char input;

	cout << prompt;	//Prompt user

	//Take input until it conforms to whether it should be alone on line or not
	while (cin >> input, isolated && (cin.peek()!='\n')) {
		cout << "Enter valid input:";
		cin.ignore(1000, '\n');
		cin.clear();
	}

	return input;
}


//Print board
int printBoard(char board[][3]) {
	int x,y;
	char baseboard[4][4] = {' ','a', 'b', 'c'
			,'1','\0','\0','\0'
			,'2','\0','\0','\0'
			,'3','\0','\0','\0'};

	//Print template and board values in approprite places
	for (y=0; y<4; y++) {
		for (x=0; x<4; x++) {
			cout << baseboard[y][x];
			if (x && y) {	//Only print board values it not edges
				if (board[x-1][y-1] == XPLAYER)
					cout << 'x';
				else if (board[x-1][y-1] == OPLAYER)
					cout << 'o';
			}
			cout << '\t';
		}
		cout << '\n';
	}


	return 0;
}


//Clear 2d array to all spaces
int clearBoard(char board[][3]) {
	for (int c = 0; c < 9; c++)
		*(board[0]+c) = ' ';

	return 0;
}
