class Solution {
public:
	int search(vector<int>& nums, int target)
	{
		if (nums.empty()) return -1;
		int size = nums.size();
		int l = 0, r = size - 1, m = 0;
		while (l < r)
		{
			m = (l + r) / 2;
			if (target == nums[m]) return m;


			if (nums[m] > nums[r])
			{
				if (nums[m]>target && nums[l] <= target) r = m;
				else l = m + 1;
			}
			else if (nums[m] < nums[r])
			{
				if (nums[m] < target && nums[r] >= target) l = m + 1;
				else r = m;
			}
			else
				r--;
		}
		return nums[l] == target ? l : -1;
	}
};


//a simple c++ recuresive solution

bool search(vector<int>& nums, int target) {
	return search(0, nums.size() - 1, target, nums);
}

bool search(int low, int high, int target, vector<int>& nums) {
	if (low == high)
		return nums[low] == target;

	int mid = (low + high) / 2;

	if (nums[low] == nums[mid])
		return search(low, mid, target, nums) || search(mid + 1, high, target, nums);

	if (nums[low]<nums[mid])
		target >= nums[low] && target <= nums[mid] ? high = mid : low = mid + 1;
	else
		target >= nums[low] || target <= nums[mid] ? high = mid : low = mid + 1;
	return search(low, high, target, nums);
}
