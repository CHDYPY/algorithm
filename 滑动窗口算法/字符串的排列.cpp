// 题目： 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
//	换句话说，第一个字符串的排列之一是第二个字符串的子串。


#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std;


bool isPart(string s1, string s2) {
	unordered_map<char, int> need;
	unordered_map<char, int> window;
	//为判断窗口赋值 
	for(char c : s2) {
		need[c]++;
	}
	
	int left = 0;
	int right = 0;
	
	int flag = 0; // 标志符，判断window和need中相等的元素个数 
	
	while(right<s1.size()) {
		if(need.count(s1[right])) {
			window[s1[right]]++;
			if(window[s1[right]] == need[s1[right]]) {
				flag++;
			} 
		}
		right++;
		//window的value可以大于need 
		while(flag == need.size()) {
			if(right-left == s2.size()) {
				return true;
			}
			
			if(need.count(s1[left])) {
				if(window[s1[left]] == need[s1[left]])
					flag--;
				window[s1[left]]--;
			}
			left++;
		}
	}
	return false;
	
	
}



int main() {
	string s1 = "sadfasdfasdfasdfasdfhdfgdfgc";
	string s2 = "fdas";
	
	cout << isPart(s1, s2);
	
	
	return 0;
}
