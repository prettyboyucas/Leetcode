class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max, min;

		int length = prices.size();
		if (length <= 1)
			return 0;
		int res = 0;
		int sum = 0;
		int start = prices[0];

		for (int i = 1; i < length; i++) {
			if (prices[i - 1] > prices[i]) {
				res = prices[i - 1] - start;
				sum += res;
				start = prices[i];
			}
		}
		res = prices[length - 1] - start;
		sum += res;
		return sum;

	}
};