

// heap

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		priority_queue<pair<int, int>> pq;
		vector<int> res;
		for (auto& item : nums)
			m[item]++;
		for (auto& item : m)
			pq.push(make_pair(item.second, item.first));

		for (int i = 0; i < k; i++) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;


	}
};