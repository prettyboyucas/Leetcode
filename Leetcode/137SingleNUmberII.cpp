
class Solution {//ģ��������
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

//one����һ�εĶ�����λ
//two�������εĶ�����λ
//��ͬʱ������1������Ҫ���㡣
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;
		for (auto& i : nums) {
			two |= (one&i);
			one ^= i;
			three = ~(one&two);//three = one&two,������3λ������Ȼ����ȡ����
			one &= three;
			two &= three;
		}
		return one;
	}
};