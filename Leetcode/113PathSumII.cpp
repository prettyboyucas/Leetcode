

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		vector<int> pathstack;
		int accu = 0;
		bool flag = false;

		pathSum(root, sum, res, pathstack, accu);
		return res;
	}
	void pathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& pathstack, int accu) {
		pathstack.push_back(root->val);
		accu += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (sum == accu) {
				res.push_back(pathstack);
			}


		}

		if (root->left != nullptr)
			pathSum(root->left, sum, res, pathstack, accu);
		if (root->right != nullptr)
			pathSum(root->right, sum, res, pathstack, accu);

		pathstack.pop_back();
		//accu -= root->val;
		//return false;
	}
};