//Remove all elements from a linked list of integers that have value val.



#include "Header.h"

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
 class Solution {
 public:
	 ListNode* removeElements(ListNode* head, int val) {
		 if (head == nullptr) return head;
		 ListNode* pAux =new ListNode(0);
		 ListNode* pNode = pAux;
		 while (head!=nullptr ) {
			 if (head->val != val) {//���val���Ȳż���node��
				 pNode->next = head;
				 pNode = pNode->next;
				 
			 }
			 else {
				 pNode->next = nullptr;//����val�ڵ���Ҫ��Node�Ͽ���Ҫ�����һ���ڵ㲻�Ͽ��Ļ�����������

			 }
			 head = head->next;

			 }

		 return pAux->next;
	 }
 };
 // ֱ����������в���ѽ
 class Solution1 {
 public:
	 ListNode* removeElements(ListNode* head, int val) {
		 if (head == nullptr) return head;
		 ListNode* pAux = new ListNode(0);
		 ListNode* pNode = pAux;
		 pAux->next = head;
		 while (pNode->next != nullptr) {
			 if (pNode->next->val == val)
				 pNode->next = pNode->next->next;
			 else
				 pNode = pNode->next;
		 }

		 return pAux->next;
	 }
 };