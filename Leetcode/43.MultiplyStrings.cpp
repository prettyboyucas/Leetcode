

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty())
			return string("");
		int len1 = num1.size(), len2 = num2.size();
		int len3 = len1 + len2;
		int i, j, product, carry;

		string res(len3, '0');

		for (i = len1 - 1; i >= 0; --i) {//从结尾开始处理
			carry = 0;
			for (j = len2 - 1; j >= 0; --j) {
				product = carry + (res[i + j + 1] - '0') +
					(num1[i] - '0') *(num2[j] - '0');
				res[i + j + 1] = product % 10 + '0';
				carry = product / 10;
			}
			res[i + j + 1] = carry + '0';


		}
		auto pos = res.find_first_not_of('0');
		if (pos == std::string::npos)
			return string("0");
		return res.substr(pos);
	}
};