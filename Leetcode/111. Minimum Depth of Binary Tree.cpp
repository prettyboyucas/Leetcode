struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int nLeft = minDepth(root->left);
		int nRight = minDepth(root->right);
		if (nLeft == 0)//���ǵ�һ������Ϊ�յĻ�����ô��Сֵ������һ��������1��
			return nRight + 1;
		if (nRight == 0)
			return nLeft + 1;
		return nLeft > nRight ? nRight + 1 : nLeft + 1;
	}
};

//BFS��������Ļ���⵽һ��Ҷ�ڵ�Ϳ��Խ����ˡ�

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		queue<TreeNode*> level;
		level.push(root);
		int cur = 1;
		int next = 0;
		int num = 1;
		while (!level.empty()) {
			TreeNode* Node = level.front();
			level.pop();
			cur--;//�Լ�һ����Ҫ�����ˡ�
			if (Node->left == nullptr && Node->right == nullptr)
				return num;
			if (Node->left != nullptr) {
				level.push(Node->left);
				next++;
			}
			if (Node->right != nullptr) {
				level.push(Node->right);
				next++;
			}
			if (cur == 0) {
				num++;
				cur = next;
				next = 0;
			}
		}
		return 0;

	}
};