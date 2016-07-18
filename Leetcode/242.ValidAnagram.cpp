
class Solution {
public:
	bool isAnagram(string s, string t) {
		int lens = s.size();
		int lent = t.size();
		int map[26] = { 0 };
		if (lens != lent)
			return false;
		for (int i = 0; i < lens; i++) {
			map[s[i] - 'a']++;
		}
		for (int i = 0; i < lens; i++) {
			if (map[t[i] - 'a']--) < 0
				return false;
		}
		return true;
	}
};