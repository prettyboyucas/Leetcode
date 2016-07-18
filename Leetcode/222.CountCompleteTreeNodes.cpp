class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr)
			return 0;
		TreeNode* pleft = root;
		TreeNode* pright = root;
		int hleft = 1;
		int hright = 1;
		while (pleft->left) {
			hleft++;
			pleft = pleft->left;
		}
		while (pright->right) {
			hright++;
			pright = pright->right;
		}
		if (hleft == hright)
			return pow(2, hleft) - 1;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};