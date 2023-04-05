#include <iostream>

using namespace std;

class Node {
public:
	Node* next;
	Node* prev;
	int value;

	friend class Iterator;
	friend class Sequence;
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
private:
	Node* head;
	Node* tail;
	int size = 0;

public:
	Sequence() {
		head = new Node;
		head->value = 0;
		tail = new Node;
		tail->value = 0;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	Node* begin() {
		return head->next;
	}

	Node* end() {
		return tail;
	}

	void insert(Iterator& p, int x) {
		Node* node = new Node;
		node->value = x;

		p.node->prev->next = node;
		node->prev = p.node->prev;

		node->next = p.node;
		p.node->prev = node;

		size++;
	}

	int Size() {
		return size;
	}

};

int main() {
	int n;
	cin >> n;

	while (n--) {
		Sequence seq;
		Iterator p;
		p.node = seq.begin();
		int dnlcl =1;

		int c;
		cin >> c;

		for (int i = 0; i < c; i++) {
			int a;
			cin >> a;
			seq.insert(p, a);
		}

		p.node = seq.begin();

		int count;
		cin >> count;

		for (int i = 0; i < count; i++) {
			int move;
			cin >> move;
			int m = move;

			if (move < 0) {
				m = -move;
			}
			for (int t = 0; t < m; t++) {
				if (move > 0) {
					if (p.node == seq.end()) {
						break;
					}
					else { ++p; dnlcl++; }
				}

				else {
					if (p.node == seq.begin()) {
						break;
					}
					else {
						--p; dnlcl--;
					}
				}
			}

			int va = p.node->value;
			int valu = va;
			if (va < 0) {
				valu = -va;
			}

			for (int k = 0; k < valu; k++) {
				if (va > 0) {
					if (p.node == seq.end()) {
						break;
					}
					else { ++p; dnlcl++; }
				}

				else {
					if (p.node == seq.begin()) {
						break;
					}
					else {
						--p; dnlcl--;
					}
				}
			}
		}

		int s = seq.Size()+1;

		if (s % 2 == 0&&s/2==dnlcl) {
			cout << "middle\n";
		}

		else if (dnlcl > s/2) {
			cout << "trailer" << "\n";
		}
		else if (dnlcl <= s/2) {
			cout << "header" << "\n";
		}

		
	}
}




