// ��Ŀ�� ����һ���ַ��� s ��һ���ַ��� t ��
//	���� s �к��� t �����ַ�����С�Ӵ���
//	��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
//	ע�⣺��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�



#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std;

void display(unordered_map<char, int> need) {
	for(unordered_map<char, int>::iterator it = need.begin(); it != need.end(); it++) { 
		cout << (*it).first << ":" << (*it).second << endl;
	}
	cout << "-------------------------" << endl; 
}

bool isNeqW(unordered_map<char, int> need, unordered_map<char, int> window) {
	
	if(need.size() != window.size()) {
		return false;
	} else {
		for(unordered_map<char, int>::iterator it = need.begin(); it != need.end(); it++) {
			if((*it).second > window[(*it).first]) {
				return false;
			}
		}
	}
	
	return true;
}
//���⺯�� 
string minWindow(string s, string t) {
	unordered_map<char, int> need, window;
	//��t�е��ַ����ִ�����ֵ��need�� 
	for(char c : t) need[c]++;
	
	int left = 0;
	int right = 0;
	int start = 0; //������С�������ʼλ�� 
	int len = INT_MAX; //������С����ĳ��� 
	while(right < s.length()) {
		//need���Ƿ����rightָ���µ��ַ� 
		if(need.count(s[right])) {
			window[s[right]]++;
		}
		
		//�ж� need �� window�е�Ԫ�ظ�����������ȵ�����£�ֻҪwindow��value����need���Ϳ������� 
		while(isNeqW(need, window)) {
			//�ж������Ƿ���С 
			if(right-left+1 < len) {
				start = left;
				len = right - left+1;
			}
			left++;
			if(need.count(s[left-1])) {
				window[s[left-1]]--;
			}	
		}
		
		right++;
		//�����ʱ��right++
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
