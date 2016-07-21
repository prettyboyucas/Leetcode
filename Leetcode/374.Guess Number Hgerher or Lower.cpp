//Âíµ¤£¬Åª·´ÁËÄáÂê
int guess(int num);
class Solution1 {
public:
	int guessNumber(int n) {
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			int res = guess(mid);
			if (res == 1)
				l = mid + 1;
			else if (res == -1)
				r = mid - 1;
			else
				return mid;
			/*
			switch (guess(mid))
			{
			case 1: l = mid+1; break;
			case -1: r = mid-1; break;
			default: return mid;
			}
			*/
		}
		return 0;
		// return *"It doesn't allow me to compile if I don't return something here";
	}
};
class Solution {
public:
	int guessNumber(int n) {
		int start = 1;
		int end = n;
		while (start <= end) {
			int middle = start + (end - start) / 2;
			int result = guess(middle);

			if (result == 0)
				return middle;
			else if (result > 0)
				//end = middle - 1;
				start = middle + 1;
			else
				//start = middle + 1;
				end = middle - 1;

		}
		return 0;
	}
};