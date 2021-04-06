// ��Ŀ�� 


#include<iostream>
#include <iomanip>
#include<vector>

using namespace std;

vector<int> wt = {11, 5, 3, 9, 13};
vector<int> val = {15, 9, 8, 63, 4}; 

int N = wt.size();
int W = 25;

vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
//����ֵ������x��ʾȡwt��ǰx���y��ʾȡ����y��[x, y]��ʾ������Ʒ����wt[0:x]����������Ϊyʱ������ֵ�� 

void setdp() {
	for(int i = 1; i<=N; i++) {
		for(int j = 1; j<=W; j++) {
			//�������� 
			if(wt[i-1] > j) {
				dp[i][j] = dp[i-1][j]; 
			} else { //�������ˣ������˴��ǲ��Ŵ� 
				dp[i][j] = dp[i-1][j] > dp[i-1][j-wt[i-1]]+val[i-1] ? dp[i-1][j] : dp[i-1][j-wt[i-1]]+val[i-1];
			}
		}
	}
}

void display() {
	for(int i = 0; i<=N; i++) {
		for(int j = 0; j<=W; j++) {
			cout <<std::right<<setw(2) << dp[i][j] << " ";
		} 
		cout << endl;
	}
} 

int main() {
	setdp();
	display();
	cout << dp[N][W] << endl; 
	return 0;
}
