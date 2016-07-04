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