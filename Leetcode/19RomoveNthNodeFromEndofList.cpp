#include <iostream>
#include <string>
#include <vector>




 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//�ⷨһ���������εĽⷨ
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
			return NULL;
		ListNode* pNode = head;
		int nodeNum = 0;
		//����ȡ��������
		while (pNode != NULL) {
			++nodeNum;
			pNode = pNode->next;
		}
		//������K���ڵ���Ǵ�ͷ�ĵ�nodeNum-n+1���ڵ�
		int i = 1;//��ʼ����һ���ڵ�
		//�����ͷ�ڵ�Ļ�
		if (nodeNum == n) {
			pNode = head->next;
			delete head;
			return pNode;
		}
		pNode = head;
		while (i < nodeNum - n) {
			pNode = pNode->next;
			i++;
		}
		ListNode* preNode = pNode;
		ListNode* NthNode = pNode->next;
		preNode->next = NthNode->next;
		delete NthNode;
		return head;
	}
};
//�ⷨ������������ָ�룬ǰ�����K-1,��ͷ������prehead����Ҫ�ҵĽڵ�
//��������Ҫ�ҵ��ǽڵ�ǰ�Ľڵ���ܰѸýڵ�ɾ���ˡ����������K��
class Solution2 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
			return NULL;
		ListNode* pAhead = head;
		ListNode* pBehind = head;
		//����ɾ��ͷ�ӵ�
		//pAhead��ǰ��n���ڵ�
		for (int i = 0; i < n; ++i) {
			if (pAhead != NULL)
				pAhead = pAhead->next;//��������ȸպõ���n,��pahead�պú���
			else
				return NULL;
		}
		//��ǰ��
		if (pAhead == NULL) {
			pBehind = head->next;
			delete head;
			return pBehind;
		}
		while (pAhead->next != NULL) {
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		ListNode* pNext = pBehind->next;
		pBehind->next = pNext->next;
		delete pNext;
		return head;
	}
};
//�ⷨ����newһ���ڵ�ָ��head

class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
			return NULL;
		ListNode* res = new ListNode(0);
		res->next = head;
		ListNode* pAhead = res;
		ListNode* pBehind = res;
		//����ɾ��ͷ�ӵ�
		//pAhead��ǰ��n���ڵ�
		for (int i = 0; i < n; ++i) {
			if (pAhead->next != NULL)
				pAhead = pAhead->next;//��������ȸպõ���n,��pahead�պú���
			else
				return NULL;
		}
		//��ǰ��
		while (pAhead->next != NULL) {
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		if (pBehind == res) {
			delete res;
			ListNode* secondNode = head->next;
			delete head;
			return secondNode;
		}
		ListNode* pNext = pBehind->next;
		pBehind->next = pNext->next;
		delete pNext;
		return head;
	}
};