//根据上一个题改编

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		vector<int> line;
		vector<int> nextline;
		if (rowIndex < 0)
			return res;
		line.push_back(1);
		res = line;
		if (rowIndex == 0)
			return res;
		for (int i = 0; i < rowIndex; ++i) {
			nextline.push_back(1);
			for (auto iter = line.begin(); iter < line.end() - 1; ) {//用while循环应该更好吧，下面已经递增了
				nextline.push_back(*iter + *(++iter));//自己递增了
			}
			nextline.push_back(1);
			//res.push_back(nextline);
			res = nextline;
			line = nextline;
			nextline.clear();
		}
		return res;
	}
};

class Solution {
public:
	vector<int> getRow(int rowIndex) {

	}
};











