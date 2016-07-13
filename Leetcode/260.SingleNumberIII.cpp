/*class Solution {//使用hashmap
public:
vector<int> singleNumber(vector<int>& nums) {
vector<int> res;
if (nums.empty())
return res;
unordered_map<int, int> dup;
for (int i = 0; i < nums.size(); ++i) {
dup[nums[i]]++;
}

auto iter = dup.cbegin();
while (iter != dup.cend()) {
if (iter->second == 1)
res.push_back( iter->first);
++iter;
}

return res;
}
};
*/
class Solution {//位运算？？
	int findFirstBit1(int num) {
		int index = 0;
		while ((num & 1) == 0) {
			++index;
			num >>= 1;
		}
		return index;
	}
	bool isBit1(int num, int index) {
		num = num >> index;
		return (num & 1);
	}

	vector<int> singleNumber(vector<int>& nums) {
		int result = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

		int indexOfBit1 = findFirstBit1(result);

		int num1 = 0, num2 = 0;
		for (auto& i : nums) {
			if (isBit1(i, indexOfBit1))
				num1 ^= i;
			else
				num2 ^= i;
		}
		vector<int> res;
		res.push_back(num1);
		res.push_back(num2);
		return res;


	}
};
//梗简便的求取第一个置位 diff &=-diff;为什么呢；
class Solution
{
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		// Pass 1 : 
		// Get the XOR of the two numbers we need to find
		int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		// Get its last set bit
		diff &= -diff;

		// Pass 2 :
		vector<int> rets = { 0, 0 }; // this vector stores the two numbers we will return
		for (int num : nums)
		{
			if ((num & diff) == 0) // the bit is not set
			{
				rets[0] ^= num;
			}
			else // the bit is set
			{
				rets[1] ^= num;
			}
		}
		return rets;
	}
};