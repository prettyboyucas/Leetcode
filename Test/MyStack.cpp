#include    <iostream>
#include    <iomanip>
using namespace std;

#include    "MyStack.h"

MyStack::MyStack(int n)
{
	maxsize = n;
	top = 0;
	myStack = new int[n];
}

MyStack::MyStack(const MyStack &s)
{
	maxsize = s.maxsize;
	// allocate MyStack for left side object
	myStack = new int[maxsize];
	// now copy right side object to left side object
	for (top = 0; top < maxsize; ++top)
	{
		myStack[top] = s.myStack[top];
	}
}


void MyStack::push(int i)   // push an int into a MyStack
{
	if (!full())
	{
		cout << "push( " << i << " )\t at location "
			<< top << '\n';
		myStack[top] = i;
		++top;              // advance to the next empty location
	}
}

int MyStack::pop()           // pop an int from a MyStack
{
	if (empty())
	{
		return -1;          // MyStack is empty; return -1
	}
	else
	{
		--top;
		cout << "pop( ) " << myStack[top]
			<< " at location " << top << '\n';
		// return item at top of the MyStack
		return myStack[top];
	}
}

ostream &operator <<(ostream &out, const MyStack &s)
{
	for (int i = s.size() - 1; i >= 0; --i)
	{
		out << setw(3) << i << setw(5) << s.myStack[i] << '\n';
	}

	return out;
}