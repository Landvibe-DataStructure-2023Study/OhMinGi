#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int value;
	Node* next;

public:

	Node() {
		this->next=NULL;
		this->value = 0;
	}

	friend class LinkedList;
};

class LinkedList {
private:
	Node* head=NULL;
	Node* tail=NULL;
	int size=0;

public:
	void Print();
	void AddFront(int);
	void RemoveFront();
	void Update(int, int);
	bool empty();
	void Min();
};

bool LinkedList::empty() {
	if (size == 0) {
		return true;
	}

	else {
		return false;
	}

}

void LinkedList::AddFront(int x) {
	Node* node = new Node;
	node->value = x;
	node->next = NULL;

	if (empty()) {
		head = tail = node;
	}

	else {
		node->next = head;
		head = node;
	}

	size++;
}

void LinkedList::Print() {
	if (empty()) {
		cout << "empty" << "\n";
		return;
	}

	Node* node = head;

	
	while (node != NULL) {
		cout << node->value << " ";
		node = node->next;
	}
	

	cout << endl;
}

void LinkedList::RemoveFront() {

	if (empty()) {
		cout << "empty" << "\n";
		return;
	}

	Node* node = head;
	int tmp = node->value;

	if (size==1) {
		head = tail = NULL;
	}

	else {
		head = head->next;
	}

	delete node;
	size--;
	cout << tmp << "\n";
}

void LinkedList::Update(int index,int x) {

	if (index >= size) {
		cout << "error" << "\n";
		return;
	}

	Node* node = head;

	
	for (int i = 0; i < index; i++) {
		node = node->next;
	}

	node->value = x;
	
}

void LinkedList::Min() {
	if (empty()) {
		cout << "empty\n";
		return;
	}

	Node* node = head;
	int min = node->value;
	int a = 0;
	int c = 0;

	while (node != NULL) {
		if (min > node->value) {
			c = a;
			min=node->value;
			node = node->next;
		}
		else {
			node = node->next;
		}

		a++;
	}
	cout << c << " " << min << "\n";
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

		else if (str == "RemoveFront") {
			linkedlist.RemoveFront();
		}

		else if (str == "AddFront") {
			int x;
			cin >> x;
			linkedlist.AddFront(x);
		}

		else if (str == "Update") {
			int index, x;
			cin >> index >> x;
			linkedlist.Update(index, x);
		}

		else if (str == "Min") {
			linkedlist.Min();
		}
	}
}