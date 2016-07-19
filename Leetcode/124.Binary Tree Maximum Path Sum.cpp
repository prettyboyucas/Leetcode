
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int maxValue = numeric_limits<int>::min();
		maxPath(root, maxValue);
		return maxValue;
	}
	int maxPath(TreeNode* root, int& maxValue) {
		if (root == nullptr)
			return 0;
		int left = max(0, maxPath(root->left, maxValue));//���������
		int right = max(0, maxPath(root->right, maxValue));//�ұ�������
		maxValue = max(maxValue, left + right + root->val);//�����������·����
		return max(left, right) + root->val;//�����������������ֵ���ϸýڵ��ֵ
	}
};