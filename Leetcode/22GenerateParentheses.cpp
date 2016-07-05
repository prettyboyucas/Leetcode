#include <iostream>

#include <string>
#include <vector>

using namespace std;

//Given n pairs of parentheses, write a 
//function to generate all combinations of well-formed parentheses.
class Solution22 {
public:
	vector<string> generateParenthesis(int n) {
		string s;
		vector<string> res;
		int l = 0;
		int r = 0;
		generateCore(s, res, l, r, n);
		
		return res;
	}
private:
	void generateCore(string s, vector<string>& res, int l, int r, int n) {
		if (r == n)
			res.push_back(s);
		else if (l == n) {
			generateCore(s + ')', res, l, r + 1, n);
		}
		else {
			if (l > r) {
				generateCore(s + ')',res, l, r + 1, n);
			}
			generateCore(s + '(',res, l + 1, r, n);
		}
	}
};