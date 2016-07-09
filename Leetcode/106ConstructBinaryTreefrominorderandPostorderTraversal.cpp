
//��ǰ�������һ����ֻ��ȡ�������һ��������������ͬ�������ǰһ��
class Solution {

public:
	typedef vector<int>::iterator Iter;
	TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
	{
		if (istart == iend)return NULL;
		int rootval = *(pend - 1);
		Iter iterroot = find(istart, iend, rootval);
		TreeNode *res = new TreeNode(rootval);
		res->left = buildTreeRecur(istart, iterroot, pstart, pstart + (iterroot - istart));
		res->right = buildTreeRecur(iterroot + 1, iend, pstart + (iterroot - istart), pend - 1);
		return res;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// write your code here
		return buildTreeRecur(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};
