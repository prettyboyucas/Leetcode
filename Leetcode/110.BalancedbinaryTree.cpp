struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return balanced(root, depth);
	}

	bool balanced(TreeNode* pRoot, int& depth){
		if (pRoot == nullptr)
		{
			depth = 0;
			return true;
		}
		int left, right;
		if (balanced(pRoot->left, left) && balanced(pRoot->right, right)) {
			int diff = left - right;
			if (abs(diff) <= 1) {
				depth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false
	}
};