//#define  _CRT_SECURE_NO_WARNINGS


#include "stdafx.h"
#include <stdio.h>
#include <ctime>
#include <thread>
#include <process.h>
//#include <boost/algorithm/string.hpp>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> dict;
		vector<int> res;

		for (int i = 0; i < (int)nums1.size(); i++)
			dict[nums1[i]] ++;
		for (int i = 0; i < (int)nums2.size(); i++)
			if (dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);//空间复杂度o(m),比下面的o(m+n)小。
		//	if (--dict[nums2[i]] >= 0)
			//	res.push_back(nums2[i]);
		return res;
	}
};

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int n1 = nums1.size();
		int n2 = nums2.size();
		int i1 = 0;
		int i2 = 0;


		vector<int> res;

		while(i1 < n1 && i2 < n2) {
			if (nums1[i1] == nums2[i2])
			{
				res.push_back(nums1[i1]);
				i1++;
				i2++;

			}
			else if (nums1[i1] > nums2[i2]) {
				i2++;
			}
			else {
				i1++;
			}
		}
		return res;
	}
};





int main(){
	/*
	char* context = nullptr;
	 char* str1 = "1.2*3";
	 const char* sep = ".*";
	char* ptr = strtok_s(str1, sep, &context);
	

	while (ptr != nullptr) {
		cout << *ptr << endl;
		ptr = strtok_s(nullptr, '.', &context);
	}
	*/
	Solution ss;
	cout << ss.reverseString("abcdefghigklmnopqrstuvwxyz") << endl;


	vector<bool> bits;
	bits.push_back(true);
	const bool& j = bits.front();

	int data[] = { 3,2,3,8,8,8,8,8,8,8,5 };
	int data1[] = { 3,2,3 };

		

	//ss.QuickSort(data, 6, 0, 11);
	//cout << ss.MoreThanHalfNum(data1, 3) << endl;;
	//for (int i = 0; i < 11; i++) {
	//	cout << data[i] << " ";
	//}
	
	//cout << a << end;
	vector<int> vec{ 1,2,3,4,5,5,4,2,1 };
	string s = "1010101010";
	//cout << sizeof(int) << endl;
	int diff = 0b001110100;
	//int res = diff&(-diff);
	//cout << res << endl;
	getchar();
	return 0;
}