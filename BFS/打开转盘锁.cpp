//题目：你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
//	每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
//	锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
//	列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
//	字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。


#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;


vector<string> deadends  = {"0201","0101","0102","1212","2002"};
string target = "0202";


string leftNode(string nums, int i) {

	if(nums[i] == '0') {
		nums[i] = '9';
	} else {
		nums[i]--;
	}

	return nums;
}

string rightNode(string nums, int i) {
	
	if(nums[i] == '9') {
		nums[i] = '0';
	} else {
		nums[i]++;
	}
	
	return nums;
}

int getDistance(vector<string> nums, string root) {
	set<string> visited;
	queue<string> q;
	int distance = 0;
	if(root == target) {
		return 0;
	}
	q.push(root);
	visited.insert(root);
	
	while(!q.empty()) {
		int size = q.size();
		for(int i =0; i<size; i++) {
			string ss = q.front();
			q.pop();
			if(ss == target) {
				return distance;
			}
			for(string a : deadends) {
				if(a == ss) {
					continue;
				}
			}
			for(int j = 0; j<target.length(); j++) {
				string left = leftNode(ss, j);
				string right = rightNode(ss, j);
				if(visited.count(left) == 0) {
					q.push(left);
					visited.insert(left);
				}
				if(visited.count(right) == 0) {
					q.push(right);
					visited.insert(right);
				}
			}
			
			
		}
		distance++;
	}
	
}




int main() {
	string nums = "0000";
	
	cout<< getDistance(deadends, nums);
	return 0;
} 
