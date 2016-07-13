
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty())
			return res;
		int beginX = 0, endX = matrix[0].size() - 1;
		int beginY = 0, endY = matrix.size() - 1;
		while (true) {
			//left to right
			for (int j = beginX; j <= endX; ++j)
				res.push_back(matrix[beginY][j]);
			if (++beginY > endY)
				break;
			for (int i = beginY; i <= endY; ++i)
				res.push_back(matrix[i][endX]);
			if (beginX > --endX)
				break;

			for (int j = endX; j >= beginX; --j)
				res.push_back(matrix[endY][j]);
			if (beginY > --endY)
				break;
			for (int i = endY; i >= beginY; --i)
				res.push_back(matrix[i][beginX]);
			if (++beginX > endX)
				break;
		}
		return res;
	}
};
