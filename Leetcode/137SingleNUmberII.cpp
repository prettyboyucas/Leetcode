
class Solution {//模拟三进制
public:
	int singleNumber(vector<int>& nums) {
		constexpr auto W = sizeof(int) * 8;
		vector<int> vec(W, 0);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < W; ++j) {
				vec[j] += (nums[i] >> j) & 1;
				vec[j] %= 3;
			}
		}
		int res = 0;
		for (int i = 0; i < W; ++i) {
			res += (vec[i] << i);
		}
		return res;
	}
};

//one出现一次的二进制位
//two出现两次的二进制位
//当同时出现了1，则需要清零。
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;
		for (auto& i : nums) {
			two |= (one&i);
			one ^= i;
			three = ~(one&two);//three = one&two,出现了3位个数，然后再取反。
			one &= three;
			two &= three;
		}
		return one;
	}
};