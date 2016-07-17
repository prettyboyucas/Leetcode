//naive solution,there must be a better idea.
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();

		sort(nums.begin(), nums.end());
		return nums[len / 2];
	}
};

//C语言的方法
void swap1(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//我的版本
int myPartiton(int data[], int start, int end) {
	int small = start;
	for (int index = start; index < end; index++) {
		if (data[index] < data[end]) {
			if (index != small)
				swap1(&data[index], &data[small]);

			//增加索引
			small++;
		}
	}
	if (small != end) {
		swap1(&data[small], &data[end]);
	}
	return small;
}


//is morethan half number
int majorityElement(int* numbers, int length) {
	if (length <= 0)
		return 0;

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;

	int index = myPartiton(numbers, start, end);
	while (index != middle) {
		if (index > middle) {
			end = index - 1;
			index = myPartiton(numbers, start, end);
		}
		else {
			start = index + 1;
			index = myPartiton(numbers, start, end);
		}

	}
	int result = numbers[middle];
	return result;
}


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();

		sort(nums.begin(), nums.end());
		return nums[(len - 1) / 2];
	}
	//private:
	int Partition(int data[], int length, int start, int end) {
		if (data == nullptr || length <= 0 || start < 0 || end >= length)
			throw std::exception("Invalid parameters");
		int index = RandomInRange(start, end);
		swap(data[index], data[end]);
		int small = start - 1;
		for (index = start; index < end; ++index) {
			if (data[index] < data[end]) {
				++small;
				if (small != index)
					swap(data[index], data[small]);
			}
		}
		++small;
		swap(data[small], data[end]);
		return small;
	}
	int RandomInRange(int start, int end) {
		srand(time(0));
		return rand() % (end - start) + start;
	}
	void QuickSort(int data[], int length, int start, int end) {
		if (start == end)
			return;
		int index = Partition(data, length, start, end);
		if (index > start)
			QuickSort(data, length, start, index - 1);
		if (index < end)
			QuickSort(data, length, index + 1, end);
	}



	//我的版本
	int myPartiton(int data[], int start, int end) {
		int small = start;
		for (int index = start; index < end; index++) {
			if (data[index] < data[end]) {
				if (index != small)
					swap(data[index], data[small]);

				//增加索引
				small++;
			}
		}
		if (small != end) {
			swap(data[small], data[end]);
		}
		return small;
	}
	void myQuicksort(int data[], int start, int end) {
		if (start == end)
			return;
		int index = myPartiton(data, start, end);
		if (index > start)
			myQuicksort(data, start, index - 1);
		if (index < end)
			myQuicksort(data, index + 1, end);
	}
};