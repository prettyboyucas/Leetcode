class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root == nullptr)
			return res;
		dfs(root, "", res);
		return res;
	}
	void dfs(TreeNode* root, string out, vector<string>& res) {
		out += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr)
			res.push_back(out);
		else {
			if (root->left)
				dfs(root->left, out + "->", res);
			if (root->right)
				dfs(root->right, out + "->", res);
		}

	}
};

class Solution {//倒过来进行，把根节点插入前面的地方就行。
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		//vector<string>
		if (root == nullptr)
			return{};
		if (root->left == nullptr && root->right == nullptr)
			return{ to_string(root->val) };
		vector<string> left = binaryTreePaths(root->left);
		vector<string> right = binaryTreePaths(root->right);
		left.insert(left.end(), right.begin(), right.end());
		for (auto& ele : left)
			ele = to_string(root->val) + "->" + ele;
		return left;
	}
};