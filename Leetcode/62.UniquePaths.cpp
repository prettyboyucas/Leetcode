class Solution {//�ݹ�recursive
public:
	int uniquePaths(int m, int n) {
		//if (m == 1 && n == 1)
		//return 0;
		if (m == 1 || n == 1)
			return 1;
		//int res = 0;
		//	if (n > 1)
		//	res += uniquePaths(m, n - 1);
		//	if (m > 1)
		//	res += uniquePaths(m - 1, n);
		return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
	}
};

//���Ƶķ�����
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0; //�����߽��ֵΪ0
		if (m == 1 && n == 1) return 1; //���ֵΪ1��
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};


class Solution {//ѭ�����cyclic
public:
	int uniquePaths(int m, int n) {
		int i = 0, j = 0;
		vector<vector<int>> matrix(m, vector<int>(n));
		for (; i < m; i++)
			matrix[i][0] = 1;
		for (; j < n; j++)
			matrix[0][j] = 1;
		for (i = 1; i < m; i++)
			for (j = 1; j < n; j++)
				matrix[i][j] == matrix[i - 1][j] + matrix[i][j - 1];
		return matrix[m - 1][n - 1];
	}
};
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> f(n, 0);
		f[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				// ��ߵ��Ǹ��º��
				// �ұߵ���û�и��¹���
				f[j] = f[j] + f[j - 1];
			}
		}
		return f[n - 1];
	}
};