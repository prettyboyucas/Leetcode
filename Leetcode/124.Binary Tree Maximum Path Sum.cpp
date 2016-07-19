
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int maxValue = numeric_limits<int>::min();
		maxPath(root, maxValue);
		return maxValue;
	}
	int maxPath(TreeNode* root, int& maxValue) {
		if (root == nullptr)
			return 0;
		int left = max(0, maxPath(root->left, maxValue));//左边最大的数
		int right = max(0, maxPath(root->right, maxValue));//右边最大的数
		maxValue = max(maxValue, left + right + root->val);//加起来就是最长路径。
		return max(left, right) + root->val;//返回左右子树的最大值加上该节点的值
	}
};