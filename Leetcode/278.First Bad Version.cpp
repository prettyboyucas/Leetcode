bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		return recursive(1, n);
	}

	int recursive(int begin, int end) {
		int middle = (begin + end) / 2;
		bool badVersion = isBadVersion(middle);
		if (begin == end)
			return end;
		if (badVersion)
			return recursive(0, middle);
		else
			return recursive(middle + 1, end);
	}
};

//也可以采用循环。
int firstBadVersion(int n) {
	int left = 1, right = n;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (isBadVersion(mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
class Solution {
public:
	int firstBadVersion(int n) {
		for (int i = 1; i <= n; i++) {
			if (isBadVersion)
				return n;
		}
		return -1;
	}


};
