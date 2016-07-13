class Solution {//O(n) is not so good
public:
	int findMin(vector<int>& nums) {
		//	if (nums.empty())
		//	throw new std::exception("size is zero");
		int min = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < min)
				min = nums[i];
		}
		return min;
	}
};
class Solution {//devide and conquer
public:
	int findMin(vector<int>& nums) {
		//inputparameter check

		int begin = 0, end = nums.size() - 1;
		int mid = begin;
		while (nums[begin] > nums[end]) {
			if (begin == end - 1) {
				mid = end;
				break;
			}
			mid = (begin + end) / 2;
			if (nums[mid] > nums[begin])
				begin = mid;
			else if (nums[mid] < nums[end])
				end = mid;

		}
		return nums[mid];

	}
};
class Solution {
public:
	/**
	* @param num: a rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &num) {
		// write your code here
		int left = 0, right = num.size() - 1, mid;
		while (num[left]>num[right]) {
			mid = (left + right) / 2;
			if (num[mid] >= num[left] && num[mid]>num[right]) left = mid + 1;
			else right = mid;
		}
		return num[left];
	}
};