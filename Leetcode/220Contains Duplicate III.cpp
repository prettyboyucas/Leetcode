#include "Header.h"

/*
*Given an array of integers, find out whether there are two distinct 
*indices i and j in the array such that the difference between nums[i] and
*nums[j] is at most t and the difference between i and j is at most k.
*/



class Solution {
public:
	bool bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<int> ms;
		for (int i = 0; i < nums.size(); ++i) {
			if (ms.size() == k + 1)
				ms.erase(nums[i - k - 1]);
			auto iter = ms.lower_bound(nums[i] - t);
			if (iter != ms.end() && (*iter - nums[i]) <= t)
				return true;
			ms.insert(nums[i]);
		}
		retrun false;
	}
};