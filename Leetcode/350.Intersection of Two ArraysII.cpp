/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
//int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

//}

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
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
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
			++tmp1_loc;
			++tmp2_loc;
			last_tmp1_value = tmp1[tmp1_loc];
			last_tmp2_value = tmp2[tmp2_loc];
			/*

			while((tmp1[tmp1_loc] == last_tmp1_value) && (tmp1_loc < nums1Size)) {
			++tmp1_loc;
			}

			last_tmp1_value = tmp1[tmp1_loc];

			while((tmp2[tmp2_loc] == last_tmp2_value) && (tmp2_loc < nums2Size)) {
			++tmp2_loc;
			}

			last_tmp2_value = tmp2[tmp2_loc];
			*/

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