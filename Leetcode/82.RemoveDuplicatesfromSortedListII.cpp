
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* pAux = new ListNode(0);
		ListNode* pHead = pAux;
		pHead->next = head;

		while (head != nullptr) {
			while (head->next != nullptr && pHead->next->val == head->next->val) {
				head = head->next;
			}
			//���ѭ��һ��ûִ�У���head����ԭ���ĵط���
			if (pHead->next == head)
				pHead = pHead->next;
			else
				pHead->next = head->next;
			head = head->next;
		}
		return pAux->next;

	}
};

//�ο����˵�
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *root = NULL;
		ListNode **ppNext = &root;
		while (head) {
			if (head->next == NULL || head->next->val != head->val) {
				*ppNext = head;
				ppNext = &(head->next);
				head = head->next;
			}
			else {
				int val = head->val;
				do {
					head = head->next;
				} while (head != NULL && head->val == val);
			}
		}
		*ppNext = NULL;
		return root;
	}
};