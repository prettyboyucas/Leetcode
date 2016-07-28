
class Solution {//修改右指针
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		TreeNode* cur = root;
		TreeNode* pre = nullptr;

		while (cur != nullptr) {



			if (cur->left == nullptr) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {

				pre = cur->left;
				while (pre->right != nullptr && pre->right != cur)
					pre = pre->right;//前驱节点


				if (pre->right == nullptr) {
					pre->right = cur;
					res.push_back(cur->val);//这就是先需了哇？
					cur = cur->left; //继续左走
				}
				else if (pre->right == cur) {//左走完了，恢复原状，右走
					pre->right = nullptr;
					//res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;

	}



};



class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		helper(root, res);
		return res;
	}
	void helper(TreeNode* root, vector<int>& res) {
		if (root == nullptr)
			return;
		res.push_back(root->val);
		helper(root->left, res);
		helper(root->right, res);
	}
};


class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;

		stack<TreeNode*> s;
		while (root || !s.empty) {
			if (root != nullptr) {
				s.push(root);
				res.push_back(root->val);
				root = root->left;
			}
			else {
				root = s.top();
				s.pop();
				root = root->right;
			}
		}


		return res;
	}
};
