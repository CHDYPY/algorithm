//����һ�� N��N �����̣�������� N ���ʺ�ʹ�����ǲ��ܻ��๥����
//PS���ʺ���Թ���ͬһ�С�ͬһ�С������������������ĸ���������ⵥλ��

#include<iostream>
#include<vector> 

using namespace std;

//�������� 
vector< vector<string> > board;

//��ʼ������
void initBoard(int N) {
	for(int i = 0; i<N; i++) {
		vector<string> row(N, "0");
		board.push_back(row);
	}
	
}

//�������
void displayBoard() {
	for(int i = 0; i<board.size(); i++) {
		for(int j = 0; j<board.size(); j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool NotEat(int row, int col) {
	//�ж���(�ú�����Ϊɶ�˴����ж��У� 
	for(int i = 0; i<board.size(); i++) {
		if(board[i][col] == "#") {
			return false;
		}
	}
	
	//�ж������Ƿ��лʺ� 
	for(int i = row-1, j = col+1; i>=0&&j<board.size(); i--, j++) {
		if(board[i][j] == "#") {
			return false;
		}
	}
	//�ж������Ƿ��лʺ� 
	for(int i = row-1, j = col-1; i>=0&&j>=0; i--, j--) {
		if(board[i][j] == "#") {
			return false;
		}
	}
	return true;
}

void N_Queen(int n) {
	//�ж��Ƿ������������������ 
	if(n==board.size()){
		displayBoard();
		cout<<"-----------------------"<<endl;
		return;
	}
	for(int i = 0; i<board.size(); i++) {
		//�ж��Ƿ��������� 
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
