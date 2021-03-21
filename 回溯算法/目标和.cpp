// 题目： 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
//现在你有两个符号?+?和?-。
//对于数组中的任意一个整数，你都可以从?+?或?-中选择一个符号添加在前面。
//返回可以使最终数组和为目标数 S 的所有添加符号的方法数。



#include<iostream>
#include<vector>

using namespace std;

vector<int> nums = {5,40,23,47,43,19,36,10,28,46,14,11,5,0,5,22,39,30,50,41};
vector<int> symbol = {1, -1};
int S = 48;
int ways = 0;

void dsp(int index, int sum) {
	if(index == nums.size()) {
		if(sum == S) {
			ways++;
		}
		return;
	}
	for(int i = 0; i<2; i++) {
		sum += symbol[i]*nums[index];
		dsp(index+1, sum);
		sum -= symbol[i]*nums[index];
	}
	
}


int main() {
	dsp(0, 0);
	cout << ways << endl;
	
	return 0;
}
