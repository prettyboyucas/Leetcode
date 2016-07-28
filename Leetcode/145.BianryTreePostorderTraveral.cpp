

class Solution {//修改右指针
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		TreeNode* cur = root;
		TreeNode* pre = nullptr;

		while (cur != nullptr) {



			if (cur->right == nullptr) {
				res.insert(res.begin(), cur->val);
				cur = cur->left;
			}
			else {

				pre = cur->right;
				while (pre->left != nullptr && pre->left != cur)
					pre = pre->left;//前驱节点


				if (pre->left == nullptr) {
					pre->left = cur;
					//res.push_back(cur->val);//这就是先需了哇？
					res.insert(res.begin(), cur->val);
					cur = cur->right; //继续左走
				}
				else if (pre->left == cur) {//左走完了，恢复原状，右走
					pre->left = nullptr;
					//res.push_back(cur->val);
					cur = cur->left;
				}
			}
		}
		return res;

	}
};
















class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> temp;
		while (root || !temp.empty()) {
			while (root) {
				temp.push(root);
				res.insert(res.begin(), root->val);//插在前面 so clever
				root = root->right;
			}
			root = temp.top();
			temp.pop();
			root = root->left;
		}
		return res;
	}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		helper(root, res);

		return res;
	}
	void helper(TreeNode* root, vector<int>& res) {
		if (root == nullptr)
			return;
		helper(root->left, res);
		helper(root->right, res);
		res.push_back(root->val);
	}
};
