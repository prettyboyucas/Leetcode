//DP
class Solution {
public:
	vector<vector<string>> partition(string s) {
		const int n = s.size();
		//bool p[n][n];
		//fill_n(&p[0][0], n*n, false);
		vector<vector<bool>>  p(n, vector<bool>(n, 0));
		for (int i = n - 1; i >= 0; i--)
			for (int j = i; j < n; j++)
				p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);

		vector<vector<string>> sub_palins[n];// (n, vector<string>(n, ""));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				if (p[i][j]) {
					const string palindrome = s.substr(i, j - i + 1);//回文字符串。
					if (j + 1 < n) {
						for (auto v : sub_palins[j + 1]) {
							v.insert(v.begin(), palindrome);//从头开始添加进单独的string
							sub_palins[i].push_back(v);

						}
					}
					else {
						sub_palins[i].push_back(vector<string> {palindrome});
					}
				}
			}
			return sub_palins[0];
		}

	}
};




class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> path;
		DFS(s, path, result, 0);
		return result;
	}
	void DFS(string& s, vector<string>& path, vector<vector<string>>& result, int start) {
		if (start = s.size()) {
			result.push_back(path);
			return;
		}
		for (int i = start; i < s.size(); i++) {
			if (isPalindrome(s, start, i)) {
				path.push_back(s.substr(start, i - start + 1));
				DFS(s, path, result, i + 1);
				path.pop_back();
			}
		}

	}


	bool isPalindrome(const string& s, int start, int end) {
		while (start < end && s[start] == s[end]) {
			++start;
			--end;
		}
		return start >= end;
	}
};

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> path;  //one partition answer;
		dfs(s, path, result, 0, 1);
		return result;
	}
	//prev pre geban ,start dangqiangeban
	void dfs(string& s, vector<string>& path, vector<vector<string>>& result,
		size_t prev, size_t start) {
		if (start == s.size()) {
			if (isPalindrome(s, prev, start - 1)) {
				path.push_back(s.substr(prev, start - prev));
				result.push_back(path);
				path.pop_back();
			}
			return;
		}
		//bu duan kai;
		dfs(s, path, result, prev, start + 1);
		if (isPalindrome(s, prev, start - 1)) {
			//duankai
			path.push_back(s.substr(prev, start - prev));
			dfs(s, path, result, start, start + 1);
			path.pop_back();
		}
	}


	bool isPalindrome(const string& s, int start, int end) {
		while (start < end && s[start] == s[end]) {
			++start;
			--end;
		}
		return start >= end;
	}
};