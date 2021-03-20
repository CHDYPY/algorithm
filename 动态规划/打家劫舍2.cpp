// ��Ŀ�� ����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�
//����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
//ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ ���ܹ�͵�Ե�����߽�




#include<iostream>
#include<vector>

using namespace std;

vector<int> nums = {1,2,1,1};
vector<int> dp(nums.size(), 0);


int rob() {
	if(nums.size() == 0) {
		return 0;
	} else if(nums.size() == 1){
		return nums[0];
	} else if(nums.size() == 2) {
		return nums[0] > nums[1] ? nums[0] : nums[1];
	}
	
	dp[0] = nums[0];
	dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	
	for(int i = 2; i<dp.size(); i++) {
		dp[i] = dp[i-1] > dp[i-2]+nums[i] ? dp[i-1] : dp[i-2]+nums[i];
	}
	
	int m = dp[nums.size()-3] > dp[nums.size()-2] ? dp[nums.size()-3] : dp[nums.size()-2];
	
	dp[0] = nums[1];
	dp[1] = nums[1] > nums[2] ? nums[1] : nums[2];
	
	for(int i = 2; i<dp.size()-1; i++) {
		dp[i] = dp[i-1] > dp[i-2]+nums[i+1] ? dp[i-1] : dp[i-2]+nums[i+1];
	}
	
	m = dp[dp.size()-2] > m ? dp[dp.size()-2] : m;
	
	
	return m;
}


int main() {
	cout << rob() << endl;
	
	return 0;
}
