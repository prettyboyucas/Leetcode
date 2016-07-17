class Solution1 {
public:
	int countPrimes(int n) {
		if (n <= 1)
			return 0;
		int count = 0;


		for (int i = 2; i < n; i++) {
			if (i > 10 && (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0))
				continue;
			if (isPrime(i))
				count++;
		}
		return count;
	}
private:
	bool isPrime(int n) {
		if (n <= 1)
			return false;
		int k = (int)sqrt((double)n);
		for (int i = 2; i <= k; i++) {
			if (n%i == 0)
				return false;
		}
		return true;

	}
};
class Solution {
public:
	int countPrimes(int n) {
		bool *tag = new bool[n];
		int *prime = new int[n];
		int cnt = 0;
		memset(tag, true, sizeof(bool) * n);
		for (int i = 2; i < n; ++i) {
			if (tag[i]) prime[cnt++] = i;
			for (int j = 0; j < cnt && i * prime[j] < n; ++j) {
				tag[i * prime[j]] = false;
				if (i % prime[j] == 0) break;
			}
		}
		delete[] tag;
		delete[] prime;
		return cnt;
	}
};

//第三种方法：

class Solution {
public:
	int countPrimes(int n) {
		bool *p = new bool[n];
		memset(p, true, sizeof(bool) * n);
		for (int i = 2; i * i < n; ++i) {
			if (p[i]) for (int j = 2; i * j < n; ++j) {
				p[i * j] = false;
			}
		}
		int cnt = 0;
		for (int i = 2; i < n; ++i) if (p[i]) ++cnt;
		delete[] p;
		return cnt;
	}
};
