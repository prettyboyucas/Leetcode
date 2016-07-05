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
//���õ��ǲ��뷨��������
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
			//pre �������������������
			//��λ���ʼ���±������С�
			pre = pHead;
			while (pre->next != nullptr && pre->next->val <= cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;//��cur����pre->next֮ǰ
			pre->next = cur;//��cur����pre
			cur = pNext;//����������һ��
		}
		return pHead->next;

	}
};