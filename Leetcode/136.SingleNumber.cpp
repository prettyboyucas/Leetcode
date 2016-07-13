class Solution {//使用hashmap
public:
	int singleNumber(vector<int>& nums) {
		if (nums.empty())
			return 0;
		unordered_map<int, int> dup;
		for (int i = 0; i < nums.size(); ++i) {
			dup[nums[i]]++;
		}

		auto iter = dup.cbegin();
		while (iter != dup.cend()) {
			if (iter->second == 1)
				return iter->first;
			++iter;
		}

		return 0;
	}
};
//异或是是什么鬼
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int x = 0;
		for (const auto& i : nums)
			x ^= i;
		return x;
		//use stl library
		//return accumulate(nums.begin(),nums.end(),0, bit_xor<int>());
	}
};
