class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || nums.size() == k)
			return;
		int length = nums.size();
		if (k > length)
			k -= length;

		for (int i = 0; i < length - k; i++) {
			nums.push_back(nums[i]);
		}
		nums.erase(nums.begin(), nums.begin() + length - k);
	}
};

//jiuzhang suanfa sulution
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty())
			return;
		int length = nums.size();
		k = k%length;

		reverse(nums.begin(), nums.begin() + length - k);
		reverse(nums.begin() + length - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};