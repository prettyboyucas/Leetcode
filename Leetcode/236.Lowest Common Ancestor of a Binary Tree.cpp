class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q)
			return root;
		//����ÿһ�ڵ㣬���left ��right����һ��û�ҵ��Ļ���˵���ýڵ㲻��lca,��Ҫ���ϴ��ݸ÷ǿ�ֵ�����ڸ������˰���
		TreeNode* left = lowestCommonAncestor(root->left, p, q);//��֧��root ==p�ġ�
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		//return !left ? right : !right ? left : root;
		if (left && right) return root;
		return left ? left : right;
	}
};
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		if (left && left != p && left != q)
			return left;
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (right && left) return root;
		return left ? left : right;
	}
};
//������ѽʲô�㷨
class Solution {
	struct Frame {
		TreeNode* node;
		Frame* parent;
		vector<TreeNode*> subs;
	};
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		Frame answer;
		stack<Frame> stack;
		stack.push({ root, &answer });
		while (stack.size()) {
			Frame *top = &stack.top();
			Frame* parent = top->parent;
			TreeNode* node = top->node;
			if (!node || node == p || node == q) {
				parent->subs.push_back(node);
				stack.pop();
			}
			else if (top->subs.empty()) {
				stack.push({ node->right, top });
				stack.push({ node->left, top });
			}
			else {
				TreeNode* left = top->subs[0];
				TreeNode* right = top->subs[1];
				parent->subs.push_back(!left ? right : !right ? left : node);
				stack.pop();
			}
		}
		return answer.subs[0];
	}
};
//�ҵ��������·������͹����ڵ���Ƿֲ�Ľڵ㡣
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*p, TreeNode* q) {
		if (root == nullptr || p == nullptr || q == nullptr);

		vector<TreeNode*> pathp;
		vector<TreeNode*> pathq;
		pathp.push_back(root);
		pathq.push_back(root);

		getPath(root, p, pathp);
		getPath(root, q, pathq);

		TreeNode* lca = nullptr;
		for (int i = 0; i < pathp.size() && i < pathq.size(); i++) {
			if (pathp[i] == pathq[i])
				lca = pathp[i];
			else
				break;
		}
		return lca;
	}

private:
	bool getPath(TreeNode* root, TreeNode* n, vector<TreeNode*>& path) {
		if (root == n)
			return true;

		if (root->left != nullptr) {
			path.push_back(root->left);
			if (getPath(root->left, n, path))
				return true;
			path.pop_back();
		}
		if (root->right != nullptr) {
			path.push_back(root->right);
			if (getPath(root->right, n, path))
				return true;
			path.pop();
		}
		return false;
	}
};


//���ϸ��ⷨһ������·����

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void getPath(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &path, vector<TreeNode *> &path1, vector<TreeNode*> &path2) {
		if (root == NULL) return;
		path.push_back(root);
		if (root == p) path1 = path;
		if (root == q) path2 = path;
		//�ҵ������ڵ��Ϳ����˳���
		if (!path1.empty() && !path2.empty()) return;
		getPath(root->left, p, q, path, path1, path2);
		getPath(root->right, p, q, path, path1, path2);
		path.pop_back();
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path, path1, path2;
		getPath(root, p, q, path, path1, path2);
		TreeNode *res = root;
		int idx = 0;
		while (idx < path1.size() && idx < path2.size()) {
			if (path1[idx] != path2[idx]) break;
			else res = path1[idx++];
		}
		return res;
	}
};