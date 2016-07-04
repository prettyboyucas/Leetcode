#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <list>
#include <vector>
#include <queue>

using namespace std;


 //Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		//快慢指针得到中间点才行。
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = nullptr;
		//divide
		ListNode* p1 = sortList(head);
		ListNode* p2 = sortList(fast);
		//conquer
		return mergeTwoLists(p1,p2);
	}

private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		ListNode* pHead = new ListNode(0);
		ListNode* pNode = pHead;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				pNode->next = l1;
				pNode = pNode->next;
				l1 = l1->next;
			}
			else {
				pNode->next = l2;
				pNode = pNode->next;
				l2 = l2->next;
			}

		}
		//如果一个链表完成，则直接连接另一个链表即可。不用挨个遍历啊，
		if (l1 != NULL) {
			pNode->next = l1;
		}
		if (l2 != NULL) {
			pNode->next = l2;
		}
		ListNode* preHead = pHead->next;
		delete pHead;
		return preHead;
	}
};