class Solution {
public:
	int climbStairs(int n) {
		if (n < 0) return 0;
		int result[3] = { 0,1,2 };
		if (n <= 2)
			return result[n];
		long long climbOne = 1;
		long long climbTwo = 2;
		long long climbN = 0;
		for (int i = 3; i <= n; ++i) {
			climbN = climbOne + climbTwo;
			climbOne = climbTwo;
			climbTwo = climbN;
		}
		return climbN;

	}
};