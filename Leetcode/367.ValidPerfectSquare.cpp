
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 0)
		{
			return false;
		}

		if (num == 1)
		{
			return true;
		}

		int low = 1;
		int high = num;
		while (low <= high)
		{
			int middle = low + (high - low) / 2;
			int reminder = num / middle;
			if (reminder == middle)
			{
				return (num % middle == 0);
			}
			else if (reminder > middle)
			{
				low = middle + 1;
			}
			else
			{
				high = middle - 1;
			}
		}
		return false;
	}
};

class Solution1 {
public:
	bool isPerfectSquare(int num) {
		int start = 1;
		int end = num;
		//if (num > 2000000000)
		//end = 65535 * 2;

		while (start < end) {
			int mid = start + (end - start) / 2;
			//mid = mid > 65535 ? 65535 : mid;
			if ((long)mid*mid < (long)num)
				start = mid + 1;
			else
				end = mid;
		}
		return end*end == num ? true : false;
	}
};