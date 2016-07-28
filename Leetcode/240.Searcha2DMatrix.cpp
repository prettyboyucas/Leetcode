class Solution {//treat the matrix as a sorted list
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return 0;
		int rowlen = matrix.size();
		int collssen = matrix[0].size();
		int end = rowlen*collen - 1;
		int start = 0;
		int row = 0;
		int col = 0;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			row = mid / collen;
			col = mid % collen;
			if (matrix[row][col] == target)
				return true;
			if (matrix[row][col]>target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return false;
	}
};
