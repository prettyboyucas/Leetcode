class Solution {//""dvdf怎么老是通不过啊
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		unordered_set<char> m;
		int lens = 0;
		int res = 0;
		int left = 0;
		for (auto& ch : s) {
			if (m.find(ch) == m.end()) {
				m.insert(ch);
				res = max(res, (int)m.size());

			}
			else {
				m.erase(m.begin(), next(m.find(ch)));
				m.insert(ch);
			}
		}
		return res;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		
		int maxLen = 0, start = -1;
		for (int i = 0; i < s.size(); i++) {
			if (dict[s[[i]]>start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};