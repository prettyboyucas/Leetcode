#include "Header.h"

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int length = nums.size();
		int len = 0;
		for (int i = 0; i < length; ++i) {
			if (nums[i] != 0) {
				nums[len++] = nums[i];
			}
		}
		for (; len < length; ++len) {
			nums[len] = 0;
		}
	}
};