#include <iostream>

using namespace std;

class Stack {
public:
	int arr[100000]{};
	int datasize = 0;
	int maxSize;

	Stack(int n) {
		maxSize = n;
	}

	int size() {
		return datasize;
	}

	bool empty() {
		return datasize == 0;
	}

	int top() {
		if (empty()) {
			return -1;
			
		}

		return arr[datasize - 1];
	}

	void push(int x) {
		if (datasize >= maxSize) {
			cout<< "FULL" <<"\n";
			return;
		}

		arr[datasize++] = x;
	}

	void pop() {
		if (empty()) {
			cout<< -1 <<"\n";
			return;
		}

		cout << arr[datasize - 1]<<"\n";
		datasize--;

	}

	void full() {
		if (datasize >= maxSize) {
			cout << 1<<"\n";
		}

		else { cout << 0<<"\n"; }
	}
};

int main() {

	int n, t;
	cin >> t >> n;

	Stack stack(t);

	string str;

	while (n--) {
		cin >> str;

		if (str == "size") {
			cout << stack.size() <<"\n";
		}

		else if (str == "empty") {
			cout << stack.empty() <<"\n";
		}

		else if (str=="top") {
			cout << stack.top()<<"\n";
		}

		else if (str=="push") {
			int x;
			cin >> x;
			stack.push(x);
		}

		else if (str=="pop") {
			 stack.pop();
		}

		else if (str == "full") {
			stack.full();
		}
	}
}