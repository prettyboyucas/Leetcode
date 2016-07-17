//跟subset一样，只是不放入重复的部分进去。
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		set<vector<int>> subs;
		vector<int> sub;

		getsubs(nums, 0, sub, subs);
		res.assign(subs.begin(), subs.end());

		return res;
	}
	void getsubs(vector<int>& nums, int index, vector<int>& sub, set<vector<int>>& res) {
		//if(std::find(res.begin(),res.end(), sub) ==res.end())
		res.insert(sub);
		for (int i = index; i < nums.size(); i++) {
			sub.push_back(nums[i]);
			getsubs(nums, i + 1, sub, res);
			sub.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {//采用set不包括重复的啦。
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> sub;
		getsubs(nums, 0, sub, res);

		return res;
	}
	void getsubs(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>>& res) {
		if (std::find(res.begin(), res.end(), sub) == res.end())
			res.push_back(sub);
		for (int i = index; i < nums.size(); i++) {
			sub.push_back(nums[i]);
			getsubs(nums, i + 1, sub, res);
			sub.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {//1,2,3,3把3，3看成一个整体，有3中状态。null,3,33，其他唯一的数只要两个状态啊
		sort(nums.begin(), nums.end());
		vector<vector<int>> subs = { {} };
		vector<int> sub;
		for (int i = 0; i < nums.size();) {
			int count = 1;
			while (count + i < nums.size() && nums[count + i] == nums[i])
				count++;
			int n = subs.size();
			for (int j = 0; j < n; j++) {
				vector<int> instance = subs[j];
				for (int k = 0; k < count; k++) {
					instance.push_back(nums[i]);
					subs.push_back(instance);
				}
			}
			i += count;

		}
	}
};