//给你一个 N×N 的棋盘，让你放置 N 个皇后，使得它们不能互相攻击。
//PS：皇后可以攻击同一行、同一列、左上左下右上右下四个方向的任意单位。

#include<iostream>
#include<vector> 

using namespace std;

//定义棋盘 
vector< vector<string> > board;

//初始化棋盘
void initBoard(int N) {
	for(int i = 0; i<N; i++) {
		vector<string> row(N, "0");
		board.push_back(row);
	}
	
}

//输出棋盘
void displayBoard() {
	for(int i = 0; i<board.size(); i++) {
		for(int j = 0; j<board.size(); j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool NotEat(int row, int col) {
	//判断列(好好想想为啥此处不判断行） 
	for(int i = 0; i<board.size(); i++) {
		if(board[i][col] == "#") {
			return false;
		}
	}
	
	//判断左上是否有皇后 
	for(int i = row-1, j = col+1; i>=0&&j<board.size(); i--, j++) {
		if(board[i][j] == "#") {
			return false;
		}
	}
	//判断右上是否有皇后 
	for(int i = row-1, j = col-1; i>=0&&j>=0; i--, j--) {
		if(board[i][j] == "#") {
			return false;
		}
	}
	return true;
}

void N_Queen(int n) {
	//判断是否完成条件，完成则输出 
	if(n==board.size()){
		displayBoard();
		cout<<"-----------------------"<<endl;
		return;
	}
	for(int i = 0; i<board.size(); i++) {
		//判断是否满足条件 
		if(NotEat(n, i)) {
			board[n][i] = "#";
			N_Queen(n+1);
			board[n][i] = "0";
		}
	}
}



int main() {
	initBoard(8);
	N_Queen(0);
	
	return 0;
} 
