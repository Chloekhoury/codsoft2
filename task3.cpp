#include<iostream>
using namespace std;
void main() {
	void display(char[][3]);
	bool check(char[][3]);
	char a; int y;
	do {
		char board[3][3] = { {'1','1','1'}, {'1','1','1'} ,{'1','1','1'} };
		cout << "\nPlayer 1 will use the X and Player 2 will use the O\n Please choose where you want to put your symbol in the grid at your turn (the row then the column)\n";
		int u = 1; int h; int p = 0;int r=0; char o;
		for ( y = 1; y <= 9; y++) {
			if (u % 2 == 0) {
				h = 2; o = 'O';
			}
			else {
				h = 1; o = 'X';
			}
			cout << endl << endl;
			display(board);
			cout << endl<<endl<<"Player " << h << ":";
			int q = 0;
			do
			{
				
				if (q != 0) {
					if ((board[p][r] == 'X') || (board[p][r] == 'O'))cout << "It's already taken, retry please: ";
					else cout << "invalid case";
				}
				cin >> p >> r;
				p--; r--;
				q++;
			} while (board[p][r] == 'X' || board[p][r] == 'O'||p>2 || p <0  || r > 2 || r<0);

			board[p][r] = o;
			if (check(board)) {
				cout << endl<< "Player " << h << "won, Congrats!"; break;
			}
				u++;
		}
		if (y == 10) {
			display(board); cout << endl<<"Draw\n";
		}
		cout<<"Do you wanna replay ? press y if yes and n if no : ";
		cin >> a;
	} while (a == 'y');
	cout << "Thanks for playing :)";
}

void display( char board[3][3]) {
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2; j++) {
			cout << " ";
			if (board[i][j] == 'X' || board[i][j] == 'O')cout << board[i][j];
			else cout << " ";
			if(j!=2)cout << " | ";
		}
		if(i!=2)cout << endl << "------------\n";
}
}

bool check(char board[3][3]) {
	for (int i = 0; i < 3; i++){
		int t = 0; int w = 0;
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X')t++;
			if (board[j][i] == 'O')w++;
		}
		if (t == 3 || w == 3)return true;
		
}
	if (board[0][0] == board[1][1] == board[2][2])return true;
	if (board[0][2] == board[1][1] == board[2][0])return true;
	return false;
}