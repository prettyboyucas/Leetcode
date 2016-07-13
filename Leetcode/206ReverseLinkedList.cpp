//后面节点直接移动到前面

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* pAux = new ListNode(0);
		pAux->next = head;
		ListNode* pnode = head;
		ListNode* tmp = nullptr;
		while (pnode->next != nullptr) {
			tmp = pnode->next;
			pnode->next = tmp->next;
			tmp->next = pAux->next;
			pAux->next = tmp;
		}
		return pAux->next;
	}
};
//直接反转链表
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		

};