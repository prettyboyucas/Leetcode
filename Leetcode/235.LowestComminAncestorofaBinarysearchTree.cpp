class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return root;
		////if (((root->left != nullptr) && root->left->val < root->val) &&
		//	((root->right != nullptr) && root->right->val < root->val))
		if (p->val <root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (p->val > root->val && q->val>root->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};
//ֱ�Ӵ�root��ʼ�жϣ��Ƿ�λ��q,p֮��Ϳ�����