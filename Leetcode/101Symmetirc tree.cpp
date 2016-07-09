struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//�ݹ飬�ֱ��жϽڵ�ֵ�Ƿ���ȣ��Լ������� �������Ƿ�Գƣ�
/*
�������������������ԳƵ�������
�����ڵ�ֵ��ȣ����߶�Ϊ��
��ڵ�����������ҽڵ���������Գ�
��ڵ�����������ҽڵ���������Գ�
*/
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return isSym(root->left, root->right);
	}
	bool isSym(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr)
			return true;
		if ((!left && right) || (left && !right))
			return false;
		if (left->val == right->val) {
			return isSym(left->left, right->right) && isSym(left->right, right->left);
		}
		else {
			return false;
		}
	}
};
//ѭ������
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
�㷨2���ǵݹ�ⷨ�����������зֱ𱣴��������ڵ���������ڵ㣬ÿ�δ����������зֱ�ȡ��Ԫ�أ�
�������Ԫ�ص�ֵ��ȣ�����������ǵ����ҽڵ�������Ҷ��С�Ҫע��ÿ��ȡ��������Ԫ�أ�
�����Ԫ�ص�����Ҫ���Ҷ���Ԫ�ص��Һ���Ҫͬʱ��Ϊ�ջ���ͬʱΪ�գ����򲻿��ܶԳƣ�
ͬ�������Ԫ�ص��Һ���Ҫ���Ҷ���Ԫ�ص�����Ҳһ����
*/
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (root == NULL)return true;
		queue<TreeNode*> qleft, qright;
		if (root->left)qleft.push(root->left);
		if (root->right)qright.push(root->right);
		while (qleft.empty() == false && qright.empty() == false)
		{
			TreeNode *ql = qleft.front();
			TreeNode *qr = qright.front();
			qleft.pop();  qright.pop();
			if (ql->val == qr->val)
			{
				if (ql->left && qr->right)
				{
					qleft.push(ql->left);
					qright.push(qr->right);
				}
				else if (ql->left || qr->right)
					return false;
				if (qr->left && ql->right)
				{
					qleft.push(qr->left);
					qright.push(ql->right);
				}
				else if (qr->left || ql->right)
					return false;
			}
			else return false;
		}
		if (qleft.empty() && qright.empty())
			return true;
		else return false;
	}
};