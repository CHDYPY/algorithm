// ��Ŀ�� ����һ��������������飬�ҵ���������������еĳ��� 

#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;

vector<int> s = {4,10,4,3,8,9};

//dp ����Ƕ���s.size()=n����������Ԫ��С��s[n-1]��������������еĳ��� 
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
