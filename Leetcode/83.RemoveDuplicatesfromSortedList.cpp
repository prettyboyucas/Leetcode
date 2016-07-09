//�Լ�д����ô��ô�ð�
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
		//pNew->next = nullptr;//�����Ȱѽڵ�Ͽ���

		while (pNode != nullptr && pNode->next != nullptr) {
			if (pNode->next->val != pNew->val) {


				pNew->next = pNode->next;
				pNew = pNew->next;
				pNode = pNode->next;//ȫ���ظ��Ķ���������Ҫ����

			}
			else {
				pNode->next = pNode->next->next;

			}
		}
		return head;
	}
};
//�ο����˵Ķ���

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