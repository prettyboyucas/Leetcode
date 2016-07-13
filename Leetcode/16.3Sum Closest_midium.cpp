class Solution {//jiabiyuanli
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int min_gap = numeric_limits<int>::max();
		sort(nums.begin(), nums.end());
		for (auto i = nums.begin(); i < prev(nums.end(), 2); ++i) {
			auto b = next(i);
			auto c = prev(nums.end());
			while (b < c) {
				int sum = *i + *b + *c;
				int gap = abs(sum - target);

				//store minimun gap and result;
				if (gap < min_gap) {
					result = sum;
					min_gap = gap;
				}
				if (sum > target)
					c--;
				else if (sum == target)
					return result;
				else
					b++;
			}
		}
		return result;
	}
};
