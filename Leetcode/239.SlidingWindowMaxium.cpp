class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> max;
		if (nums.size() < k || k <= 0)
			return max;
		deque<int> index;

		//����ǰk��Ҳ���Ǵ��ڴ�С�ҵ�����index
		/*

		for (int i = 0; i < k; i++) {
		if (index.empty())
		index.push_back(i);
		else {
		while (nums[index.back()] <= nums[i])��Ҫ���жϲ���popback����
		index.pop_back();
		index.push_back(i);
		}

		}
		*/
		for (int i = 0; i < k; i++) {
			while (!index.empty() && nums[i] >= nums[index.back()])
				index.pop_back();

			index.push_back(i);
		}

		//start sliding windows
		for (int i = k; i < nums.size(); i++) {
			max.push_back(nums[index.front()]);

			//if nums[i] >��ǰ��index
			while (!index.empty() && nums[index.back()] <= nums[i])
				index.pop_back();

			if (!index.empty() && index.front() <= i - k)
				index.pop_front();
			index.push_back(i);
		}
		max.push_back(nums[index.front()]);
		return max;
	}
};