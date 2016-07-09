struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归，分别判断节点值是否相等，以及左子树 右子树是否对称，
/*
其中左子树和右子树对称的条件：
两个节点值相等，或者都为空
左节点的左子树和右节点的右子树对称
左节点的右子树和右节点的左子树对称
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
//循环方法
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
算法2：非递归解法，用两个队列分别保存左子树节点和右子树节点，每次从两个队列中分别取出元素，
如果两个元素的值相等，则继续把他们的左右节点加入左右队列。要注意每次取出的两个元素，
左队列元素的左孩子要和右队列元素的右孩子要同时不为空或者同时为空，否则不可能对称，
同理左队列元素的右孩子要和右队列元素的左孩子也一样。
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