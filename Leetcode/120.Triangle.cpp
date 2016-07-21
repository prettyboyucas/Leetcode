

//动态规划，先倒数第二行从左到右，再往上。
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size();
		for (int i = len - 2; i >= 0; i--)
			for (int j = 0; j < i + 1; j++)
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		return triangle[0][0];
	}
};