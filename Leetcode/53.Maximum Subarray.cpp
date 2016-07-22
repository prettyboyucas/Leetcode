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
		int res = 0;
		vector<int> sum(lens + 1, 0);
		for (int i = 0; i < lens; i++) {
			sum[i + 1] = sum[i]>0 ? sum[i] + nums[i] : nums[i];
			if (sum[i + 1]>res)
				res = sum[i + 1];
		}
		return res;
	}
}