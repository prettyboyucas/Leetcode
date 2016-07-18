class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (stack2.size() <= 0) {
			while (stack1.size() > 0) {
				int temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}
		if (stack2.size() == 0)
			throw exception("queue is empty");
		stack2.pop();
	}

	// Get the front element.
	int peek(void) {
		if (stack2.size() <= 0) {
			while (stack1.size() > 0) {
				int temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}
		if (stack2.size() == 0)
			throw exception("queue is empty");
		int head = stack2.top();
		return head;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return stack1.empty() && stack2.empty();
	}
private:

	stack<int> stack1;
	stack<int> stack2;
};
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack<int> tmp;
		while (!s.empty()) {
			tmp.push(s.top());
			s.pop();
		}
		s.push(x);
		while (!tmp.empty()) {
			s.push(tmp.top());
			tmp.pop();
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		s.pop();
	}

	// Get the front element.
	int peek(void) {
		return s.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s.empty();
	}
private:

	stack<int> s;
};