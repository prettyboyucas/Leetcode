class Codec {
public:

	// Encodes a tree to a single string.
	string serialize1(TreeNode* root) {
		string str;
		if (root == nullptr) {
			str.append("$ ");
			return str;
		}
		str = str + to_string(root->val) + ' ';
		str = str + serialize(root->left);
		str = str + serialize(root->right);
		return str;

	}
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}
	void serialize(TreeNode* root, ostringstream& out) {
		if (root) {
			out << root->val << ' ';
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else {
			out << "# ";
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

		istringstream in(data);
		return deserialize(in);
	}

private:
	TreeNode* deserialize(istringstream& in) {
		string val;
		in >> val;
		if (val == "$") return nullptr;
		TreeNode* root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//bfs
class Codec {
public:
	string serialize(TreeNode* root) {
		ostringstream out;
		queue<TreeNode*> q;
		if (root)
			q.push(root);

		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (t) {
				out << t->val << ' ';
				q.push(t->left);
				q.push(t->right);
			}
			else {
				out << " # ";
			}
		}
		return out.str();
	}
	//decodes
	TreeNode* deserialize(string data) {
		if (data.empty())
			return nullptr;
		istringstream in(data);
		queue<TreeNode*> q;
		string val;
		in >> val;
		TreeNode* res = new TreeNode(stoi(val));
		TreeNode* cur = res;
		q.push(cur);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();

			if (!(in >> val)) break;
			if (val != "#") {
				cur = new TreeNode(stoi(val));
				q.push(cur);
				t->left = cur;
			}
			if (!(in >> val)) break;
			if (val != "#") {
				cur = new TreeNode(stoi(val));
				q.push(cur);
				t->right = cur;
			}
		}
		return res;
	}
};
