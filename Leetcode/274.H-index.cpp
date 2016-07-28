class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty())
			return 0;
		sort(citations.begin(), citations.end(), greater<int>());
		int h = 1;
		while (h <= citations.size() && citations[h - 1] >= h) ++h;
		return --h;
	}
};

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty())
			return 0;
		int n = citations.size();
		vector<int> hash(n + 1, 0);
		for (int i = 0; i < n; i++) {
			if (citations[i] >= n)//单独开一个空间存放超出索引的值
				hash[n]++;
			else
				hash[citations[i]]++;
		}
		int paper = 0;
		for (int i = n; i >= 0; --i) {
			paper += hash[i];
			if (paper >= i)
				return i;
		}
	}
};
