//��Ŀ������ k ��?ֵ��Ӳ�ң�?ֵ�ֱ�Ϊ c1, c2 ... ck ��ÿ��Ӳ�ҵ�����?�ޣ�
//	�ٸ�?����?�� amount ������������Ҫ?öӲ�Ҵճ����?���������ܴճ����㷨���� -1 ��

#include<iostream>
#include<vector>

using namespace std;


int main() {
	int num;
	int a[4] = {1, 2, 5, 10};
	cout<<"Ҫ�����Ǯ����";
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
