#include "Header.h"

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0) return "";
		string res= "1";
		char ch;
		for (int i = 1; i < n; ++i) {
			 ch = res[0];
			string str;
			int counting = 1;
			for (int j = 1; j < res.size(); ++j) {
				if (res[j] != ch) {
					str.push_back(counting + '0');
					str.push_back(ch);
					ch = res[j];
					counting = 1;
				}
				else {
					counting++;
				}
			}
			str.push_back(counting + '0');
			str.push_back(ch);
			res = str;

		}
		return res;
	}
};