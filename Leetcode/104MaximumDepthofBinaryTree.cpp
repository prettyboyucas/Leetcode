/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Subscribe to see which companies asked this question
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) { 
		if (root == nullptr)
			return 0;
		int nLeft = maxDepth(root->left);
		int nRight = maxDepth(root->right);//�ݹ��ҵ����������

		return nLeft > nRight ? nLeft + 1 : nRight + 1;
	}
};