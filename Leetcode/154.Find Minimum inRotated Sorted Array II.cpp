class Solution {
public:
	int findMin(vector<int>& nums) {
		int begin = 0, end = nums.size() - 1;
		int mid = begin;
		while (nums[begin] >= nums[end]) {
			if (begin == end - 1) {
				mid = end;
				break;
			}
			mid = (begin + end) / 2;

			if (nums[mid] == nums[begin] && nums[mid] == nums[end])
				return MinInorder(nums);//特殊情况，三者一样，就直接用顺序查找方法。

			if (nums[mid] >= nums[begin])
				begin = mid;
			else if (nums[mid] <= nums[end])
				end = mid;

		}
		return nums[mid];
	}
private:
	int MinInorder(vector<int>& nums) {
		int min = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < min)
				min = nums[i];
		}
		return min;
	}
};

class Solution {
	int findMin(vector<int>& nums) {
		int lo = 0;
		int hi = nums.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid]> nums[hi]) {
				lo = mid + 1;
			}
			else if (nums[mid] < nums[hi]) {
				hi = mid;
			}
			else
			{
				hi--;
			}//减一来解决三者一样的情况。有道理
		}
		return nums[lo];
	}
};