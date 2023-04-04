#include <iostream>

using namespace std;

class Node {
private:
	Node* next;
	Node* prev;
	int value;
public:
	friend class Sequence;
	friend class Iterator;
};

class Iterator {
public:
	Node* node = nullptr;

	Iterator* operator++() {
		node = node->next;
		return this;
	}

	Iterator* operator--() {
		node = node->prev;
		return this;
	}
};

class Sequence {
public:
	Node* head;
	Node* tail;
	int size = 0;

	Sequence() {
		head = new Node;
		tail = new Node;
		size = 0;
		head->next = tail;
		tail->prev = head;
	}

	Node* begin() {
		return head->next;
	}

	Node* end() {
		return tail;
	}

	void insert(Iterator &p, int e) {
		Node* node = new Node;
		node->value = e;

		p.node->prev->next = node;
		node->prev = p.node->prev;

		node->next = p.node;
		p.node->prev = node;

		size++;
	}

	void erase(Iterator& p) {
		if (size == 0) {
			cout << "Empty\n";
			return;
		}

		if (p.node == tail) {
			return;
		}
		
		Node* node = p.node;

		node->prev->next = node->next;
		node->next->prev = node->prev;

		delete node;
		p.node = begin();
		size--;
	
	}

	void print() {
		if (size == 0) {
			cout << "Empty\n";
		}

		else {
			Node* node = head->next;

			while (node != tail) {
				cout << node->value << " ";
				node = node->next;
			}

			cout << "\n";
		}
	}

	void find(int e) {		 
			Node* node = head->next;
			int index = 0;

			while (node != tail) {
				if (node->value == e) {
					cout << index << "\n";
					return;
				}
				else {
					node = node->next;
					index++;
				}
			}
			cout << "-1\n";
	}

	void findmultiple(int x) {
		Node* node = head->next;
		int index = 0;
		bool b = false;

		while (node != tail) {
			if (node->value%x==0) {
				cout << index << " ";
				b = true;
			}

			node = node->next;
			index++;
		}
		if (b == false) {
			cout << -1;
		}
		cout << "\n";
	}
};

int main() {
	int m;
	cin >> m;

	Sequence seq;
	Iterator p;
	p.node = seq.begin();

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		if (str == "begin") {
			p.node = seq.begin();
		}

		else if (str == "end") {
			p.node = seq.end();
		}

		else if (str == "insert") {
			int x;
			cin >> x;
			seq.insert(p,x);
		}

		else if (str == "erase") {
			seq.erase(p);
		}

		else if (str == "nextP") {
			if (p.node == seq.end()) {

			}
			else {
				++p;
			}
		}

		else if (str == "prevP") {
			if (p.node == seq.begin()) {

			}
			else {
				--p;
			}
		}

		else if (str == "find") {
			int x;
			cin >> x;
			seq.find(x);
		}

		else if (str == "print") {
			seq.print();
		}

		else if (str == "findmultiple") {
			int x;
			cin >> x;
			seq.findmultiple(x);
		}
	}
}


