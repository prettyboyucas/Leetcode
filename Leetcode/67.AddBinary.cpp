class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty())
			return b;
		if (b.empty())
			return a;
		string res;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int lena = a.size();
		int lenb = b.size();
		int maxlen = lena < lenb ? lenb : lena;
		int carry = 0;
		for (int i = 0; i < maxlen; ++i) {
			int ai = i < a.size() ? a[i] - '0' : 0;
			int bi = i < b.size() ? b[i] - '0' : 0;
			int val = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;
			res.insert(res.begin(), val + '0');
		}
		if (carry == 1)
			res.insert(res.begin(), '1');
		return res;


	}
};