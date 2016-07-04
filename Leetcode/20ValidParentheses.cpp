#include <iostream>
#include <string>
#include <stack>
#include <map>

using std::map;
using std::stack;
using std::string;

//����map�����ö�ջ���бȽϡ�
class Solution {
public:
	bool isValid(string s) {
		map<char, char>  parentheses = {
			{'(', ')'},
			{'{', '}'},
			{'[', ']'}
		};

		stack<char> cstack;
		for (auto& ch : s) {
			if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') {
				if (!cstack.empty() && parentheses[cstack.top()] == ch) {
					cstack.pop();
				}
				else {
					cstack.push(ch);
				}
			}
			
		}


		if (cstack.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//�ⷨ����Ϊpatentheses����string����������
class Solution3 {
public:
	bool isValid(string s) {
		map<char, char>  parentheses = {
			{ '(', ')' },
			{ '{', '}' },
			{ '[', ']' }
		};
		std::string toFind("(){}[]");
		stack<char> cstack;
		std::string::size_type pos = 0;
		for (auto& ch : s) {
			if (pos = toFind.find(ch) != std::string::npos) {
				if (!cstack.empty() && parentheses[cstack.top()] == ch) {
					cstack.pop();
				}
				else {
					cstack.push(ch);
				}
			}

		}


		if (cstack.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//ֱ������find.���÷�Χforѭ�������������ͳ�ʱ��
class Solution4 {
public:
	bool isValid(string s) {
		map<char, char>  parentheses = {
			{ '(', ')' },
			{ '{', '}' },
			{ '[', ']' }
		};
		std::string toFind("(){}[]");
		stack<char> cstack;
		std::string::size_type pos = 0;
		while ((pos = s.find_first_of(toFind, pos)) != std::string::npos) {
				if (!cstack.empty() && parentheses[cstack.top()] == s[pos]) {
					cstack.pop();
				}
				else {
					cstack.push(s[pos]);
				}

		}


		if (cstack.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};