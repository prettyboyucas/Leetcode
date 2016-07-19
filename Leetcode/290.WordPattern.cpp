
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> m;
		istringstream in(str);
		int i = 0;
		for (string word; in >> word; i++) {
			if (m.find(pattern[i]) != m.end()) {
				if (m[pattern[i]] != word)
					return false;
			}
			else {
				//for (auto&item : m)
				//	if (item.second == word)
				//	return false;
				for (map<char, string>::iterator it = m.begin(); it != m.end(); it++) {
					if (it->second == word)
						return false;
				}
				m[pattern[i]] = word;
			}
		}
		return i == pattern.size();

	}
};
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> m1;
		map<string, char> m2;
		istringstream in(str);
		int i = 0;
		for (string word; in >> word; i++) {
			if (m1.find(pattern[i]) != m1.end()) {
				if (m1[pattern[i]] != word)
					return false;
			}
			else {
				m1[pattern[i]] = word;
			}
			if (m2.find(word) != m2.end()) {
				if (m2[word] != pattern[i])
					return false;
			}
			else {
				m2[word] = pattern[i];
			}
		}
		return i == pattern.size();

	}
};
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, int> m1;
		unordered_map<string, int> m2;
		istringstream in(str);
		int i = 0;
		for (string word; in >> word; ++i) {
			if (m1.find(pattern[i]) != m1.end() || m2.find(word) != m2.end()) {
				if (m1[pattern[i]] != m2[word]) return false;
			}
			else {
				m1[pattern[i]] = m2[word] = i + 1;
			}
		}
		return i == pattern.size();
	}
};