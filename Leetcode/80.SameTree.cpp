
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//if (p == nullptr || q == nullptr)
		//	return false;

		return RecursiveTree(p, q);

	}
	bool RecursiveTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p != nullptr && q == nullptr)
			return false;
		if (q != nullptr && p == nullptr)
			return false;


		if (p->val == q->val) {
			return RecursiveTree(p->right, q->right) && RecursiveTree(p->left, q->left);
		}
		else {
			return false;
		}


	}
};

//¾«Á¶Ò»µã
class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (!p && !q) return true;
		if ((!p && q) || (p && !q)) return false;
		if (p->val != q->val) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};