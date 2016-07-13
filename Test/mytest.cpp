#include "stdafx.h"
#include <stdio.h>
#include <ctime>
#include <thread>
#include <process.h>
using namespace std;

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





int main(){
	
	vector<int> vec{ 1,2,3,4,5,5,4,2,1 };
	string s = "1010101010";
	//cout << sizeof(int) << endl;
	int diff = 0b001110100;

	int res = diff&(-diff);
	cout << res << endl;
	getchar();


	return 0;
}