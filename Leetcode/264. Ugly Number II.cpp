class Solution {
public:
	int nthUglyNumber(int n) {
		if (n < 0)
			return 0;
		int *uglys = new int[n];
		uglys[0] = 1;
		int next = 1;

		int* p2 = uglys;
		int* p3 = uglys;
		int* p5 = uglys;

		while (next < n) {
			uglys[next] = min(min(*p2 * 2, *p3 * 3), *p5 * 5);
			while (*p2 * 2 <= uglys[next])
				p2++;
			while (*p3 * 3 <= uglys[next])
				p3++;
			while (*p5 * 5 <= uglys[next])
				p5++;
			next++;
		}
		int res = uglys[n - 1];
		delete[] uglys;
		return res;

	}
};