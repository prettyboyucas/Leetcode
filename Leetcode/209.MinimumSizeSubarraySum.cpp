

class Solution {//效果渣得不行啊
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())
			return 0;
		int len = nums.size();
		int res = len + 1;
		for (int i = 0; i < len; i++) {
			int sum = 0;
			for (int j = i; j < len; j++) {
				sum += nums[j];
				if (sum >= s) {
					res = j - i + 1 < res ? j - i + 1 : res;
					break;
				}

			}
		}
		return (res == len + 1) ? 0 : res;
	}
};

class Solution {// 快慢维护一个sum
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())
			return 0;
		int len = nums.size();
		int res = len + 1;
		int slow = 0, fast = 0;
		int sum = 0;
		while (fast < len) {
			sum += nums[fast++];

			while (sum >= s) {
				sum -= nums[slow++];
				res = min(res, fast - slow + 1);
			}
		}
		return res == len + 1 ? 0 : res;

	}
};

class Solution {//upper_bound 主要适用在求和与一个值得关系
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> sums(nums.size(), 0);
		partial_sum(nums.begin(), nums.end(), sums.begin());
		int n = nums.size(), minlen = n + 1;
		for (int i = 0; i < n; i++) {
			if (sums[i] >= s) {
				auto p = upper_bound(sums.begin(), sums.begin() + i, sums[i] - s);

				if (p != sums.begin() + 1) {
					minlen = min(minlen, i - (p - sums.begin()) + 1);
				}
			}
		}
		return minlen == n + 1 ? 0 : minlen;
	}
};