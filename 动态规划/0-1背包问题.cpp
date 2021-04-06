// 题目： 


#include<iostream>
#include <iomanip>
#include<vector>

using namespace std;

vector<int> wt = {11, 5, 3, 9, 13};
vector<int> val = {15, 9, 8, 63, 4}; 

int N = wt.size();
int W = 25;

vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
//最大价值矩阵，行x表示取wt的前x项，列y表示取容量y，[x, y]表示对于物品集合wt[0:x]，背包容量为y时的最大价值。 

void setdp() {
	for(int i = 1; i<=N; i++) {
		for(int j = 1; j<=W; j++) {
			//容量不够 
			if(wt[i-1] > j) {
				dp[i][j] = dp[i-1][j]; 
			} else { //容量够了，看放了大还是不放大 
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
