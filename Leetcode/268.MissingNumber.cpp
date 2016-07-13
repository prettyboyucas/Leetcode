
//hashtable
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		if (nums.empty())
			return -1;
		unordered_map<int, int> m;
		for (auto& i : nums)
			m[i]++;
		for (int i = 0; i <= nums.size(); ++i) {
			if (m[i] == 0)
				return i;
		}
		return -1;
	}
};

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		//	if (nums.empty())
		//	return -1;
		//	return nums.size()*(nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
		int len = nums.size();
		return static_cast<unsigned int>(len*(len + 1)) / 2 - accumulate(nums.begin(), nums.end(), 0);
	}
};
//binary sort like find dupulicate number 1~n
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int left = 0;
		int right = nums.size();
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid]>mid)
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};

//¿‡À∆SingleNumble use bit manipulation
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			res ^= (i + 1) ^ nums[i];
		}
		return res;
	}
};