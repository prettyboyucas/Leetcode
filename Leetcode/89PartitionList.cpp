class Solution {//另一种建立两个头指针分别进行建表再链接起来
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* pAux = new ListNode(0);
		pAux->next = head;
		ListNode* pnode = head;
		ListNode* pre = pAux;
		while (pnode != nullptr && pnode->val < x) {
			pre = pre->next;
			pnode = pnode->next;
		}
		while (pnode != nullptr && pnode->next != nullptr) {//注意必须加伤pnode!==nullptr
			if (pnode->next->val >= x) {
				pnode = pnode->next;
			}
			else {
				ListNode* temp = pnode->next;
				pnode->next = temp->next;
				temp->next = pre->next;
				pre->next = temp;
				pre = pre->next;
			}
		}
		return pAux->next;

	}
};
