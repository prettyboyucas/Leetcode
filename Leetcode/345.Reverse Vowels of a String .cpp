class Solution {//超过内存限制
public:
	string reverseVowels(string s) {
		vector<int> index;
		string vowel("aeiouAEIOU");
		string::size_type pos = 0;
		while ((pos = s.find_first_of(vowel, pos)) != string::npos) {
			index.push_back(pos);
		}

		int length = index.size();
		for (int i = 0, j = length - 1; i < j; i++, j--) {
			swap(s[index[i]], s[index[j]]);
		}
		return s;

	}
};


class Solution {
public:
	string reverseVowels(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			left = s.find_first_of("aeiouAEIOU", left);
			right = s.find_last_of("aeiouAEIOU", right);
			if (left < right) {
				swap(s[left++], s[right--]);
			}
		}
		return s;
	}
};
class Solution {//在元音中查找S，两边逼近，这也可以的。
public:
	string reverseVowels(string s) {
		string vowels = "aeiouAEIOU";

		int i = 0, j = s.length() - 1;

		while (i < j) {
			while (i < j && vowels.find(s[i]) == -1) {
				i++;
			}

			while (i < j && vowels.find(s[j]) == -1) {
				j--;
			}

			char ch = s[i];
			s[i] = s[j];
			s[j] = ch;

			i++;
			j--;
		}

		return s;
	}
};