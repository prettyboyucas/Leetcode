class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
		if (nums.empty())
			return res;
		if (nums.size() == 1) {
			res.push_back(nums[0]);
			return res;
		}

		int m1 = nums[0];
		int m2 = 0;
		int c1 = 1, c2 = 0;


		for (int i = 1; i < nums.size(); i++) {
			int x = nums[i];
			if (x == m1)
				c1++;
			else if (x == m2)
				c2++;
			else if (c1 == 0) {
				m1 = x;
				c1 = 1;
			}
			else if (c2 == 0) {
				m2 = x;
				c2 = 1;
			}
			else {
				--c1;
				--c2;
			}
		}
		c1 = 0;
		c1 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (m1 == nums[i]) ++c1;
			else if (m2 == nums[i]) ++c2;
		}
		if (c1 > nums.size() / 3) res.push_back(m1);
		if (c2 > nums.size() / 3) res.push_back(m2);
		return res;
	}
};
