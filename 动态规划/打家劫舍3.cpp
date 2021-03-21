// ��Ŀ�����ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ�����
//		�������ֻ��һ����ڣ����ǳ�֮Ϊ���� ���� ���ˡ��� ��֮�⣬ÿ����������ֻ��һ������ ��������֮������
//		һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö����� ���� 
//		�������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������
//		�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�




#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<TreeNode*, int> check, notCheck;

void dfs(TreeNode *treeNode) {
	if(treeNode == nullptr) {
		return;
	}
	
	dfs(treeNode->left);
	dfs(treeNode->right);
	check[treeNode] = treeNode->val + notCheck[treeNode->left] + notCheck[treeNode->right];
	
	int m1 = check[treeNode->left] < notCheck[treeNode->left] ? notCheck[treeNode->left] : check[treeNode->left];
	int m2 = check[treeNode->right] < notCheck[treeNode->right] ? notCheck[treeNode->right] : check[treeNode->right];
	noCheck[treeNode] = m1 + m2;
}




int notCheck(TreeNode *treeNode);

int check(TreeNode *treeNode) {
	
	if(treeNode == nullptr) {
		return 0;
	}
	
	int m = notCheck(treeNode->left) > notCheck(treeNode->right) ?  notCheck(treeNode->left) : notCheck(treeNode->right);
	return m + treeNode->val;
} 

int notCheck(TreeNode *treeNode) {
	
	if(treeNode == nullptr) {
		return 0;
	}
	
	int m1 = check(treeNode->left) < notCheck(treeNode->left) ? notCheck(treeNode->left) : check(treeNode->left);
	int m2 = check(treeNode->right) < notCheck(treeNode->right) ? notCheck(treeNode->right) : check(treeNode->right);
	
	return m1 + m2;
}

int main() {
	
	
	
	return 0;
}
