class Solution {
public:
	bool canWinNim(int n) {
		if (n % 4 == 0)
			return false;
		return true;
		//return n%4!=0;
		//return n%4;
		return n&3
	}
};