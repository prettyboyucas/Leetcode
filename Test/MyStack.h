#include    <iostream>
#include    <iomanip>
using namespace std;


class MyStack
{
public:
	MyStack(int);           // constructor
	MyStack(const MyStack &); // copy constructor
	~MyStack();              // destructor

	void push(int);       // push an int into a MyStack
	int  pop();            // pop an int from a MyStack

	//bool empty() const;    // is the MyStack empty?
	//bool full() const;     // is the MyStack full?

	//int capacity() const;  // capacity of the MyStack
	//int size() const;      // current size of the MyStack

	friend ostream &operator <<(ostream &, const MyStack &);

private:
	int * myStack;             // pointer to local MyStack of ints

	int top;                // top of MyStack (next avail. location)
	int maxsize;            // max size of the MyStack
};