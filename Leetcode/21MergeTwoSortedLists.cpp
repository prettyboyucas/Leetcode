#include <iostream>
#include <string>
#include <stack>
#include <map>

using std::map;
using std::stack;
using std::string;


//Definition for singly-linked list.
struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
		while (l1 != NULL) {
			pNode->next = l1;
			pNode = pNode->next;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			pNode->next = l2;
			pNode = pNode->next;
			l2 = l2->next;
		}
		ListNode* preHead = pHead->next;
		delete pHead;
		return preHead;
	}
};