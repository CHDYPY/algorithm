// 题目： 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
//这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。




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
