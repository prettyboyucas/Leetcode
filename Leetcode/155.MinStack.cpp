class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stackdata.push(x);
		if (stackmin.size() == 0 || x < stackmin.top())
			stackmin.push(x);
		else
			stackmin.push(stackmin.top());
	}

	void pop() {
		stackdata.pop();
		stackmin.pop();

	}

	int top() {
		return stackdata.top();
	}

	int getMin() {
		return stackmin.top();
	}
private:
	stack<int> stackdata;
	stack<int> stackmin;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

//使用智能指针 use smart pointer
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		//stackdata = new stack<int>();
		//stackmin = new stack<int>();
		stackdata = make_shared<stack<int>>();
		stackmin = make_shared<stack<int>>();
	}

	void push(int x) {
		stackdata->push(x);
		if (stackmin->size() == 0 || x < stackmin->top())
			stackmin->push(x);
		else
			stackmin->push(stackmin->top());
	}

	void pop() {
		stackdata->pop();
		stackmin->pop();

	}

	int top() {
		return stackdata->top();
	}

	int getMin() {
		return stackmin->top();
	}
private:
	shared_ptr<stack<int>> stackdata;
	shared_ptr<stack<int>> stackmin;
	//stack<int>* stackdata;
	//stack<int>* stackmin;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

