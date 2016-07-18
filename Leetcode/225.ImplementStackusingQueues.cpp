class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		qAdapter.push(x);
		for (int i = 0; i < qAdapter.size() - 1; i++) {
			qAdapter.push(qAdapter.front);
			qAdapter.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		qAdapter.pop();
	}

	// Get the top element.
	int top() {
		return qAdapter.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return qAdapter.empty();
	}
private:
	queue<int> qAdapter;
}；
//采用两个队列的方式来做。

class Stack1 {
public:
	// Push element x onto stack.
	void push(int x) {
		queue<int> tmp;
		while (!q.empty())
		{
			tmp.push(q.front());
			q.pop();

		}
		q.push(x);
		while (!tmp.empty()) {
			q.push(tmp.front());
			tmp.pop();
		}

	}

	// Removes the element on top of the stack.
	void pop() {
		q.pop();
	}

	// Get the top element.
	int top() {
		return q.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};