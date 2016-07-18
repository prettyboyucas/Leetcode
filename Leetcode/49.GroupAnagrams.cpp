//采用map，利用string 排序过的 做主键，vector<string>做键值
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		vector<string> item;
		string element;
		if (strs.empty())
			return res;
		map<string, vector<string>> gamap;
		for (int i = 0; i < strs.size(); i++) {
			gamap[sortSring(strs[i])].push_back(strs[i]);
		}
		for (auto& item : gamap) {
			res.push_back(item.second);
		}
		return res;



	}
	string sortSring(string str) {
		sort(str.begin(), str.end());
		return str;
	}
};