
/*
分析：这一题约束最多只能买卖两次股票，并且手上最多也只能持有一支股票。
因为不能连续买入两次股票，所以买卖两次肯定分布在前后两个不同的区间。
设p(i) = 区间[0,1,2...i]的最大利润 + 区间[i,i+1,....n-1]的最大利润
（式子中两个区间内分别只能有一次买卖，这就是第一道题的问题），那么本题的最大利润
= max{p[0],p[1],p[2],...,p[n-1]}。根据第一题的算法2，我们可以求区间[0,1,2...i]的最大利润；
同理可以从后往前扫描数组求区间[i,i+1,....n-1]的最大利润，其递归式如下：

dp[i-1] = max{dp[i], maxprices - prices[i-1]}  ,maxprices是区间[i,i+1,...,n-1]内的最高价格。
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		vector<int> profit(prices.size());
		int minprices = 0;
		minprices = prices[0];
		profit[0] = 0;
		for (int i = 1; i < prices.size(); ++i) {
			profit[i] = max(profit[i - 1], prices[i] - minprices);
			minprices = min(minprices, prices[i]);
		}

		int maxprices = prices[prices.size() - 1];
		int best = 0;
		for (int i = prices.size() - 2; i >= 0; --i) {
			best = max(best, maxprices - prices[i] + profit[i]);
			maxprices = max(maxprices, prices[i]);
		}
		return best;
	}
};