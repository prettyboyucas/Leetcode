class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> res;
		//res.push_back(nums[0]);
		for (const auto& item : nums) {
			vector<int>::iterator iter = lower_bound(res.begin(), res.end(), item);
			if (iter != res.end())
				*iter = item;
			else {
				res.push_back(item);
			}
		}
		return res.size();
	}
};

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> ends{ nums[0] };
		for (auto a : nums) {
			if (a < ends[0]) ends[0] = a;
			else if (a>ends.begin())
				ends.push_back(a);
			else {
				int left = 0, right = ends.size();
				while (left < right) {
					int mid = left + (right - left) / 2;
					if (ends[mid] < a) left = mid + 1;
					else
						right = mid;
				}
				ends[right] = a;
			}
		}
		return ends.size();
	}
};


//O(nlog(n))如果比最小的小，覆盖。比最大的大，添加。如果居中，知道第一个大于该数值的东东，覆盖。
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> res;
		//res.push_back(nums[0]);
		for (const auto& item : nums) {
			vector<int>::iterator iter = lower_bound(res.begin(), res.end(), item);
			if (iter != res.end())
				*iter = item;
			else {
				res.push_back(item);
			}
		}
		return res.size();
	}
};


//longest increaing Subsequence//动态规划DP
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] >= nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};