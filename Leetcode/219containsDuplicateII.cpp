#include "Header.h"
// 超出时间不可用
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= 1) return false;
		if (k == 0 && !nums.empty()) return false;
		int length = nums.size();
		for (int i = 0; i < length; ++i) {
			int max = length < i + k + 1 ? length : i + k + 1;
			for (int j = i+1; j < max; ++j) {
					if (nums[j] == nums[i]) {
						return true;
					}
			}
		}
		return false;
	}
};
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= 1 || k<=0) return false;
		map<int, int> km;
		for (int i = 0; i < nums.size(); ++i) {
			if (km.find(nums[i]) != km.end() && i - km[nums[i]] <= k)
				return true;
			else
				km[nums[i]] = i;

		}
		return false;
	}
};