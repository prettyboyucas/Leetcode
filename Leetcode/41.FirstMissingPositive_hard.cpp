

class Solution {//���ǳ���ʱ�临�Ӷȣ�����ȡ��
public:
	int firstMissingPositive(vector<int>& nums) {
		unordered_map<int, int> m;
		for (auto&i : nums) {
			if (i > 0) {
				m[i]++;
			}
		}
		int i = 1;
		while (m[i] >= 1) {
			i++;
		}
		return i;
	}
};

class Solution {//bucket sort
public:
	int firstMissingPositive(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			if (num > 0 && num <= nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[nums[i] - 1], nums[i]);
		}
		int res = 1;
		//	while (nums[res] == res)
		//	res++;
		for (auto& item : nums) {
			if (item == res)
				++res;
		}
		return res;

	}
};