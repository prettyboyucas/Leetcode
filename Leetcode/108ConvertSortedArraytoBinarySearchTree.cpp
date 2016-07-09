struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return nullptr;
		int length = nums.size();

		return BSTCore(nums, 0, length - 1);
	}
	TreeNode* BSTCore(vector<int>& nums, int start, int end) {

		if (start > end)
			return nullptr;
		int middle = (start + end) / 2;
		TreeNode* pRoot = new TreeNode(nums[middle]);
		pRoot->left = BSTCore(nums, start, middle - 1);
		pRoot->right = BSTCore(nums, middle + 1, end);

		return pRoot;
	}
};
