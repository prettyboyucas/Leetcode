struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	using Iter = vector<int>::iterator;

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;
		int length = preorder.size();
		if (length != inorder.size())
			return nullptr;
		return buildCore(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());//注意是尾后迭代器。需要+1
	}

	//Treenodecor
	TreeNode* buildCore(Iter prestart, Iter preend, Iter instart, Iter inend) {//注意是尾后迭代器。需要+1

		TreeNode* root = new TreeNode(*prestart);
		root->val = *prestart;
		if (prestart == preend - 1)
			return root;
		root->left = root->right = nullptr;
		Iter rootinorder = instart;
		while (rootinorder != inend && *rootinorder != *prestart) {
			rootinorder++;
		}

		auto leftLength = rootinorder - instart;
		Iter leftPreorderEnd = prestart + leftLength;
		if (leftLength > 0)//构造左子树
		{
			root->left = buildCore(prestart + 1, leftPreorderEnd + 1, instart, rootinorder);//注意是尾后迭代器。需要+1
		}
		if (leftLength + 1 < preend - prestart) {
			root->right = buildCore(leftPreorderEnd + 1, preend, rootinorder + 1, inend);//注意是尾后迭代器。需要+1
		}
		return root;
	}
};

//借鉴别人的东东
class Solution {
	/**
	*@param preorder : A list of integers that preorder traversal of a tree
	*@param inorder : A list of integers that inorder traversal of a tree
	*@return : Root of a tree
	*/
public:
	typedef vector<int>::iterator Iter;
	TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
	{
		if (istart == iend)return NULL;
		int rootval = *pstart;
		Iter iterroot = find(istart, iend, rootval);
		TreeNode *res = new TreeNode(rootval);
		res->left = buildTreeRecur(istart, iterroot, pstart + 1, pstart + 1 + (iterroot - istart));
		res->right = buildTreeRecur(iterroot + 1, iend, pstart + 1 + (iterroot - istart), pend);
		return res;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		// write your code here
		return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
	}
};