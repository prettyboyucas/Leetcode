
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.empty() && t.empty())
			return true;
		unordered_map<char, char> hashs, hasht;
		int lens = s.size(), lent = t.size();
		if (lens != lent)
			return false;
		for (int i = 0; i < lens; i++) {

			if (hashs.find(s[i]) == hashs.end()) {
				hashs[s[i]] = t[i];
			}
			else if (hashs[s[i]] != t[i]) {
				return false;
			}

			if (hasht.find(t[i]) == hasht.end()) {
				hasht[t[i]] = s[i];
			}
			else if (hasht[t[i]] != s[i]) {
				return false;
			}

		}
		return true;
	}
};