#include <iostream>
#include <string>
#include <vector>




 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//解法一：遍历两次的解法
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
			return NULL;
		ListNode* pNode = head;
		int nodeNum = 0;
		//遍历取得链表长度
		while (pNode != NULL) {
			++nodeNum;
			pNode = pNode->next;
		}
		//倒数第K个节点就是从头的第nodeNum-n+1个节点
		int i = 1;//初始化第一个节点
		//如果是头节点的话
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