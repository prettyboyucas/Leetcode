// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
/*
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (auto iter = digits.rbegin(); iter != digits.rend(); iter++) {
			*iter += carry;
			carry = *iter / 10;
			if (carry == 0)
				break;
			*iter = *iter % 10;
		}
		if (carry > 0)
			digits.insert(digits.begin(), 1);
		return digits;

	}
};
*/

class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "base::h" << endl; }
};
int main2()
{
	/*
	vector<int> digits{ 1,0 };
	Solution solution;
	vector<int> res;
	res = solution.plusOne(digits);
	for (auto& ele : res)
		cout << ele << " ";
	cout << endl;
	*/
	using Fun = void(*)(void);
	Base b;
	Fun pFun = nullptr;
	int** pVtab = (int**)&b;
	pFun = (Fun)pVtab[0][0];

	cout << "dizhi:" << (int*)(&b) << endl;//取类的地址
	//auto xx = (int*)*(int)*(&b);
	cout << "diyigedizhi" << (int*)*(int*)(&b) << endl;//解引用类地址得到虚函数表第一个元素地址
	      //pFun = (Fun)*((int*)*(int*)(&b));//解引用第一个元素地址得到表里的值是成员函数的地址。
            //pFun();
	//pFun = (Fun)*((int*)*(int*)(&b)+0);
	pFun();
	//pFun = (Fun)*((int*)*(int*)(&b) + 1);
	//pFun();


    return 0;
}

