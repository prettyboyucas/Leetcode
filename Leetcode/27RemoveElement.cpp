#include "Header.h"

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int length = nums.size();
		int len = 0;
		for (int i = 0; i < length; ++i) {
			if (nums[i] £¡ = val)
				nums[len++] = nums[i];
		}
		return len;
	}
};