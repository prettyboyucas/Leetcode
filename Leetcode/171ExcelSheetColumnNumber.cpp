class Solution {
public:
	int titleToNumber(string s) {
		if (s.empty())
			return 0;
		int res;
		for (auto& ch : s) {
			res = 26 * res + ch - 'A' + 1;
		}
		return res;
	}
};