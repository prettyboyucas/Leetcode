class Solution3 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> subs;
		vector<int> sub;
		genSubsets(nums, 0, sub, subs);
		return subs;
	}
	void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>> & subs) {
		subs.push_back(sub);
		for (int i = start; i < nums.size(); i++) {
			sub.push_back(nums[i]);
			genSubsets(nums, i + 1, sub, subs);
			sub.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> subs(1, vector<int>());
		for (int i = 0; i < nums.size(); i++) {
			int n = subs.size();
			for (int j = 0; j < n; j++) {
				subs.push_back(subs[j]);
				subs.back().push_back(nums[i]);
			}
		}
		return subs;
	}
};


class Solution3 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int num_subset = pow(2, nums.size());
		vector<vector<int>> res(num_subset, vector<int>());
		for (int i = 0; i < nums.size(); i++)
			for (int j = 0; j < num_subset; j++)
				if ((j >> i) & 1)
					res[j].push_back(nums[i]);

		return res;
	}
}