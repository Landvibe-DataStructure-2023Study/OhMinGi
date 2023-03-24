#include <iostream>

using namespace std;

class Node {
private:

	Node* next;
	int value;

public:

	friend class Queue;
};

class Queue {
private:

	Node* Front;
	Node* Rear;
	int datasize = 0;

public:

	Queue() {
		Front = new Node;
		Rear = new Node;	
		Rear->next = Front;
		datasize = 0;
	}

	bool empty() {
		return datasize == 0;
	}

	void enqueue(int x) {
		Node* node = new Node;
		node->value = x;

		if (empty()) {
			Rear->next = node;
			node->next = Front;
		}

		else {
			node->next = Rear->next;
			Rear->next = node;

		}

		datasize++;
	}

	void dequeue() {
		if (empty()) {
			cout << "Empty" << "\n";
			return;
		}

		Node* node = Rear->next;
		Node* pnode = node;

		while (node->next != Front) {
			pnode = node;
			node = node->next;
		}

		pnode->next = Front;
		int tmp = node->value;
		delete node;
		datasize--;
		cout << tmp << "\n";
	}

	int size() {
		return datasize;
	}


	void front() {
		if (empty()) {
			cout << "Empty" << "\n";
			return;
		}
		
		Node* node = Rear->next;
		Node* pnode = node;

		while (node != Front) {
			pnode = node;
			node = node->next;
		}

		int tmp = pnode->value;
		cout << tmp << "\n";
	}

	void rear() {
		if (empty()) {
			cout << "Empty" << "\n";
			return;
		}

		Node* node = Rear->next;
		int tmp = node->value;

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
};

int main() {
	int n;
	Queue queue;
	string str;

	cin >> n;

	while (n--) {
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
	}
}





