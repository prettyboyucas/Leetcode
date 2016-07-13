class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr)//��ѽ�������ȺŰ�
			return false;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};