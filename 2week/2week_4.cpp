#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int value;
	Node* next;
	Node* prev;
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
		head->value = 10000;
		tail = new Node;
		tail->value = 10000;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	void Print();
	void Insert(int, int);
	void Remove(int);
	void RemoveAll(int);
	void NeighborMin(int);
};

void LinkedList::Insert(int index, int x) {


	if (index > size) {
		cout << "error" << "\n";
		return;
	}

	Node* node = head->next;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}

	Node* prevnode = node->prev;
	Node* insertnode = new Node;
	insertnode->value = x;
	insertnode->prev = prevnode;
	prevnode->next = insertnode;
	node->prev = insertnode;
	insertnode->next = node;

	size++;
}

void LinkedList::Print() {
	if (head->next == tail) {
		cout << "empty" << "\n";
		return;
	}

	Node* node = head->next;


	while (node != tail) {
		cout << node->value << " ";
		node = node->next;
	}


	cout << endl;
}

void LinkedList::Remove(int index) {

	if (index >= size) {
		cout << "error" << "\n";
		return;
	}

	if (index == 0 && size == 0) {
		cout << "error" << "\n";
		return;
	}

	Node* node = head->next;

	for (int i = 0; i < index; i++) {
		node = node->next;
	}

	Node* prevnode = node->prev;
	Node* nextnode = node->next;
	prevnode->next = nextnode;
	nextnode->prev = prevnode;

	size--;

	cout << node->value << "\n";

	delete  node;
}

void LinkedList::RemoveAll(int x) {
	Node* node = head->next;
	int count{ 0 };

	if (head->next == tail) {
		cout << "not found\n";
		return;
	}

	while (node != tail) {
		if (node->value == x) {
			count++;
			size--;
			Node* prevnode = node->prev;
			Node* nextnode = node->next;
			prevnode->next = nextnode;
			nextnode->prev = prevnode;
		}

		node = node->next;
	}

	if (count > 0) {
		cout << count << endl;
	}
	else {
		cout << "not found\n";
		return;
	}
}

void LinkedList::NeighborMin(int index) {
	if (index >= size) {
		cout << "error" << "\n";
		return;
	}

	Node* node = head->next;

	for (int i = 0; i < index; i++) {
		node = node->next;
	}

	Node* prevnode = node->prev;
	Node* nextnode = node->next;
	int small;

	if (prevnode->value < nextnode->value) {
		small = prevnode->value;
	}
	else {
		small = nextnode->value;
	}

	cout << small << endl;
}

int main() {
	int n;
	string str;
	LinkedList linkedlist;

	cin >> n;

	while (n--) {
		cin >> str;

		if (str == "Print") {
			linkedlist.Print();
		}

		else if (str == "Remove") {
			int index;
			cin >> index;
			linkedlist.Remove(index);
		}

		else if (str == "Insert") {
			int index, x;
			cin >> index >> x;
			linkedlist.Insert(index, x);
		}

		else if (str == "RemoveAll") {
			int x;
			cin >> x;
			linkedlist.RemoveAll(x);
		}

		else if (str == "NeighborMin") {
			int index;
			cin >> index;
			linkedlist.NeighborMin(index);
		}
	}
}