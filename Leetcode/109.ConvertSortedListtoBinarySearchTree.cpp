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
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* pSlow = head;
		ListNode* pFast = head;
		ListNode* pfirst = nullptr;//slow之前得节点
		while (pFast->next != nullptr && pFast->next->next != nullptr) {
			pfirst = pSlow;

			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}//快慢指针找中点



		TreeNode* root = new TreeNode(pSlow->val);
		if (pfirst != nullptr)//节点为空的话说明只有一个或两个节点。左子树坑定没了
		{
			//if()
			pfirst->next = nullptr;//断开链表分两段
			root->left = sortedListToBST(head);
		}
		root->right = sortedListToBST(pSlow->next);

		return root;


	}
};