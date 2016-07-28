



/*
The idea is that when rotating the array, there must be one half of the array that is still in sorted order.
For example, 6 7 1 2 3 4 5, the order is disrupted from the point between 7 and 1. So when doing binary search,
we can make a judgement that which part is ordered and whether the target is in that range,
if yes, continue the search in that half, if not continue in the other half.

*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.length - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (nums[mid] == target)
				return mid;

			if (nums[start] <= nums[mid]) {
				if (target < nums[mid] && target >= nums[start])
					end = mid - 1;
				else
					start = mid + 1;
			}

			if (nums[mid] <= nums[end]) {
				if (target > nums[mid] && target <= nums[end])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}
};

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		int length = nums.size();
		int start = 0;
		int end = length - 1;

		while (start < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] >nums[end])
				start = mid + 1;
			else
				end = mid;
		}
		int rot = start;
		//
		start = 0;
		end = length - 1;
		//binary search
		while (start <= end) {
			int mid = start + (end - start) / 2;
			int realmid = (mid + rot) % length;
			if (nums[realmid] == target)
				return realmid;
			if (nums[realmid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return -1;
	}
};

/*use two help functions to search in rotated and unrotated array.

do a cut in the middle, the array would be divided into two arrays, 
one is rotated and one is unrotated. Then we can keep cutting by calling help 
function recursively.*/
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
				if (nums[m]<target && nums[r] >= target) l = m + 1;
				else r = m;
			}
		}
		return nums[l] == target ? l : -1;
	}
};