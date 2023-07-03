#include <iostream>

using namespace std;

int Count = 0;

class Node {
public:
	int data;
	Node* right;
	Node* left;
	Node* parent;

	Node(int x) {
		right = left = parent = nullptr;
		data = x;
	}
};

class BST {
public:
	Node* root = nullptr;

	void insert(int x) {
		Node* n = new Node(x);

		if (root == nullptr) {
			root = n;
			return;
		}

		Node* node = root;
		Node* parentNode = node->parent;

		while (node != nullptr) {
			if (x > node->data) {
				parentNode = node;
				node = node->right;

			}
			else {
				parentNode = node;
				node = node->left;
			}
		}

		n->parent = parentNode;
		if (parentNode->data > x) {
			parentNode->left = n;
		}
		else {
			parentNode->right = n;
		}
	}

	Node* search(int x) {
		Node* node = root;

		while (node != NULL) {
			if (x == node->data) {
				return node;
			}
			else if (x < node->data) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}

		return nullptr;
	}

	void sub(int x) {
		Node* node = search(x);
		if (node->left == nullptr) {
			return;
		}
		sub1(node->left);
	}

	void sub1(Node* node) {
		if (node == nullptr) {
			return;
		}
		sub1(node->left);
		Count++;
		sub1(node->right);
	}

};

int main() {
	int n, t;
	cin >> n >> t;
	BST bst;

	while (n--) {
		int num;
		cin >> num;
		bst.insert(num);
	}

	while (t--) {
		Count = 0;
		int a, b;
		cin >> a >> b;
		bst.sub(a);
		int tmp = Count;
		Count = 0;
		bst.sub(b);
		cout << tmp + Count << "\n";
	}
}