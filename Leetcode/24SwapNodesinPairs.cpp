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
			 pNext = pCur->next;//������һ���ڵ�

			 pCur->next = pPre;//��ת����ָ�������ڵ�
			 if (pNext == nullptr) {//�������û�нڵ�ֱ�Ӹ�ֵnullptr����ѭ����
				 pPre->next = nullptr;
				 pCur = nullptr;
			 }
			 else {
				 if (pNext->next == nullptr) {//���滹ʣһ���ڵ�ֱ�����Ͼ���
					 pPre->next = pNext;
					 pCur = nullptr;
				 }
				 else {
					 pCur = pNext->next;//���滹�������ڵ��Ǿͼ���ѭ��
					 pPre->next = pCur;
					 pPre = pNext;
				 }
			 }
		 }

		 return pAux->next;
	 }
 };