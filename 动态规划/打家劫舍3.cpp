// 题目：在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
//		这个地区只有一个入口，我们称之为“根 ”。 除了“根 ”之外，每栋房子有且只有一个“父 ”房子与之相连。
//		一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树 ”。 
//		如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//		计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。




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
