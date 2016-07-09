
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		vector<int> element;
		if (root == nullptr)
			return res;
		queue<TreeNode*> nodes;
		nodes.push(root);
		int nextLevel = 0;
		int curLevel = 1;
		while (!nodes.empty()) {
			TreeNode* pNode = nodes.front();
			element.push_back(pNode->val);

			if (pNode->left != nullptr) {
				nodes.push(pNode->left);
				nextLevel++;
			}
			if (pNode->right != nullptr) {
				nodes.push(pNode->right);
				nextLevel++;
			}
			nodes.pop();
			--curLevel;
			if (curLevel == 0) {
				res.push_back(element);
				element.clear();
				curLevel = nextLevel;
				nextLevel = 0;
			}
		}
		return res;

	}
};