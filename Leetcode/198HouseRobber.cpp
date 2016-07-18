class Solution1 {//前往后递归超时要不得，重复计算很多次。
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int len = nums.size() - 1;
		return robRecursive(nums, len);
	}
	int robRecursive(vector<int>& nums, int length) {
		if (length == 0)
			return nums[0];
		if (length == 1)
			return max(nums[0], nums[1]);
		return max(robRecursive(nums, length - 1), robRecursive(nums, length - 2) + nums[length]);
	}
};


class Solution {//用数组吧前面的计算结果保存起来就行。
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int length = nums.size();
		if (length == 1)
			return nums[0];
		vector<int> result(length, 0);
		result[0] = nums[0];
		result[1] = nums[0] > nums[1] ? nums[0] : nums[1];
		for (int i = 2; i < length; i++) {
			result[i] = result[i - 1]>(result[i - 2] + nums[i]) ? result[i - 1] : (result[i - 2] + nums[i]);
		}
		return result[length - 1];
	}
};
