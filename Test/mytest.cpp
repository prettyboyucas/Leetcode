#include "stdafx.h"
#include <stdio.h>
#include <ctime>
#include <thread>
#include <process.h>
using namespace std;
/*
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> line;
		vector<int> nextline;
		if (numRows <= 0)
			return res;
		line.push_back(1);
		res.push_back(line);
		if (numRows == 1)
			return res;
		for (int i = 1; i < numRows; ++i) {
			nextline.push_back(1);
			for (auto iter = line.begin(); iter < line.end() - 1; ++iter) {
				nextline.push_back(*iter + *(++iter));
			}
			nextline.push_back(1);
			res.push_back(nextline);
			line = nextline;
			nextline.clear();
		}
	}
};

int main(){
	
	
	map<char, int> mymap;
	map<char, int>::iterator itlow, itup;
	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;
	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');
	cout << itlow->second << endl;
	cout << itup->second << endl;
	mymap.erase(itlow, itup);
	//print content
	for (auto& ele : mymap) {
		cout << ele.first << "=>"<<ele.second << "\n";
	}
	getchar();


	return 0;
}