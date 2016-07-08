#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
using std::list;
using std::priority_queue;
using std::map;
using std::stack;
using std::string;

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
		for (size_t i = 0; i<lists.size(); ++i) {
			ret = mergeTwoLists(ret, lists[i]);
		}
		return ret;
	}
};
//解法二:利用分治法思想维护一个k个大小的最小堆，初始化堆中元素为每个链表的头结点，每次从堆中选择最小的元素加入到结果链表，再选择该最小元素所在链表的下一个节点加入到堆中。这样当堆为空时，所有链表的节点都已经加入了结果链表。元素加入堆中的复杂度为O（longk），总共有kn个元素加入堆中，因此，复杂度也和算法2一样是O（nklogk）
class Solution32 {
private:
	class cmp {
	public:
		bool operator() (const ListNode* lhs, const ListNode* rhs) {
			return lhs->val > rhs->val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		size_t n = lists.size();
		ListNode* pHead = new ListNode(0);
		ListNode* pNode = pHead;
		priority_queue<ListNode*, vector<ListNode*>, cmp> min_que;
		for (size_t i = 0; i < n; ++i) {
			if (lists[i] != nullptr)
				min_que.push(lists[i]);
		}
		while (!min_que.empty()) {
			ListNode* topNode = min_que.top();
			pNode->next = topNode;
			min_que.pop();

			pNode = pNode->next;

			if (topNode->next != nullptr)
				min_que.push(topNode->next);
		}
		ListNode* result = pHead->next;
		delete pHead;
		return result;


	}
};

//解法3 采用二分法，利用递归

class Solution21_23 {
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
		if (lists.empty())
			return nullptr;
		size_t start = 0;
		size_t end = lists.size() - 1;
		while (end > 0) {
			start = 0;
			while (start < end) {
				lists[start] = mergeTwoLists(lists[start], lists[end]);
				start++;
				end--;
			}
		}
		return lists[0];
	}

};
