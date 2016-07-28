

class Solution {//超时用不了
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		double t = myPow(x, n / 2);
		if (n % 2) return n<0 ? 1 / x*t*t : x*t*t;
		else return t*t;
	}
	double myPow1(double x, int n) {
		if (n < 0) {
			//	n = -n;
			//	x = 1 / x;
			return (1 / x)*myPow(1 / x, -(n + 1));
		}
		//return (1 / x)*myPow(1 / x, -(n + 1));
		if (n == 0)
			return 1;
		if (n == 2)
			return x*x;
		if (n % 2 == 0)
			return myPow(myPow(x, n / 2), 2);
		else
			return x*myPow(myPow(x, n / 2), 2);
	}
};
