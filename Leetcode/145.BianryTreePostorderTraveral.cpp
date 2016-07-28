

class Solution {//�޸���ָ��
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
					pre = pre->left;//ǰ���ڵ�


				if (pre->left == nullptr) {
					pre->left = cur;
					//res.push_back(cur->val);//������������ۣ�
					res.insert(res.begin(), cur->val);
					cur = cur->right; //��������
				}
				else if (pre->left == cur) {//�������ˣ��ָ�ԭ״������
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
				res.insert(res.begin(), root->val);//����ǰ�� so clever
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
