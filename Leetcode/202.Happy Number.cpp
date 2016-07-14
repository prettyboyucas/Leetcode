class Solution {
public:
	bool isHappy(int n) {
		if (n < 0)
			return false;
		m[n]++;

		long newn = 0;
		while (n > 0) {
			newn += (n % 10)*(n % 10);
			n /= 10;
		}
		if (newn == 1)
			return true;
		else if (m[newn] != 0)
			return false;
		else
			return isHappy(newn);

	}
private:
	unordered_map<int, int> m;
};


//����1�������Ͳ���happy number!ת��Ϊstring����ͺܷ��㰡��
class Solution {
public:
	bool isHappy(int n) {
		if (n < 0)
			return false;
		m[n]++;
		string str = to_string(n);

		long newn = 0;
		newn = accumulate(str.begin(), str.end(), 0, [](long x, const char& ch) ->long {return x + (ch - '0')*(ch - '0'); });
		//	while (n > 0) {
		//		newn += (n % 10)*(n % 10);
		//		n /= 10;
		//	}
		if (newn == 1)
			return true;
		else if (m[newn] != 0)
			return false;
		else
			return isHappy(newn);

	}
private:
	//int mypower(char a, char b){return }
	unordered_map<int, int> m;
};