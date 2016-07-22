class Solution {
public:
	int minCut(string s) {
		const int n = s.size();
		//constexpr  int SIZE = n + 1;
		//int f[n+1];
		vector<int> f(n + 1, 0);
		//int **a = new bool*[n];
		//for (int i = 0; i < n; i++)
		//	a[i] = new bool[n];

		//bool p[n][n];
		vector<vector<bool>> p(n, vector<bool>(n, 0));
		//	fill_n(&p[0][0], n*n, false);
		//the worst case is cutting by each other
		for (int i = 0; i <= n; i++) {
			f[i] = n - 1 - i;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];
	}
};
