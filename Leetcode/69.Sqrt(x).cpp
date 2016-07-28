
class Solution {
public:
	int mySqrt(int x) {
		int start = 1;
		int end = x;
		if (x == 0)
			return 0;
		if (x == 1)
			return 1;
		while (start < end) {
			int mid = start + (end - start) / 2;
			long sum = (long)mid*mid;
			if (sum == x)
				return mid;

			else if (sum < (long)x)
				start = mid + 1;
			else
				end = mid;
		}
		return end - 1;
	}
};
//newton·½·¨
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		doubleg = 1.0, ng;// rand() % x;
		while (true) {
			ng = (g + x / g) / 2;
			if ((g - ng)> 0.01)
				g = ng;
			else
				break;
		}
		return int(g);
	}
};