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
		for (size_t i = 0; i<lists.size(); ++i) {
			ret = mergeTwoLists(ret, lists[i]);
		}
		return ret;
	}
};
//�ⷨ��:���÷��η�˼��ά��һ��k����С����С�ѣ���ʼ������Ԫ��Ϊÿ�������ͷ��㣬ÿ�δӶ���ѡ����С��Ԫ�ؼ��뵽���������ѡ�����СԪ�������������һ���ڵ���뵽���С���������Ϊ��ʱ����������Ľڵ㶼�Ѿ������˽������Ԫ�ؼ�����еĸ��Ӷ�ΪO��longk�����ܹ���kn��Ԫ�ؼ�����У���ˣ����Ӷ�Ҳ���㷨2һ����O��nklogk��
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

//�ⷨ3 ���ö��ַ������õݹ�

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
