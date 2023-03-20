#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	Node* next;
	char value;
public:
	friend class Stack;
};


class Stack {
private:
	int datasize;
	Node* Top;

public:
	Stack()
	{
		datasize = 0;
		Top = nullptr;
	}

	void push(char x) {
		Node* node = new Node;
		node->value = x;
		node->next = Top;
		Top = node;
		datasize++;
	}

	char top() {
		if (empty()) return -1;
		return  Top->value;
	}

	char pop() {
		if (empty()) {
			return -1;
		}
		Node* node = Top;
		Top = Top->next;
		delete node;
		datasize--;
		
	}
	bool empty() {
		return datasize == 0;
	}

	int size() {
		return datasize;
	}
};

int check(char c) {
	if (c == '*' || c == '/') {
		return 3;
	}

	else if (c == '+' || c == '-') {
		return 2;
	}

	else {
		return 1;
	}
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		int count = 0;

		Stack stack;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				cout << str[i];
			}

			else {

				while (!stack.empty() && (check(stack.top()) >= check(str[i]))) {
					cout << stack.top();
					stack.pop();

					if (stack.empty()) {
						count++;
					}

				}

				stack.push(str[i]);

			}
		}

		while (!stack.empty()) {
			cout << stack.top();
			stack.pop();
		}

		count++;
		cout << " " << count<<"\n";
	}
}

