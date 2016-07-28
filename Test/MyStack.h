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

	bool empty() const { return true; } // is the MyStack empty?
	bool full() const { return true; }    // is the MyStack full?

	int capacity() const { return 0;}  // capacity of the MyStack
	int size() const { return 0; }      // current size of the MyStack

	friend ostream &operator <<(ostream &, const MyStack &);

private:
	int * myStack;             // pointer to local MyStack of ints

	int top;                // top of MyStack (next avail. location)
	int maxsize;            // max size of the MyStack
};