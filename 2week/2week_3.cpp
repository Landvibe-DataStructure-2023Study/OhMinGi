#include <iostream>

using namespace std;

class Node {
private:
	int value;
	Node* next;

public:

	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size = 0;

public:
	LinkedList() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		size = 0;
	}
	bool empty() {
		return size == 0;
	}

	void Pirnt() {
		if (empty()) {
			cout << "empty\n";
			return;
		}

		Node* node = head->next;

		while (node != tail) {
			cout << node->value << " ";
			node = node->next;
		}

		cout << endl;
	}

	void AddBack(int x) {
		Node* node = new Node;
		node->value = x;
		
		Node* inode = head->next;

		if (empty()) {
			head->next = node;
			node->next = tail;
		}

		else {
			Node* prevnode = inode;
			while (inode != tail) {
				prevnode = inode;
				inode = inode->next;
			}

			prevnode->next = node;
			node->next = tail;
		}

		size++;
	}

	void RemoveBack() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		
		Node* prevnode = head;
		Node* node = head->next;

		while (node->next != tail) {
			prevnode = node;
			node = node->next;
		}

		int tmp = node->value;
		prevnode->next = tail;
		delete node;
		cout << tmp << "\n";
		size--;

	}

	void Update(int index, int x) {
		if (index >= size) {
			cout << "error\n";
			return;
		}

		Node* node = head->next;
		for (int i = 0; i < index; i++) {
			node = node->next;
		}

		node->value = x;
	}

	void Max() {

		if (empty()) {
			cout << "empty\n";
			return;
		}

		Node* node = head->next;
		int big = node->value;
		int n = 0;
		int c = 0;

		while (node != tail) {
			if (node->value > big) {
				big = node->value;
				n = c;
			}
			node = node->next;
			c++;
		}

		cout << n <<" " << big << "\n";
	}
};

int main() {
	int n;
	string str;
	LinkedList linkedlist;

	cin >> n;
	while (n--) {
		cin >> str;

		if (str == "Print") {
			linkedlist.Pirnt();
		}

		else if (str == "AddBack") {
			int x;
			cin >> x;
			linkedlist.AddBack(x);
		}

		else if (str == "RemoveBack") {
			linkedlist.RemoveBack();
		}

		else if (str == "Update") {
			int index, x;
			cin >> index >> x;
			linkedlist.Update(index, x);
		}

		else if (str == "Max") {
			linkedlist.Max();
		}
	}
}

