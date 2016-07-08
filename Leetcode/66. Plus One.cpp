class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (auto iter = digits.rbegin(); iter != digits.rend(); iter++) {
			*iter += carry;
			carry = *iter / 10;
			if (carry == 0)
				break;
			*iter = *iter % 10;
		}
		if (carry > 0)
			digits.insert(digits.begin(), 1);
		return digits;

	}
};