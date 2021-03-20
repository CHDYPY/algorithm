// ��Ŀ�� ����һ���Ǹ��������飬a1, a2, ..., an, ��һ��Ŀ������S��
//����������������?+?��?-��
//���������е�����һ���������㶼���Դ�?+?��?-��ѡ��һ�����������ǰ�档
//���ؿ���ʹ���������ΪĿ���� S ��������ӷ��ŵķ�������



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
