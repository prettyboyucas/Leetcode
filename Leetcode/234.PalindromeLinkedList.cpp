
//快慢指针+ 反转链表
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		// tranvese last final half list
		if (head == nullptr || head->next == nullptr)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* last = slow->next;
		while (last->next != nullptr) {
			ListNode* tmp = last->next;
			last->next = tmp->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}
		last = slow->next;
		while (last != nullptr) {
			if (head->val != last->val)
				return false;
			head = head->next;
			last = last->next;
		}
		return true;



	}
};