//#define  _CRT_SECURE_NO_WARNINGS


#include "stdafx.h"
#include "quote.h"




using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {

	}
};



class Solution {//修改右指针
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		TreeNode* cur = root;
		TreeNode* pre = nullptr;

		while (cur != nullptr) {
			if (cur->left == nullptr) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right != nullptr && pre->right != cur)
					pre = pre->right;
				if (pre->right == nullptr) {
					pre->right = cur;
					cur = cur->left;
				}
				else if (pre->right == cur) {
					pre->right = nullptr;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;

	}



};

class Solution {//修改右指针
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		TreeNode* cur = root;
		TreeNode* pre = nullptr;

		while (cur != nullptr) {

			

			if (cur->left == nullptr) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {

				pre = cur->left;
				while (pre->right != nullptr && pre->right != cur)
					pre = pre->right;//前驱节点


				if (pre->right == nullptr) {
					pre->right = cur;
					res.push_back(cur->val);//这就是先需了哇？
					cur = cur->left; //继续左走
				}
				else if (pre->right == cur) {//左走完了，恢复原状，右走
					pre->right = nullptr;
					//res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;

	}



};



class Solution {//修改右指针
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;

		TreeNode* cur = root;
		TreeNode* pre = nullptr;

		while (cur != nullptr) {



			if (cur->right == nullptr) {
				res.insert(res.begin(),cur->val);
				cur = cur->left;
			}
			else {

				pre = cur->right;
				while (pre->left != nullptr && pre->left != cur)
					pre = pre->left;//前驱节点


				if (pre->left == nullptr) {
					pre->left = cur;
					//res.push_back(cur->val);//这就是先需了哇？
					res.insert(res.begin(), cur->val);
					cur = cur->right; //继续左走
				}
				else if (pre->left == cur) {//左走完了，恢复原状，右走
					pre->left = nullptr;
					//res.push_back(cur->val);
					cur = cur->left;
				}
			}
		}
		return res;

	}
};





int main() {

	string str1("ABCDEFG");
	string str2(7, '\1');
	char a = 'a';
	char b = 'b';
	cout << addchar(a, b);
	cout << endl;


	cout << "hahaha" << endl;
	partial_sum(str1.begin(), str1.end(), str2.begin(),addchar);
	cout << str2 << endl;
	getchar();
	return 0;
}