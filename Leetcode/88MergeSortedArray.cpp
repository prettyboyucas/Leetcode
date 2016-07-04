#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Solution88_1 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums1.empty() && nums2.empty()  || m < 0 || n < 0)
			return;
		vector<int> res;
		size_t i = 0;
		size_t j = 0;
		while (i < m && j < n) {
			if (nums1[i] < nums2[j]) {
				res.push_back(nums1[i++]);
			}
			else {
				res.push_back(nums2[j++]);
			}
		}
		while (i < m) {
			res.push_back(nums1[i++]);
		}
		while (j < n) {
			res.push_back(nums2[j++]);
		}
		nums1.clear();
		for (auto& ele : res) {
			nums1.push_back(ele);
		}
	}
};
//直接在这nums1上进行操作。
class Solution88_2 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		while (i >= 0 && j >= 0) {
			nums1[pos--] = nums1[i]>nums2[j] ? nums1[i--] : nums2[j--];
		}
		//当i>=0是，不用操作就可以了。
		while (j >= 0)
			nums1[pos--] = nums2[j--];
	}
};