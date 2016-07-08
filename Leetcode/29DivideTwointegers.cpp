


class Solution {
public:
	int divide(int dividend, int divisor) {
		if (!divisor)
			return dividend >= 0 ? INT_MAX : INT_MIN;
		if (divideng == INT_MIN && divisor == -1) return INT_MAX;

		unsigned int divd = dividend, divs = divisor;
		if (divisor < 0) divs = -divs;
		if (dividend < 0) divd = -divd;

		int res = 0;
		while (divd >= divs) {
			long long a = divs;
			int i;
			for (i = 1; a <= divd; ++i)
				a <<= 1;
			res += (1 << (i - 2));
			divd -= (divs << (i - 2));
		}
		return (dividend > 0 ^ divisor>0) ? 0 - res : res;
	}
};