#include <iostream>
#include <vector>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
	 ListNode* swapPairs(ListNode* head) {
		 if (head == nullptr || head->next == nullptr)
			 return head;

		 ListNode* pAux = new ListNode(0);
		 ListNode* pHead = pAux;

		 ListNode* pNode = head;
		 ListNode* pCur = head->next;

		 ListNode* pPre = head;
		 ListNode* pNext = nullptr;
		 ListNode* pNextNext = nullptr;
		 pHead->next = pCur;
		 while (pCur != nullptr) {
			 pNext = pCur->next;//保存下一个节点

			 pCur->next = pPre;//反转链表指向奇数节点
			 if (pNext == nullptr) {//如果后面没有节点直接赋值nullptr结束循环。
				 pPre->next = nullptr;
				 pCur = nullptr;
			 }
			 else {
				 if (pNext->next == nullptr) {//后面还剩一个节点直接连上就行
					 pPre->next = pNext;
					 pCur = nullptr;
				 }
				 else {
					 pCur = pNext->next;//后面还有两个节点那就继续循环
					 pPre->next = pCur;
					 pPre = pNext;
				 }
			 }
		 }

		 return pAux->next;
	 }
 };