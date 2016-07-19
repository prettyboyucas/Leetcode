class Solution {
public:
	string getHint(string secret, string guess) {
		int bull = 0;
		int cow = 0;
		map<char, int> m1;
		map<char, int> m2;
		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i])
				bull++;
			else {
				m1[secret[i] - '0']++;
				m2[guess[i] - '0']++;
			}

		}
		for (int i = 0; i < 10; i++) {
			if (m1[i] >= 1 && m2[i] >= 1)
				cow += min(m1[i], m2[i]);
		}
		string res;
		res = res + to_string(bull) + "A" + to_string(cow) + "B";
	}
};
class Solution {//加一减一方法
public:
	string getHint(string secret, string guess) {
		int m[256] = { 0 }, bulls = 0, cows = 0;
		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) ++bulls;
			else {
				if (m[secret[i]]++ < 0) ++cows;
				if (m[guess[i]]-- > 0) ++cows;
			}
		}
		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};
//改进的方法。
class Solution {
public:
	string getHint(string secret, string guess) {
		int m[256] = { 0 }, a = 0, b = 0, i = 0;
		for (char s : secret) {
			char g = guess[i++];
			a += s == g;
			b += (m[s]++ < 0) + (m[g]-- > 0);
		}
		return to_string(a) + "A" + to_string(b - a) + "B";
	}
};