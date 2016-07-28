/*
1. �����ǰ��������Ϊ�գ��������ǰ��㲢���䵱ǰ�ڵ㸳ֵΪ�Һ��ӡ�
2. �����ǰ�ڵ�����Ӳ�Ϊ�գ���Ѱ�ҵ�ǰ�ڵ�����������µ�ǰ���ڵ㣨Ҳ���ǵ�ǰ��������������Һ��ӣ��������������������
a) ���ǰ���ڵ���Һ���Ϊ�գ��������Һ�������Ϊ��ǰ�ڵ㣨������ʹ���Ժ�������·��ظ���㣩��Ȼ�󽫵�ǰ�ڵ����Ϊ��ǰ�ڵ�����ӡ�
b) ���ǰ���ڵ���Һ���Ϊ��ǰ�ڵ㣬�����������Ѿ������꣬���Է��ʵ�ǰ�ڵ㡣�������Һ���������Ϊ�գ��ָ����Ľṹ���������ǰ�ڵ㡣��ǰ�ڵ����Ϊ��ǰ�ڵ���Һ��ӡ�
�������£�

*/



class Solution {//�޸���ָ��
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










class Solution {//�ݹ鷽��
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

class Solution {//�ݹ鷽��
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
