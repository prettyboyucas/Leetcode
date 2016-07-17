class Solution1 {//³¬Ê±
public:
	int trailingZeroes(int n) {
		int ret = 0;
		for (int i = 1; i < n; i++) {
			int j = i;
			while (j % 5 == 0) {
				ret++;
				j /= 10;
			}
		}
		return ret;
	}
};
//ret = N/5 + n/5^2 + n/5^3 +.....
class Solution {
public:
	int trailingZeroes(int n) {
		int ret = 0;
		while (n) {
			ret += n / 5;
			n /= 5;
		}
		return ret;
	}

};