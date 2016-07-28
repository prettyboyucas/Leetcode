class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		int n = s.size(), cnt = words.size();
		if (n <= 0 || cnt <= 0)
			return ans;

		//init word accurence
		unordered_map<string, int> dict;
		for (int i = 0; i < cnt; i++)
			dict[words[i]]++;

		//travel all sub string combinations
		int wl = words[0].size();
		for (int i = 0; i < wl; ++i) {
			int left = i, count = 0;
			unordered_map<string, int> tdict;
			for (int j = i; j <= n - wl; j += wl) {
				string str = s.substr(j, wl);
				//a valid word, accumulate results
				if (dict.count(str)) {
					tdict[str]++;
					if (tdict[str] <= dict[str])
						count++;
					else {
						//a more word, advance the window left side possiablly
						while (tdict[str] > ditc[str]) {
							string str1 = s.substr(left, wl);
							tdict[str1]--;
							if (tdict[str1] < dict[str1])
								count--;
							left += wl;
						}
					}
					//come to a rusult
					if (count == cnt) {
						ans.push_back(left);
						//advance one word
						tdict[s.substr(left, wl)]--;
						count--;
						left += wl;
					}
				}
				//not a valid word, reset all vars;
				else {
					tdict.clear();
					count = 0;
					left = j + wl;
				}
			}

		}

		return ans;
	}
};
/*
这道题让我们求串联所有单词的子串，就是说给定一个长字符串，
再给定几个长度相同的单词，让我们找出串联给定所有单词的子串的起始位置，
还是蛮有难度的一道题。这道题我们需要用到两个哈希表
，第一个哈希表先把所有的单词存进去，然后从开头开始一个个遍历，
停止条件为当剩余字符个数小于单词集里所有字符的长度。
这时候我们需要定义第二个哈希表，然后每次找出给定单词长度的子串，
看其是否在第一个哈希表里，如果没有，则break，如果有，则加入第二个哈希表，
但相同的词只能出现一次，
如果多了，也break。如果正好匹配完给定单词集里所有的单词，
则把i存入结果中，具体参见代码如下：

*/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty()) return res;
		int n = words.size(), m = words[0].size();
		unordered_map<string, int> m1;
		for (auto &a : words) ++m1[a];
		for (int i = 0; i <= (int)s.size() - n * m; ++i) {
			unordered_map<string, int> m2;
			int j = 0;
			for (j = 0; j < n; ++j) {
				string t = s.substr(i + j * m, m);
				if (m1.find(t) == m1.end()) break;
				++m2[t];
				if (m2[t] > m1[t]) break;
			}
			if (j == n) res.push_back(i);
		}
		return res;
	}
};