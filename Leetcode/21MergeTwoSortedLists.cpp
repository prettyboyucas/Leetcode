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
		//���һ��������ɣ���ֱ��������һ�������ɡ����ð�����������
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

//�ⷨ�������õݹ鶯̬�滮
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
//��merge��������ѭ������һһ��һ����merge;ʱ�临�Ӷȸ߰�n+2n+3n+...+kn
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
//�ⷨ��:���÷��η�˼��