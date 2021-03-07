// ��Ŀ�� ���������ַ��� s1 �� s2��дһ���������ж� s2 �Ƿ���� s1 �����С�
//	���仰˵����һ���ַ���������֮һ�ǵڶ����ַ������Ӵ���


#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std;


bool isPart(string s1, string s2) {
	unordered_map<char, int> need;
	unordered_map<char, int> window;
	//Ϊ�жϴ��ڸ�ֵ 
	for(char c : s2) {
		need[c]++;
	}
	
	int left = 0;
	int right = 0;
	
	int flag = 0; // ��־�����ж�window��need����ȵ�Ԫ�ظ��� 
	
	while(right<s1.size()) {
		if(need.count(s1[right])) {
			window[s1[right]]++;
			if(window[s1[right]] == need[s1[right]]) {
				flag++;
			} 
		}
		right++;
		//window��value���Դ���need 
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
