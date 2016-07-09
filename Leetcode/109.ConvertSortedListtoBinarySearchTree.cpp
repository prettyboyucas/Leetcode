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
		ListNode* pfirst = nullptr;//slow֮ǰ�ýڵ�
		while (pFast->next != nullptr && pFast->next->next != nullptr) {
			pfirst = pSlow;

			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}//����ָ�����е�



		TreeNode* root = new TreeNode(pSlow->val);
		if (pfirst != nullptr)//�ڵ�Ϊ�յĻ�˵��ֻ��һ���������ڵ㡣�������Ӷ�û��
		{
			//if()
			pfirst->next = nullptr;//�Ͽ����������
			root->left = sortedListToBST(head);
		}
		root->right = sortedListToBST(pSlow->next);

		return root;


	}
};