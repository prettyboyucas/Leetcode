
class Solution {//右上角开始
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return 0;
		int rowlen = matrix.size();
		int collen = matrix[0].size();
		int col = collen - 1;
		int row = 0;
		while (col >= 0 && row < rowlen) {
			if (target == matrix[row][col])
				return true;
			else if (target < matrix[row][col]) {
				col--;
			}
			else if (target > matrix[row][col]) {
				row++;
			}
		}
		return false;
	}
};




class Solution {//二分
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return 0;
		int rowlen = matrix.size();
		int collen = matrix[0].size();
		return find(0, 0, rowlen - 1, collen - 1, matrix, target);
	}
	bool find(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix, int target) {
		int midx = x1 + (x2 - x1) / 2;
		int midy = y1 + (y2 - y1) / 2;
		if (matrix[midx][midy] == target) {
			return true;
		}
		else if (matrix[midx][midy] < target) {
			return find(x1, midy + 1, midx, y2, matrix, target) ||
				find(midx + 1, y1, x2, midy, matrix, target) ||
				find(midx + 1, midy + 1, x2, y2, matrix, target);
		}
		else {
			return find(x1, y1, midx - 1, midy - 1, matrix, target)
				|| find(midx, y1, x2, midy - 1, matrix, target) ||
				find(x1, midy, midx - 1, y2, matrix, target);
		}
		return false;
	}
};
//solution3
//对行进行二分
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	return searchMatrix(matrix, target, 0, matrix.size() - 1);
}

bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
	if (top > bottom)
		return false;

	int mid = top + (bottom - top) / 2;
	if (matrix[mid].front() <= target && target <= matrix[mid].back())
		if (searchVector(matrix[mid], target)) return true;
	//if (find(matrix[mid].begin(), matrix[mid].end(), target) != matrix[mid].end())
	//return true;

	if (searchMatrix(matrix, target, top, mid - 1)) return true;
	if (searchMatrix(matrix, target, mid + 1, bottom)) return true;

	return false;
}

bool searchVector(vector<int>& v, int target) {
	int left = 0, right = v.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == target)
			return true;
		if (v[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return false;
}
