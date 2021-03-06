class Solution {
public:

	ListNode* hasCycle(ListNode *head) {//找到遇到的元素
		if (nullptr == head)
			return head;
		ListNode* slow = head;
		ListNode* fast = head->next;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return slow;
		}
		return nullptr;

	}

	ListNode *detectCycle(ListNode *head) {
		ListNode* pnode = hasCycle(head);
		if (nullptr == pnode)
			return nullptr;
		int num = 1;
		ListNode* it = pnode->next;
		while (pnode != it) {
			num++;
			it = it->next;//计算环大小
		}

		ListNode* slow = head;
		ListNode* fast = head;
		while (num) {
			fast = fast->next;
			num--;
		}

		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;

	}
};