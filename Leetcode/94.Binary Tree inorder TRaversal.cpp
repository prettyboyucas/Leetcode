/*
1. 如果当前结点的左孩子为空，则输出当前结点并将其当前节点赋值为右孩子。
2. 如果当前节点的左孩子不为空，则寻找当前节点在中序遍历下的前驱节点（也就是当前结点左子树的最右孩子）。接下来分两种情况：
a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点（做线索使得稍后可以重新返回父结点）。然后将当前节点更新为当前节点的左孩子。
b) 如果前驱节点的右孩子为当前节点，表明左子树已经访问完，可以访问当前节点。将它的右孩子重新设为空（恢复树的结构）。输出当前节点。当前节点更新为当前节点的右孩子。
代码如下：

*/



class Solution {//修改右指针
public:
	vector<int> inorderTraversal(TreeNode* root) {
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
					pre = pre->right;
				if (pre->right == nullptr) {
					pre->right = cur;
					cur = cur->left;
				}
				else if (pre->right == cur) {
					pre->right = nullptr;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;

	}



};










class Solution {//递归方法
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		helper(root, res);
		return res;

	}

	void helper(TreeNode* root, vector<int>& res) {
		if (root == nullptr)
			reutrn;
		helper(root->left, res);
		res.push_back(root->val);
		helper(root->right, res);
	}


};

class Solution {//递归方法
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		stack<TreeNode*> s;
		while (root != nullptr || !s.empty()) {
			if (root != nullptr) {
				s.push(root);
				root = root->left;
			}
			else
			{
				root = s.top();
				s.pop();
				res.push_back(root->val);
				root = root->right;
			}
		}
		return res;

	}



};
