
/*
��������һ��Լ�����ֻ���������ι�Ʊ�������������Ҳֻ�ܳ���һ֧��Ʊ��
��Ϊ���������������ι�Ʊ�������������ο϶��ֲ���ǰ��������ͬ�����䡣
��p(i) = ����[0,1,2...i]��������� + ����[i,i+1,....n-1]���������
��ʽ�������������ڷֱ�ֻ����һ������������ǵ�һ��������⣩����ô������������
= max{p[0],p[1],p[2],...,p[n-1]}�����ݵ�һ����㷨2�����ǿ���������[0,1,2...i]���������
ͬ����ԴӺ���ǰɨ������������[i,i+1,....n-1]�����������ݹ�ʽ���£�

dp[i-1] = max{dp[i], maxprices - prices[i-1]}  ,maxprices������[i,i+1,...,n-1]�ڵ���߼۸�
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