class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int num = envelopes.size();
		if (num < 2)
			return num;
		sort(envelopes.begin(), envelopes.end(),
			[](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.first == b.first) {
				return a.second >b.second;
			}
			else {
				return a.first < b.first;
			}
		
		});
		//find the LIS of the height, as we filtered the width equal cases
		vector<int> result;
		for (const auto& iter : envelopes) {
			const auto target = iter.second;
			auto cur = lower_bound(result.begin(), result.end(), target);
			if (cur == result.end()) {
				result.emplace_back(target);

			}
			else {
				*cur = target;
			}
		}
		return result.size();

	}
};

class Solution {
public:
	static bool cmp_first(const pair<int, int>& i, const pair<int, int>& j) {
		if (i.first == j.first)
			return i.second > j.second;
		return i.first < j.first;
	}
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		vector<int> candidates;
		sort(envelopes.begin(), envelopes.end(), cmp_first);
		vector<int> dp;
		for (int i = 0; i < envelopes.size(); i++) {
			auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
			if (itr == dp.end()) {
				dp.push_back(envelopes[i].second);

			}
			else {
				*itr = envelopes[i].second;
			}
		}
		return dp.size();
	}
};