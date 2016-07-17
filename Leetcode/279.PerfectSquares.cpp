
/*
意一个正整数均可表示为4个整数的平方和，其实是可以表示为4个以内的平方数之和，那么就是说返回结果只有1,2,3或4其中的一个，
首先我们将数字化简一下，由于一个数如果含有因子4，那么我们可以把4都去掉，并不影响结果，比如2和8,3和12等等，
返回的结果都相同，读者可自行举更多的栗子。还有一个可以化简的地方就是，如果一个数除以8余7的话，那么肯定是由4个完全平方数组成，
这里就不证明了，因为我也不会证明，读者可自行举例验证。那么做完两步后，一个很大的数有可能就会变得很小了，大大减少了运算时间，
下面我们就来尝试的将其拆为两个平方数之和，如果拆成功了那么就会返回1或2，因为其中一个平方数可能为0. (注：由于输入的n是正整数，
所以不存在两个平方数均为0的情况)。注意下面的!!a + !!b这个表达式，可能很多人不太理解这个的意思，其实很简单，感叹号!表示逻辑取反，
那么一个正整数逻辑取反为0，再取反为1，所以用两个感叹号!!的作用就是看a和b是否为正整数，都为正整数的话返回2，只有一个是正整数的话返回1，
参见代码如下：
*/

class Solution {
public:
	int numSquares(int n) {
		while (n % 4 == 0) n /= 4;
		if (n % 8 == 7) return 4;
		for (int a = 0; a * a <= n; ++a) {
			int b = sqrt(n - a * a);
			if (a * a + b * b == n) {
				return !!a + !!b;
			}
		}
		return 3;
	}
};
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, 5);
		dp[0] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 1; i + j*j <= n; ++j) {
				dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
			}
			for (auto& item : dp)
				cout << item << " ";
			cout << endl;
		}
		return dp.back();
	}
};
//一个一个添加元素，有意思
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(1, 0);
		while (dp.size() <= n) {
			int m = dp.size(), val = INT_MAX;
			for (int i = 1; i * i <= m; ++i) {
				val = min(val, dp[m - i * i] + 1);
			}
			dp.push_back(val);
		}
		return dp.back();
	}
};
// Recrusion
class Solution {
public:
	int numSquares(int n) {
		int res = n, num = 2;
		while (num * num <= n) {
			int a = n / (num * num), b = n % (num * num);
			res = min(res, a + numSquares(b));
			++num;
		}
		return res;
	}
};