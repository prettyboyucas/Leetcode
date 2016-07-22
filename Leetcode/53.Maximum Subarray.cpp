//���sumС��0������Ϊ0
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = numeric_limits<int>::min();
		int sum = 0;
		for (auto& ele : nums) {
			sum += ele;
			maxSum = max(maxSum, sum);//�������ֵ
			sum = sum < 0 ? 0 : sum;//���sumС��0������Ϊ0
		}

		return maxSum;
	}
};
//��̬�滮��
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