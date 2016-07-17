
/*
��һ�����������ɱ�ʾΪ4��������ƽ���ͣ���ʵ�ǿ��Ա�ʾΪ4�����ڵ�ƽ����֮�ͣ���ô����˵���ؽ��ֻ��1,2,3��4���е�һ����
�������ǽ����ֻ���һ�£�����һ���������������4����ô���ǿ��԰�4��ȥ��������Ӱ����������2��8,3��12�ȵȣ�
���صĽ������ͬ�����߿����оٸ�������ӡ�����һ�����Ի���ĵط����ǣ����һ��������8��7�Ļ�����ô�϶�����4����ȫƽ������ɣ�
����Ͳ�֤���ˣ���Ϊ��Ҳ����֤�������߿����о�����֤����ô����������һ���ܴ�����п��ܾͻ��ú�С�ˣ�������������ʱ�䣬
�������Ǿ������ԵĽ����Ϊ����ƽ����֮�ͣ������ɹ�����ô�ͻ᷵��1��2����Ϊ����һ��ƽ��������Ϊ0. (ע�����������n����������
���Բ���������ƽ������Ϊ0�����)��ע�������!!a + !!b������ʽ�����ܺܶ��˲�̫����������˼����ʵ�ܼ򵥣���̾��!��ʾ�߼�ȡ����
��ôһ���������߼�ȡ��Ϊ0����ȡ��Ϊ1��������������̾��!!�����þ��ǿ�a��b�Ƿ�Ϊ����������Ϊ�������Ļ�����2��ֻ��һ�����������Ļ�����1��
�μ��������£�
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
//һ��һ�����Ԫ�أ�����˼
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