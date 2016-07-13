class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max, min;

		int length = prices.size();
		if (length <= 1)
			return 0;
		map<int, int> m;
		max = min = prices[0];
		m[max] = m[min] = 0;//hash表存储索引。
		int res;

		for (int i = 1; i < length; i++) {
			if (prices[i] > max) {//涨价了就买
				max = prices[i];
				m[max] = i;
				if (m[max]>m[min] && max - min> res)
					res = max - min;
			}
			else if (prices[i] < min) {
				min = max = prices[i];
				m[min] = m[max] = i;//重置
			}
		}
		return res;

	}
};

//好简单的
class Solution {
public:
	/**
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	int maxProfit(vector<int> &prices) {
		// write your code here
		if (prices.empty()) return 0;
		int i = prices.size() - 1, ans = 0, maxp = prices[i];
		for (--i; i >= 0; --i) {
			ans = max(ans, maxp - prices[i]);
			maxp = max(maxp, prices[i]);
		}
		return ans;
	}
};