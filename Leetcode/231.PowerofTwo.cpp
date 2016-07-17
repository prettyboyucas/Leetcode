class Solution {
public:
	bool isPowerOfTwo(int n) {
		// return n>0 && !n&(n-1);
		if (n <= 0)
			return false;
		bitset<32> res(n);
		if (res.count() == 1)
			return true;
		else
			return false;
	}
};
class Solution2 {
public:
	bool isPowerOfTwo(int n) {
		return n>0 && !(n&(n - 1));
	}
};
class Solution {
public:
	bool isPowerOfTwo(int n) {
		int cnt = 0;
		while (n > 0) {
			cnt += (n & 1);
			n >>= 1;
		}
		return cnt == 1;
	}
};