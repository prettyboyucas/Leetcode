#include "Header.h"
//也可以先排序再比较相邻的两个数是否相等
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); ++i) {
			if (m.find(nums[i]) != m.end())
				return true;
			else
				m[nums[i]] = i;
		}
		return false;
	}
};