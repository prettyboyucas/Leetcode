class Solution {//��һ�ֽ�������ͷָ��ֱ���н�������������
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
		while (pnode != nullptr && pnode->next != nullptr) {//ע��������pnode!==nullptr
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
