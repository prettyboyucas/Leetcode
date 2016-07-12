class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr || head->next == nullptr || m == n)
			return head;
		ListNode* pAux = new ListNode(0);
		pAux->next = head;
		ListNode* pnode = head;
		ListNode* pre = pAux;
		int begin = 1;
		while (begin < m && pnode->next != nullptr) {//first move to m
			begin++;
			pre = pnode;
			pnode = pnode->next;
		}
		while (begin < n && pnode->next != nullptr) {//then reverse m & n
			ListNode* temp = pnode->next;
			pnode->next = temp->next;
			temp->next = pre->next;
			pre->next = temp;
			begin++;
		}
		return pAux->next;
	}
};