#include <iostream>

using namespace std;

class Node {
private:
	Node* next;
	int value;
public:
	friend class Stack;
};


class Stack {
private:
	int datasize=0;
	Node* Top=nullptr;


public:
	

	void push(int x) {
		Node* node = new Node;
		node->value = x;
		node->next = Top;
		Top = node;
		datasize++;
	}

	int top() {
		if (empty()) return -1;
		return  Top->value;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		Node* node = Top;
		Top = Top->next;
		int tmp = node->value;
		delete node;
		datasize--;
		return tmp;
	}
	bool empty() {
		return datasize == 0;
	}

	int size() {
		return datasize;
	}
};

int main() {
	int n;
	string str;

	cin >>n;

	Stack stack;

	while (n--) {
		cin >> str;

		if (str == "size") {
			cout << stack.size()<<"\n";
		}

		else if (str == "empty") {
			cout << stack.empty() << "\n";
		}

		else if (str == "top") {
			cout << stack.top() << "\n";
		}

		else if (str == "push") {
			int x;
			cin >> x;
			stack.push(x);
		}

		else if (str == "pop") {
			cout << stack.pop() << "\n";
		}
		
	}
}