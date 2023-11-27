
#include <iostream>
using namespace std;
void TakeInput(char[3][3]);
void Display(char[3][3]);
int ValidEntry(char[3][3], int, int);
int CheckWinner(char[3][3]);
int main()
{
	char Grid[3][3] = {
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '},
	};

	cout << "     WELCOME TO TIC TAC TOE GAME " << endl;
	Display(Grid);
	TakeInput(Grid);
}
void  Display(char Grid[3][3]) {
	cout << "            " << Grid[0][0] << " | " << Grid[0][1] << " | " << Grid[0][2] << endl;
	cout << "            " << Grid[1][0] << " | " << Grid[1][1] << " | " << Grid[1][2] << endl;
	cout << "            " << Grid[2][0] << " | " << Grid[2][1] << " | " << Grid[2][2] << endl;
}
void TakeInput(char Grid[3][3]) {
	int R;
	int C;
	int Position;
	int Result;
	int Player1Turn = 1;
	int Player2Turn = 0;
	do {
		if (Player1Turn == 1) {
			cout << " Player 1 Turn: " ;
			cin >> Position;
			R = (Position - 1) / 3;
			C = (Position - 1) - (R * 3);


			if (ValidEntry(Grid, R, C) == 1) {
				Grid[R][C] = 'X';
				Display(Grid);
				Player2Turn = 1;
				Player1Turn = 0;
			}
			else {
				cout << "You cannot mark here" << endl;
			}
			Result = CheckWinner(Grid);
		}

		if (Result != 1) {
			if (Player2Turn == 1) {
				cout << " Player 2 Turn: ";
				cin >> Position;
				R = (Position - 1) / 3;
				C = (Position - 1) - (R * 3);

				if (ValidEntry(Grid, R, C) == 1) {
					Grid[R][C] = 'O';
					Display(Grid);
					Player1Turn = 1;
					Player2Turn = 0;
				}
				else {
					cout << "You cannot mark here" << endl;
				}

			}
		}
		Result = CheckWinner(Grid);
	} while (Result == 0);

	if (Result == 1) {
		cout << "GAME OVER!!!" << endl;
		cout << "Winner Player 1 " << endl;
	}
	else if (Result == 2) {
		cout << "GAME OVER!!!" << endl;
		cout << "Winner Player 2 " << endl;
	}
	else if (Result == 3) {
		cout << "Game Draw" << endl;
	}

}

int ValidEntry(char Grid[3][3], int R, int C) {
	if (Grid[R][C] == ' ') {
		return 1;
	}
	else {
		return 0;
	}
}
int CheckWinner(char Grid[3][3]) {
	if (Grid[0][0] == 'X' && Grid[0][1] == 'X' && Grid[0][2] == 'X') {
		return 1;
	}
	else if (Grid[1][0] == 'X' && Grid[1][1] == 'X' && Grid[1][2] == 'X') {
		return 1;
	}
	else if (Grid[2][0] == 'X' && Grid[2][1] == 'X' && Grid[2][2] == 'X') {
		return 1;
	}
	else if (Grid[0][0] == 'X' && Grid[1][0] == 'X' && Grid[2][0] == 'X') {
		return 1;
	}
	else if (Grid[0][1] == 'X' && Grid[1][1] == 'X' && Grid[2][1] == 'X') {
		return 1;
	}
	else if (Grid[0][2] == 'X' && Grid[1][2] == 'X' && Grid[2][2] == 'X') {
		return 1;
	}
	else if (Grid[0][0] == 'X' && Grid[1][1] == 'X' && Grid[2][2] == 'X') {
		return 1;
	}
	else if (Grid[0][2] == 'X' && Grid[1][1] == 'X' && Grid[2][0] == 'X') {
		return 1;
	}
	else if (Grid[0][0] == 'O' && Grid[0][1] == 'O' && Grid[0][2] == 'O') {
		return 2;
	}
	else if (Grid[1][0] == 'O' && Grid[1][1] == 'O' && Grid[1][2] == 'O') {
		return 2;
	}
	else if (Grid[2][0] == 'O' && Grid[2][1] == 'O' && Grid[2][2] == 'O') {
		return 2;
	}
	else if (Grid[0][0] == 'O' && Grid[1][0] == 'O' && Grid[2][0] == 'O') {
		return 2;
	}
	else if (Grid[0][1] == 'O' && Grid[1][1] == 'O' && Grid[2][1] == 'O') {
		return 2;
	}
	else if (Grid[0][2] == 'O' && Grid[1][2] == 'O' && Grid[2][2] == 'O') {
		return 2;
	}
	else if (Grid[0][0] == 'O' && Grid[1][1] == 'O' && Grid[2][2] == 'O') {
		return 2;
	}
	else if (Grid[0][2] == 'O' && Grid[1][1] == 'O' && Grid[2][0] == 'O') {
		return 2;
	}
	else if (Grid[0][0] != ' ' && Grid[0][1] != ' ' && Grid[0][2] != ' '
		&& Grid[1][0] != ' ' && Grid[1][1] != ' ' && Grid[1][2] != ' '
		&& Grid[2][0] != ' ' && Grid[2][1] != ' ' && Grid[2][2] != ' ') {
		return 3;
	}
	else {
		return 0;
	}

}
