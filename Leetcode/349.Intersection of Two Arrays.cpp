class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> inter;
		if (nums1.empty() || nums2.empty()) return inter;
		int i = 0, j = 0;
		int l1 = nums1.size(), l2 = nums2.size();
		map<int, int>m1;
		map<int, int>m2;
		for (; i < l1; ++i)
		{
			//if (m1[nums1[i]] != 1)
			//	{
			//	m1.insert(make_pair(nums1[i], 1));
			//}
			m1[nums1[i]]++;
		}
		for (; j < l2; ++j)
		{
			//if (m1[nums2[j]] == 1)
			//{
			//	m2.insert(make_pair(nums2[j], 1));
			//}
			m2[nums2[j]]++;
		}
		map<int, int>::iterator it = m2.begin();
		while (it != m2.end())
		{
			map<int, int>::iterator it2 = m1.find(it->first);
			if (it2 != m1.end())
			{
				inter.push_back(it->first);
			}
			++it;
		}
		return inter;

	}
};


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s(nums1.begin(), nums1.end()), res;
		for (auto a : nums2) {
			if (s.count(a)) res.insert(a);
		}
		return vector<int>(res.begin(), res.end());
	}
};
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		int i = 0, j = 0;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) ++i;
			else if (nums1[i] > nums2[j]) ++j;
			else {
				if (res.empty() || res.back() != nums1[i]) {
					res.push_back(nums1[i]);
				}
				++i; ++j;
			}
		}
		return res;
	}
};


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> res;
		sort(nums2.begin(), nums2.end());
		for (auto a : nums1) {
			if (binarySearch(nums2, a)) {
				res.insert(a);
			}
		}
		return vector<int>(res.begin(), res.end());
	}
	bool binarySearch(vector<int> &nums, int target) {
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return true;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return false;
	}
};

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
		return vector<int>(res.begin(), res.end());
	}
};


// CÓïÑÔ½â·¨

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *src, int *dst) {
	int tmp = *src;
	*src = *dst;
	*dst = tmp;
}

void quick_sort(int* unsorted, int low, int high) {
	if ((high - low) > 0) {
		int pivot = high;
		int lower_check = low;
		while (lower_check < pivot) {
			if ((pivot - lower_check) > 1) {
				if (unsorted[lower_check] > unsorted[pivot]) {
					swap(&unsorted[pivot], &unsorted[pivot - 1]);
					swap(&unsorted[lower_check], &unsorted[pivot]);
					--pivot;
				}
				else {
					++lower_check;
				}
			}
			else {
				if (unsorted[lower_check] > unsorted[pivot]) {
					swap(&unsorted[lower_check], &unsorted[pivot]);
					--pivot;
				}

				break;
			}
		}
		quick_sort(unsorted, low, pivot - 1);
		quick_sort(unsorted, pivot + 1, high);
	}
}

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int minSize;

	if (nums1Size <= nums2Size) {
		minSize = nums1Size;
	}
	else {
		minSize = nums2Size;
	}

	int *result = (int*)calloc(minSize, sizeof(int));

	int *tmp1 = (int*)calloc(nums1Size, sizeof(int));
	memcpy(tmp1, nums1, sizeof(int)*nums1Size);

	int *tmp2 = (int*)calloc(nums2Size, sizeof(int));
	memcpy(tmp2, nums2, sizeof(int)*nums2Size);

	quick_sort(tmp1, 0, nums1Size - 1);
	quick_sort(tmp2, 0, nums2Size - 1);

	int last_tmp1_value = tmp1[0];
	int last_tmp2_value = tmp2[0];
	int intersect_location = 0;

	int tmp1_loc = 0;
	int tmp2_loc = 0;
	while ((tmp1_loc < nums1Size) && (tmp2_loc < nums2Size)) {
		if (last_tmp1_value == last_tmp2_value) {
			result[intersect_location] = last_tmp1_value;
			++intersect_location;

			while ((tmp1[tmp1_loc] == last_tmp1_value) && (tmp1_loc < nums1Size)) {
				++tmp1_loc;
			}

			last_tmp1_value = tmp1[tmp1_loc];

			while ((tmp2[tmp2_loc] == last_tmp2_value) && (tmp2_loc < nums2Size)) {
				++tmp2_loc;
			}

			last_tmp2_value = tmp2[tmp2_loc];

		}
		else if (last_tmp1_value < last_tmp2_value) {
			while ((tmp1[tmp1_loc] == last_tmp1_value) && (tmp1_loc < nums1Size)) {
				++tmp1_loc;
			}

			last_tmp1_value = tmp1[tmp1_loc];
		}
		else {
			while ((tmp2[tmp2_loc] == last_tmp2_value) && (tmp2_loc < nums2Size)) {
				++tmp2_loc;
			}

			last_tmp2_value = tmp2[tmp2_loc];
		}
	}

	*returnSize = intersect_location;
	return result;
}