
//动态规划好难啊，看不懂



class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp = { {} };
		for (int i = 2; i <= n; i++) {
			for (int j = i - 1; j > 0; j--) {
				int global_min = numeric_limits<int >> ::max();
				for (int k = j + 1; k < i; k++) {
					int local_max = max(dp[j][k - 1], dp[k + 1][i]) + k;
					global_min = min(local_max, global_min);
				}
				dp[j][i] = i - j == 1 ? j : global_min;
			}
		}

		return dp[1][n];
	}
};
