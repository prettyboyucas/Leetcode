class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int i = 0, j = 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid.empty())
			return 0;
		//��㡢�յ㱻��ס��
		if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
			return 0;
		vector<vector<int>> matrix(m, vector<int>(n, 0));
		int flag = false;//���ڱ�Ե���У����ĳ���ո񱻶�ס�������ҲҪ��ʼ��Ϊ0��
		for (; i < m; i++) {
			if (flag) {
				matrix[i][0] = 0;
			}
			else {
				if (obstacleGrid[m - 1 - i][n - 1 - 0] != 1)//�ԳƵģ�����Ҫm-1,n-1Ҳ����
					matrix[i][0] = 1;
				else {
					flag = true;
					matrix[i][0] = 0;
				}

			}

		}
		flag = false;
		for (; j < n; j++) {
			if (flag) {
				matrix[0][j] = 0;
			}
			else {
				if (obstacleGrid[m - 1 - 0][n - 1 - j] != 1)//�ԳƵģ�����Ҫm-1,n-1Ҳ����
					matrix[0][j] = 1;
				else {
					flag = true;
					matrix[0][j] = 0;
				}
			}

			//if (obstacleGrid[m - 1-0][n-1-j] != 1)
			//	matrix[0][j] = 1;
		}

		for (i = 1; i < m; i++) {
			for (j = 1; j < n; j++) {
				if (obstacleGrid[m - 1 - i][n - 1 - j] != 1)//�ԳƵģ�����Ҫm-1,n-1Ҳ����
					matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];//�������ס������0��
				else
					matrix[i][j] = 0;
			}
		}



		return matrix[m - 1][n - 1];
	}
};



class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
		vector<int> f(n, 0);
		f[0] = obstacleGrid[0][0] ? 0 : 1;
		for (int i = 0; i < m; i++) {
			f[0] = f[0] == 0 ? 0 : (obstacleGrid[i][0] ? 0 : 1);
			for (int j = 1; j < n; j++)
				f[j] = obstacleGrid[i][j] ? 0 : (f[j] + f[j - 1]);
		}
		return f[n - 1];
	}
};

class Solution {
public:
	int uniquePathsWithObstacles(const vector<vector<int> >& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
		f = vector<vector<int> >(m, vector<int>(n, 0));
		f[0][0] = obstacleGrid[0][0] ? 0 : 1;
		return dfs(obstacleGrid, m - 1, n - 1);
	}
private:
	vector<vector<int>> f;

	int dfs(const vector<vector<int> >& obstacleGrid,
		int x, int y) {
		if (x < 0 || y < 0) return 0;

		if (obstacleGrid[x][y]) return 0;
		if (x == 0 && y == 0) return f[0][0]; // 
		if (f[x][y] > 0) {
			return f[x][y];
		}
		else {
			return f[x][y] = dfs(obstacleGrid, x - 1, y) +
				dfs(obstacleGrid, x, y - 1);
		}
	}
};