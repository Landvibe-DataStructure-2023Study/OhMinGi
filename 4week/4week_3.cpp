#include <iostream>

using namespace std;

int n;

class Queue {
private:
	int arr[100000];
	int frontIdx = 0;
	int rearIdx = -1;
	int dataSize = 0;

public:

	void update() {
		frontIdx %= n;
		rearIdx %= n;
	}

	bool empty() {
		return dataSize == 0;
	}

	void enqueue(int x) {
		if (dataSize >= n) {
			cout << "Full" << "\n";
		}
		
		else {
			rearIdx++;
			update();
			arr[rearIdx] = x;
			dataSize++;
		}
	}

	void dequeue() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}

		int tmp = arr[frontIdx];
		frontIdx++;
		update();
		dataSize--;
		cout << tmp << "\n";
	}

	void isEmpty() {
		if (empty()) {
			cout << "True\n";
		}

		else {
			cout << "False\n";
		}
	}

	int size() {
		return dataSize;
	}

	void front() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}

		cout << arr[frontIdx] << "\n";
	}

	void rear() {
		if (empty()) {
			cout << "Empty\n";
			return;
		}

		cout << arr[rearIdx] << "\n";
	}

	void full() {
		if (dataSize >= n) {
			cout << "True" << "\n";
		}

		else {
			cout << "False\n";
		}
	}
};

int main() {

	Queue queue;
	string str;
	int t;

	cin >> n >> t;

	while (t--) {
		cin >> str;

		if (str == "enqueue") {
			int x;
			cin >> x;
			queue.enqueue(x);
		}

		else if (str == "dequeue") {
			queue.dequeue();
		}

		else if (str == "isEmpty") {
			queue.isEmpty();
		}

		else if (str == "size") {
			cout << queue.size() << "\n";
		}

		else if (str == "front") {
			queue.front();
		}

		else if (str == "rear") {
			queue.rear();
		}

		else if (str == "full") {
			queue.full();
		}
	}
}
