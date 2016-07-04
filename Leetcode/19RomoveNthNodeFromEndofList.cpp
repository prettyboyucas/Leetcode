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
//解法二：定义两个指针，前后相差K-1,从头遍历，prehead就是要找的节点
//但是我们要找的是节点前的节点才能把该节点删除了。所以是相差K。
class Solution2 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
			return NULL;
		ListNode* pAhead = head;
		ListNode* pBehind = head;
		//考虑删除头加点
		//pAhead往前走n个节点
		for (int i = 0; i < n; ++i) {
			if (pAhead != NULL)
				pAhead = pAhead->next;//如果链表长度刚好等于n,者pahead刚好合适
			else
				return NULL;
		}
		//往前走
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
//解法三：new一个节点指向head

class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
			return NULL;
		ListNode* res = new ListNode(0);
		res->next = head;
		ListNode* pAhead = res;
		ListNode* pBehind = res;
		//考虑删除头加点
		//pAhead往前走n个节点
		for (int i = 0; i < n; ++i) {
			if (pAhead->next != NULL)
				pAhead = pAhead->next;//如果链表长度刚好等于n,者pahead刚好合适
			else
				return NULL;
		}
		//往前走
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