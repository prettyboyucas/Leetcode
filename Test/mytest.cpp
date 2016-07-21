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

//如果sum小于0，重置为0
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = numeric_limits<int>::min();
		int sum = 0;
		for (auto& ele : nums) {
			sum += ele;
			maxSum = max(maxSum, sum);//保存最大值
			sum = sum < 0 ? 0 : sum;//如果sum小于0，重置为0
		}

		return maxSum;
	}
};
//动态规划呢
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int lens = nums.size();
		int res;
		vector<int> sum(lens + 1, 0);
		for (int i = 0; i < lens, i++) {
			sum[i + 1] = sum[i]>0 ? sum[i] + nums[i] : nums[i];
			if(sum[i+1]>res)
				res = 
		}
	}
}

















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
	cout << ss.lengthOfLongestSubstring("dvdf") << endl;
	unordered_set<char> m;
	m.insert('a');
	m.insert('f');
	m.insert('c');
	m.insert('a');
	m.insert('h');
	m.erase(m.begin(), next(m.find('f')));
	for (auto& item : m)
		cout << item << " ";


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