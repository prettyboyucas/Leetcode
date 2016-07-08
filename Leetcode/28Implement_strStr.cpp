#include "Header.h"
//28.Implement strStr()

class Solution {
public:
	int strStr(string haystack, string needle) {
		auto pos = haystack.find(needle);//直接就这样就可以？
		if (string::npos == pos)
			return -1;
		return (int)pos;
	}
};
class Solution {
public:
	int strStr(string haystack, string needle) {
		int lenh = haystack.size(); lenn = needle.size();
		if (lenn == 0) return 0;
		for (int i = 0; i < lenh - lenn; ++i) {
			for (int j = 0; j < lenn; ++j) {
				if(haystack[i + j] != needle[j]) break;
			}
			if (j == lenn)
				return i;
		}
		return -1;
	}
};