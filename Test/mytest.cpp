//#define  _CRT_SECURE_NO_WARNINGS


#include "stdafx.h"
#include <stdio.h>
#include <ctime>
#include <thread>
#include <process.h>
//#include <boost/algorithm/string.hpp>

#include <boost/lexical_cast.hpp>
#include <boost\optional.hpp>
#include <boost/variant.hpp>
#include <boost/thread/thread.hpp>
#include <boost/pending/disjoint_sets.hpp>
//#include <boost\disjoint_sets.hpp>
#include <cstdio>
#include <cstring>




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




constexpr int maxn = 10;
int A[maxn + 1] = { 0,1,2,3,4,5,6,7,8,9,10 };//已经是某些项的和了。
int a[maxn + 1] = {0};
//memset(a, 0, maxn + 1);
//fill_n(a, maxn + 1, 0);

int lowbit(int x)
{
	return x&(-x);
}

void initial(int* A,int len, int* a) {
	for (int i = 1; i <= len; i++) {
		int start = len - lowbit(i) + 1;
		for (int j = start; j <= len; j++) {
			a[i] += A[j];
		}
	}
}



void add(int x, int y, int n) {
	while (x <= n) {
		a[x] += y;
		x += lowbit(x);
	}
}
int sum(int x) {
	int s = 0;
	while (x > 0) {
		s += a[x];
		x -= lowbit(x);
	}
	return s;
}









int main(){
	//fill_n(a, maxn + 1, 0);
	cout << a[0] << " " << a[1] << endl;
	
	getchar();
	return 0;
}