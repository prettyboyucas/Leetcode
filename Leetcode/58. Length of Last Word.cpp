class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) return 0;
		auto pos1 = s.find_last_not_of(' ');
		s.erase(pos1 + 1);
		auto pos = s.find_last_of(' ', pos1);
		if (pos != std::string::npos)
			return s.substr(pos + 1).size();
		return s.size();
	}
	int lengthOfLastWord1(string s) {
		if (string.empty())
			return 0;
		int n = string.size() - 1;
		while (n >= 0 && string[n] == ' ') n--;

		int i = 0;
		while (n >= 0 && string[n] != ' ') {
			n--;
			i++;
		}
		return i;

	}
};