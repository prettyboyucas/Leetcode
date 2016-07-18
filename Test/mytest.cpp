//#define  _CRT_SECURE_NO_WARNINGS


#include "stdafx.h"
#include <stdio.h>
#include <ctime>
#include <thread>
#include <process.h>
//#include <boost/algorithm/string.hpp>

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
	/*
	char* context = nullptr;
	 char* str1 = "1.2*3";
	 const char* sep = ".*";
	char* ptr = strtok_s(str1, sep, &context);
	

	while (ptr != nullptr) {
		cout << *ptr << endl;
		ptr = strtok_s(nullptr, '.', &context);
	}
	*/
	vector<bool> bits;
	bits.push_back(true);
	const bool& j = bits.front();

	int data[] = { 3,2,3,8,8,8,8,8,8,8,5 };
	int data1[] = { 3,2,3 };

		

	//ss.QuickSort(data, 6, 0, 11);
	//cout << ss.MoreThanHalfNum(data1, 3) << endl;;
	//for (int i = 0; i < 11; i++) {
	//	cout << data[i] << " ";
	//}
	
	//cout << a << end;
	vector<int> vec{ 1,2,3,4,5,5,4,2,1 };
	string s = "1010101010";
	//cout << sizeof(int) << endl;
	int diff = 0b001110100;
	//int res = diff&(-diff);
	//cout << res << endl;
	getchar();
	return 0;
}