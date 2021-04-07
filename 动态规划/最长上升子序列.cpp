// 题目： 给定一个无序的整数数组，找到其中最长上升子序列的长度 

#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;

vector<int> s = {10, 9, 2, 5, 3, 7, 101, 18};

vector<int> dp(s.size(), 1);

void setdp() {
	int max;
	for(int i = 0; i<s.size(); i++) {
		max = 1;
		for(int j = 0; j<i; j++) {
			if(s[j] < s[i]) {
				max = dp[j]+1>max ? dp[j]+1 : max;
			}
		}
		dp[i] = max;
	}
}

void display() {
	for(int i = 0; i<s.size(); i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
}


int main() {
	setdp();
	display();
	cout << dp[s.size()-1];
	return 0;
}
