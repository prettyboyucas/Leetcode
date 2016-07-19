class Solution {
public:
	int addDigits(int num) {
		while (num >= 10) {
			int n = num;
			int sum = 0;
			while (n > 0) {
				sum += n % 10;
				n = n / 10;
			}
			num = sum;
		}
		return num;
	}
};
class Solution {
public:
	int addDigits(int num) {
		int sum = 0;
		while (num>0) {
			sum += n % 10;
			n = n / 10;
		}
		if (sum < 10)
			return sum;
		else
			return addDigits(sum);
	}
};
class Solution {
public:
	int addDigits(int num) {
		//return (num - 9 * ((num - 1) / 9));
		return (num - 1) % 9 + 1;
	}
};