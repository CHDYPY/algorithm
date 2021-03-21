//��Ŀ������һ�������ĸ�Բ�β��ֵ�ת������ÿ�����ֶ���10�����֣� '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ��
//	ÿ�����ֿ���������ת������� '9' ��Ϊ '0'��'0' ��Ϊ '9' ��ÿ����ת��ֻ����תһ�����ֵ�һλ���֡�
//	���ĳ�ʼ����Ϊ '0000' ��һ�������ĸ����ֵ����ֵ��ַ�����
//	�б� deadends ������һ���������֣�һ�����ֵ����ֺ��б�����κ�һ��Ԫ����ͬ����������ᱻ�����������޷��ٱ���ת��
//	�ַ��� target ������Խ��������֣�����Ҫ������С����ת���������������β��ܽ��������� -1��


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
