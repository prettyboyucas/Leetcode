class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> line;
		vector<int> nextline;
		if (numRows <= 0)
			return res;
		line.push_back(1);
		res.push_back(line);
		if (numRows == 1)
			return res;
		for (int i = 1; i < numRows; ++i) {
			nextline.push_back(1);
			for (auto iter = line.begin(); iter < line.end() - 1; ) {//用while循环应该更好吧，下面已经递增了
				nextline.push_back(*iter + *(++iter));
			}
			nextline.push_back(1);
			res.push_back(nextline);
			line = nextline;
			nextline.clear();
		}
		return res;
	}
};