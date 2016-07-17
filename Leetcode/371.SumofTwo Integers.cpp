class Solution {
public:
	int getSum(int a, int b) {
		int sum = 0;
		int carry = 0;
		while (b != 0) {
			sum = a^b;
			carry = (a&b) << 1;
			a = sum;
			b = carry;
		}
		return sum;

	}
};

class Solution1 {
public:
	int getSum(int a, int b) {
		if (b == 0)
			return a;
		int sum = a^b;
		int carry = (a&b) << 1;
		return getSum(sum, carry);

	}
};
//精简到一行；
return b == 0 ? a : getSum(a^b, (a&b) << 1);