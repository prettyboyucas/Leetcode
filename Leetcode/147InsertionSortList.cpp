#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <thread>
using namespace std;
/*
*147. Insertion Sort List
Sort a linked list using insertion sort.
*
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
//采用的是插入法进行排序。
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* pHead = new ListNode(0);
		ListNode* pre = pHead;
		ListNode* cur = head;
		while (cur != nullptr) {
			
			ListNode* pNext = cur->next;
			//pre 的链表是排序过的链表
			//置位到最开始重新遍历才行。
			pre = pHead;
			while (pre->next != nullptr && pre->next->val <= cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;//将cur插入pre->next之前
			pre->next = cur;//将cur插入pre
			cur = pNext;//递增进入下一个
		}
		return pHead->next;

	}
};