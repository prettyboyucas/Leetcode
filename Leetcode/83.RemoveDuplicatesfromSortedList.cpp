//自己写的怎么这么烂啊
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* pNode = head;
		ListNode* pNew = head;
		//pNew->next = nullptr;//必须先把节点断开。

		while (pNode != nullptr && pNode->next != nullptr) {
			if (pNode->next->val != pNew->val) {


				pNew->next = pNode->next;
				pNew = pNew->next;
				pNode = pNode->next;//全身重复的东西，不需要这样

			}
			else {
				pNode->next = pNode->next->next;

			}
		}
		return head;
	}
};
//参考别人的东西

class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: head node
	*/
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}

		ListNode *node = head;
		while (node->next != NULL) {
			if (node->val == node->next->val) {
				node->next = node->next->next;
			}
			else {
				node = node->next;
			}
		}
		return head;
	}
};