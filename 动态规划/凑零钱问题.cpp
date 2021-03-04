//题目：给你 k 种?值的硬币，?值分别为 c1, c2 ... ck ，每种硬币的数量?限，
//	再给?个总?额 amount ，问你最少需要?枚硬币凑出这个?额，如果不可能凑出，算法返回 -1 。

#include<iostream>
#include<vector>

using namespace std;


int main() {
	int num;
	int a[4] = {1, 2, 5, 10};
	cout<<"要分配的钱数：";
	cin>>num; 
	vector<int> dp(num+1, num+1);
	
	dp[0] = 0;
	
	for(int i = 0; i<num+1; i++) {
		for(int j = 0; j<4; j++) {
			if(i-a[j] < 0) continue;
			dp[i] = dp[i] > dp[i-a[j]] ? dp[i-a[j]]+1 : dp[i];
		}
	}
	
//	for(int i = 0; i<num+1; i++) {
//		cout << dp[i] <<endl;
//	}
	cout << dp[num] <<endl;
	return 0;
	
}
