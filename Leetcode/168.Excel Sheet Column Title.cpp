class Solution {
public:
	string convertToTitle(int n) {
		string str;
		if (n < 0)
			return "";
		while (n > 0)
		{
			str.insert(str.begin(), (n - 1) % 26 + 'A');
			n = (n - 1) / 26;
		}
		return str;
		//return convertToTitle((n - 1) / 26) + (n - 1) % 26 + 'A';
	}
};