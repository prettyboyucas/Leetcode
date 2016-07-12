class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		stack<int> pathstack;
		int accu = 0;
		bool flag = false;

		pathSum(root, sum, pathstack, accu, flag);//不能返回bool，需要用参数引用，如果用bool的话参数返回找不到就麻烦了。
		return flag;
	}
	void pathSum(TreeNode* root, int sum, stack<int>& pathstack, int accu, bool& flag) {
		pathstack.push(root->val);
		accu += root->val;
		if (root->left == nullptr && root->right == nullptr) {
			if (sum == accu)
				flag = true;

		}

		if (root->left != nullptr)
			pathSum(root->left, sum, pathstack, accu, flag);
		if (root->right != nullptr)
			pathSum(root->right, sum, pathstack, flag);

		pathstack.pop();
		//accu -= root->val;
		//return false;
	}
};

//为啥这么简单就行了啊
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		if (root->right == nullptr && root->left == nullptr) {
			return sum == root->val;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};