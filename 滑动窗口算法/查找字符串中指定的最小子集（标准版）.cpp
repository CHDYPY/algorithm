// ��Ŀ�� ����һ���ַ��� s ��һ���ַ��� t ��
//	���� s �к��� t �����ַ�����С�Ӵ���
//	��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
//	ע�⣺��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�



#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std;

//���⺯�� 
string minWindow(string s, string t) {
	unordered_map<char, int> need, window;
	//��t�е��ַ����ִ�����ֵ��need�� 
	for(char c : t) need[c]++;
	
	int left = 0;
	int right = 0;
	int flag = 0;  //����һ���������������ж��Ƿ��ܹ���left�������� 
	int start = 0; //������С�������ʼλ�� 
	int len = INT_MAX; //������С����ĳ��� 
	while(right < s.length()) {
		//need���Ƿ����rightָ���µ��ַ� 
		if(need.count(s[right])) {
			window[s[right]]++;
			if(window[s[right]] == need[s[right]]) {
				flag++;
			}
		}
		
		//�ж� need �� window�е�Ԫ�ظ�����������ȵ�����£�ֻҪwindow��value����need���Ϳ������� 
		while(flag == need.size()) {
			//�ж������Ƿ���С 
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
