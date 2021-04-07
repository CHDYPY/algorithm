// 题目： 给定一个无序的整数数组，找到其中最长上升子序列的长度 

#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;

vector<int> s = {4,10,4,3,8,9};

//dp 存的是对于s.size()=n，所有序列元素小于s[n-1]的最大上升子序列的长度 
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
	int res = 0;
	for(int i = 0; i<s.size(); i++) {
		res = dp[i] > res ? dp[i] : res;
	}
	return 0;
}
