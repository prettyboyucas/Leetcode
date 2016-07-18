class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return root;
		TreeNode* node = root->right;
		root->right = root->left;
		root->left = node;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

class Solution {//遍历采用的是队列。
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return root;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			TreeNode* temp = node->left;
			node->left = node->right;
			node->right = temp;
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		return root;
	}
};