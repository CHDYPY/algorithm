// ��Ŀ�� ����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�
// Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
// ����һ������ÿ�����ݴ�Ž��ķǸ��������飬�����㲻��������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�



#include<iostream>
#include<vector>

using namespace std;

vector<int> dp(100 , 0);
vector<int> nums = {1, 2, 3, 4, 5, 6};

int main() {
	dp[0] = nums[0];
	dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	for(int i = 2; i<nums.size(); i++) {
		dp[i] = dp[i-1] > dp[i-2] + nums[i] ? dp[i-1] : dp[i-2] + nums[i];
	} 
	
	for(int i = 0; i<nums.size(); i++) {
		cout << dp[i] << " ";
	}
	
	return 0;
}
