//LLD code for Tic-Tac-Toe
#include <bits/stdc++.h>
using namespace std;

class Player{
	public:
		string playerName;
		char playerSymbol;
		
		void setPlayer(string pName, char pSym){
			playerName=pName;
			pSym=pSym;
		}
		string getPlayerName(){
			return playerName;
		}
		char getPlayerSymbol(){
			return playerSymbol;
		}
};

class Board{
	public:
		int boardSize;
		vector<vector<char>> board;
	
		void setBoardSize(int size){
			boardSize=size;
			board = vector<vector<char>>(size,vector<char>(size,'-'));
		}
		
		void printBoard(){
			for(int i=0;i<boardSize;i++){
				for(int j=0;j<boardSize;j++){
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
		}
		
		bool setPosition(int row,int col, char pSym){
			if(row>=0 && col>=0 && row<boardSize && col<boardSize && board[row][col]=='-'){
				board[row][col]=pSym;
				return true;
			}
			return false;
		}
		
		bool checkWinner(char pSym){
			//check all rows
			for(int i=0;i<boardSize;i++){
				int flag=0;
				for(int j=0;j<boardSize;j++){
					if(board[i][j]!=pSym){ flag=1; break;}
				}
				if(!flag) return true;
			}
			//check all cols
			for(int i=0;i<boardSize;i++){
				int flag=0;
				for(int j=0;j<boardSize;j++){
					if(board[j][i]!=pSym){ flag=1; break;}
				}
				if(!flag) return true;
			}
			//check all diagonals
			int flag1=0,flag2=0;
			for(int i=0;i<boardSize;i++){
				if(board[i][i]!=pSym){ flag1=1; }
				if(board[i][2-i]!=pSym){ flag2=1; }
			}
			if(!flag1 || !flag2) return true;
			return false;
		}
};

int main(){
	int n=3;
	string playerName1,playerName2;
	Player play1,play2;
	cout << "Enter player1 name: ";
	cin >> playerName1;
	play1.setPlayer(playerName1,(char)88);
	cout << "Enter player2 name: ";
	cin >> playerName2;
	play2.setPlayer(playerName2,(char)79);
	
	Board board;
	board.setBoardSize(n);
	
	int turn=0,turns=0,flag=0;
	while(turns<9){
		int row,col;
		cout << "Enter position: ";
		cin >> row >> col;
		cout << "row: " << row << " col: " << col << endl;
		
		if(turn==0){ //Player1 turn
			bool result = board.setPosition(row,col,'X');
			if(result==false){
				cout << "Invalid Move! Try again\n";
			}
			else{
				if(board.checkWinner('X')){ cout << play1.getPlayerName() << " win!\n"; flag=1; break; }
				turn=!turn;
				turns++;
			}
		}
		else{ //Player2
			bool result = board.setPosition(row,col,'O');
			if(result==false) cout << "Invalid Move! Try again\n";
			else{
				if(board.checkWinner('O')){ cout << play2.getPlayerName() << " win!\n"; flag=1; break; }
				turn=!turn;
				turns++;
			}
		}
		board.printBoard();
	}
	if(!flag) cout << "Match Draw\n";
	cout << "Match Finished\n";
	return 0;
}
