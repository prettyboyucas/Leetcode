// Test.cpp : �������̨Ӧ�ó������ڵ㡣
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

	cout << "dizhi:" << (int*)(&b) << endl;//ȡ��ĵ�ַ
	//auto xx = (int*)*(int)*(&b);
	cout << "diyigedizhi" << (int*)*(int*)(&b) << endl;//���������ַ�õ��麯�����һ��Ԫ�ص�ַ
	      //pFun = (Fun)*((int*)*(int*)(&b));//�����õ�һ��Ԫ�ص�ַ�õ������ֵ�ǳ�Ա�����ĵ�ַ��
            //pFun();
	//pFun = (Fun)*((int*)*(int*)(&b)+0);
	pFun();
	//pFun = (Fun)*((int*)*(int*)(&b) + 1);
	//pFun();


    return 0;
}

