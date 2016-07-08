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
			 if (head->val != val) {//如果val不等才加入node中
				 pNode->next = head;
				 pNode = pNode->next;
				 
			 }
			 else {
				 pNode->next = nullptr;//遇到val节点需要把Node断开，要是最后一个节点不断开的话就有问题了

			 }
			 head = head->next;

			 }

		 return pAux->next;
	 }
 };
 // 直接在上面进行操作呀
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