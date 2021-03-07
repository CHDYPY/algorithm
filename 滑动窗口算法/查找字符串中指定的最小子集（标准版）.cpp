// 题目： 给你一个字符串 s 、一个字符串 t 。
//	返回 s 中涵盖 t 所有字符的最小子串。
//	如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//	注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。



#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std;

//解题函数 
string minWindow(string s, string t) {
	unordered_map<char, int> need, window;
	//将t中的字符出现次数赋值到need中 
	for(char c : t) need[c]++;
	
	int left = 0;
	int right = 0;
	int flag = 0;  //这是一个条件符，用来判断是否能够让left进行右移 
	int start = 0; //保存最小区间的起始位置 
	int len = INT_MAX; //保存最小区间的长度 
	while(right < s.length()) {
		//need中是否包含right指针下的字符 
		if(need.count(s[right])) {
			window[s[right]]++;
			if(window[s[right]] == need[s[right]]) {
				flag++;
			}
		}
		
		//判断 need 和 window中的元素个数，个数相等的情况下，只要window的value大于need，就可以收缩 
		while(flag == need.size()) {
			//判断区间是否最小 
			if(right-left+1 < len) {
				start = left;
				len = right - left+1;
			}
			left++;
			if(need.count(s[left-1])) {
				if(window[s[left-1]] == need[s[left-1]]) {
					flag--;
				}
				window[s[left-1]]--;
			}	
		}
		
		right++;
		//不相等时，right++
	}
	if(len == INT_MAX) {
		return "";
	}
	
	return s.substr(start, len);
	 
}






int main() {
	unordered_map<char, int> map;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	
	cout << minWindow(s, t);
	

	return 0;
}
