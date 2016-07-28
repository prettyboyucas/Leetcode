class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto& c : t)
			map[c] ++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size()) {
			if (map[s[end++]]-->0)
				counter--;

			while (counter == 0) {
				if (end - begin < d)
					d = end - (head = begin);
				if (map[s[begin++]] ++ == 0)
					counter++;
			}

		}
		return  d == INT_MAX ? "" : s.substr(head, d);
	}

};

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> m;
		for (auto&c : t)
			m[c]++;
		size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
		size_t size = s.size();
		//move end to find a valid window
		while (end < size) {
			//If char in a exites in t ,decrease counter
			if (m[s[end]] >0)
				counter--;
			//Decreasing m[s[end]]. If char does not exits in t,
			//will be negative.
			m[s[end]]--;

			//when we found a valid window, move start to find small window.
			while (counter == 0) {
				if (end - start < minLen) {
					minStart = start;
					minLen = end - start;
				}
				m[s[start]]++;
				//when char exits in t, increase counter.
				if (mk[s[start]] > 0)
					count++;
				start++;
			}
		}
		if (minLen != INT_MAX)
			return s.substr(minStart, minLen);
		return "";

	}

};

int lengthOfLongestSubstringTwoDistinct(string s) {
	vector<int> map(128, 0);
	int counter = 0, begin = 0, end = 0, d = 0;
	while (end<s.size()) {
		if (map[s[end++]]++ == 0) counter++;
		while (counter>2) if (map[s[begin++]]-- == 1) counter--;
		d = max(d, end - begin);
	}
	return d;
}
The code of solving Longest Substring Without Repeating Characters is below :

Update 01.04.2016, thanks @weiyi3 for advise.

int lengthOfLongestSubstring(string s) {
	vector<int> map(128, 0);
	int counter = 0, begin = 0, end = 0, d = 0;
	while (end<s.size()) {
		if (map[s[end++]]++>0) counter++;
		while (counter>0) if (map[s[begin++]]-->1) counter--;
		d = max(d, end - begin); //while valid, update d
	}
	return d;
}
I think this post deserves some upvotes!: )