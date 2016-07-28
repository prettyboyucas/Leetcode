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
������������������е��ʵ��Ӵ�������˵����һ�����ַ�����
�ٸ�������������ͬ�ĵ��ʣ��������ҳ������������е��ʵ��Ӵ�����ʼλ�ã�
���������Ѷȵ�һ���⡣�����������Ҫ�õ�������ϣ��
����һ����ϣ���Ȱ����еĵ��ʴ��ȥ��Ȼ��ӿ�ͷ��ʼһ����������
ֹͣ����Ϊ��ʣ���ַ�����С�ڵ��ʼ��������ַ��ĳ��ȡ�
��ʱ��������Ҫ����ڶ�����ϣ��Ȼ��ÿ���ҳ��������ʳ��ȵ��Ӵ���
�����Ƿ��ڵ�һ����ϣ������û�У���break������У������ڶ�����ϣ��
����ͬ�Ĵ�ֻ�ܳ���һ�Σ�
������ˣ�Ҳbreak���������ƥ����������ʼ������еĵ��ʣ�
���i�������У�����μ��������£�

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