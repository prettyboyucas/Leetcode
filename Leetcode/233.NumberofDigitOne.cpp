

class Solution {//³¬Ê±
public:
	int countDigitOne(int n) {
		if (n <= 0)
			return 0;
		string str = to_string(n);
		return NumberOf1(str);
	}

	int NumberOf1(string str) {
		if (str.empty())
			return 0;
		int first = str[0] - '0';
		int length = str.size();

		if (length == 1 && first == 0)
			return 0;
		if (length == 1 && first >= 1)
			return 1;

		int numFirstDigit = 0;
		if (first > 1)
			numFirstDigit = pow(10, length - 1);
		else if (first == 1)
			numFirstDigit = stoi(str.substr(1)) + 1;

		int numOtherdigits = first * (length - 1)* pow(10, length - 2);
		int numRecursive = NumberOf1(str.substr(1));

		return  numFirstDigit + numOtherdigits + numRecursive;
	}
};
