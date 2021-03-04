//解数独

#include<iostream>
#include<vector>

using namespace std;

vector< vector<int> > board;
vector< vector<int> > flag(9, vector<int> (9, 0));

bool notRepeat(int row, int col, int num);


void init() {
	vector<int> v1 = {5, 3, 0, 0, 7, 0, 0, 0, 0};
	vector<int> v2 = {6, 0, 0, 1, 9, 5, 0, 0, 0};
	vector<int> v3 = {0, 9, 8, 0, 0, 0, 0, 6, 0};
	vector<int> v4 = {8, 0, 0, 0, 6, 0, 0, 0, 3};
	vector<int> v5 = {4, 0, 0, 8, 0, 3, 0, 0, 1};
	vector<int> v6 = {7, 0, 0, 0, 2, 0, 0, 0, 6};
	vector<int> v7 = {0, 6, 0, 0, 0, 0, 2, 8, 0};
	vector<int> v8 = {0, 0, 0, 4, 1, 9, 0, 0, 5};
	vector<int> v9 = {0, 0, 0, 0, 8, 0, 0, 7, 9};
	

	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	board.push_back(v5);
	board.push_back(v6);
	board.push_back(v7);
	board.push_back(v8);
	board.push_back(v9);

	
	
} 

void display() {
	for(int i = 0; i<9; i++) {
		for( int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void shudu(int row, int col) {
	if(row == 9) {
		display();
		cout << "--------------------------"<< endl;
		exit(0);
		return;
	} else if(col == 9){
		shudu(row+1, 0);
	}

	//为第row行第col列从1-9分别对该列赋值 
	if(board[row][col] == 0) {
		for(int i =1; i<10; i++) {
			if(notRepeat(row, col, i)) {
				board[row][col] = i;
				shudu(row, col+1);
				board[row][col] = 0;
			} else {
				continue;
			}
		}	
	} else {
		shudu(row, col+1);
	}
}

bool notRepeat(int row, int col, int num) {
	//判断左边
	for(int i = col-1; i>=0; i--) {
		if(board[row][i] == num) {
			return false;
		}	
	}
	
	//判断右边
	for(int i = col+1; i<9; i++) {
		if(board[row][i] == num) {
			return false;
		}	
	}
	
	//判断上边
	for(int i = row-1; i>=0; i--) {
		if(board[i][col] == num) {
			return false;
		}	
	}
	
	//判断下边
	for(int i = row+1; i<9; i++) {
		if(board[i][col] == num) {
			return false;
		}	
	}
	
	//判断九宫格
	for(int i = row/3*3; i<row/3*3+3; i++) {
		for( int j = col/3*3; j<col/3*3+3; j++) {
			if(board[i][j] == num) {
				return false;
			}
		}
	}
	
	return true; 
}





int main() {
	init();
	shudu(0,0);
//	display();	
	
	
	return 0;
} 



