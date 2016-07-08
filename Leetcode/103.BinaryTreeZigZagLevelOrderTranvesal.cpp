class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		vector<int> element;
		if (root == nullptr)
			return res;
		stack<TreeNode*> level[2];
		int cur = 0;
		int next = 1;
		level[cur].push(root);
		while (!level[0].empty() || !level[1].empty()) {
			TreeNode* pNode = level[cur].top();
			level[cur].pop();

			element.push_back(pNode->val);

			if (cur == 0) {
				if (pNode->left != nullptr)
					level[next].push(pNode->left);
				if (pNode->right != nullptr)
					level[next].push(pNode->right);

			}
			else {
				if (pNode->right != nullptr)
					level[next].push(pNode->right);
				if (pNode->left != nullptr)
					level[next].push(pNode->left);
			}


			if (level[cur].empty())
			{
				res.push_back(element);
				element.clear();
				cur = 1 - cur;
				next = 1 - next;
			}
		}
		return res;
	}
};