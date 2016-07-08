#include "stdafx.h"
using namespace std;


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* pNode = head;
		ListNode* pNew = head;
		pNew->next = nullptr;//必须先把节点断开。
		
		while (pNode->next !=  nullptr) {
			if (pNode->next->val != pNew->val) {
				

				pNew->next = pNode;
				pNew = pNew->next;
			}
			else {
				pNew->next = nullptr;
			}

				pNode = pNode->next;

			
		}
		return head;
	}
};


int main() {
	string s1 = "0";
	string s2 = "0";
	Solution sol;
	cout << sol.climbStairs(5) << endl;
	//string res = sol.multiply(s1, s2);
	//cout << res << endl;
	//for (auto& lel : res) {
	//	cout << lel;
	//}
	//for_each(res.begin(), res.end(), [](const char s) {cout << s; });
		return 0;
}