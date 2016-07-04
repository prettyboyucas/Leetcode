#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <list>
#include <vector>

using namespace std;
using std::list;

using std::map;
using std::stack;
using std::string;


//Definition for singly-linked list.
struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution21_1 {
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
		//如果一个链表完成，则直接连接另一个链表即可。不用挨个遍历啊，
		/*
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
		*/
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

//解法二：采用递归动态规划
class Solution1 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		ListNode* pNode = NULL;
		if (l1->val < l2->val) {
			pNode = l1;
			pNode->next = mergeTwoLists(l1->next, l2);
		}
		else {
			pNode = l2;
			pNode->next = mergeTwoLists(l1, l2->next);
		}
		return pNode;
	}
};

//23. Merge k Sorted Lists
//先merge两个，再循环调用一一个一个的merge;时间复杂度高啊n+2n+3n+...+kn
class Solution21_2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		else if (l2 == nullptr)
			return l1;
		ListNode* pNode = nullptr;
		if (l1->val < l2->val) {
			pNode = l1;
			pNode->next = mergeTwoLists(l1->next, l2);
		}
		else {
			pNode = l2;
			pNode->next = mergeTwoLists(l1, l2->next);
		}
		return pNode;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* ret = nullptr;
		for (size_t  i = 0; i<lists.size(); ++i) {
			ret = mergeTwoLists(ret, lists[i]);
		}
		return ret;
	}
};
//解法二:利用分治法思想