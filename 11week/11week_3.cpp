#include <iostream>

using namespace std;

int c;

class Node {
public:
	int data;
	Node* right;
	Node* left;
	Node* parent;

	Node(int x) {
		data = x;
		left = right = parent = nullptr;
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
		Node* pnode = node->parent;

		while (node != nullptr) {
			if (node->data < x) {
				pnode = node;
				node = node->right;
			}
			else {
				pnode = node;
				node = node->left;
			}
		}

		n->parent = pnode;

		if (pnode->data < x) {
			pnode->right = n;
		}
		else {
			pnode->left = n;
		}
	}

	Node* search(int x) {
		Node* node = root;

		while (node != nullptr) {
			if (node->data == x) {
				return node;
			}

			else if (node->data < x) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}

		return nullptr;
	}

	void sub(int x) {
		Node* node = search(x);
		if (node->right == nullptr) {
			return;
		}

		sub1(node->right);
	}

	void sub1(Node* node) {
		if (node == nullptr) { return; }
		sub1(node->left);
		c++;
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
		int a, b;
		cin >> a >> b;
		c = 0;
		bst.sub(a);
		int tmp = c;
		c = 0;
		bst.sub(b);
		if ((tmp - c) < 0) {
			cout << -(tmp - c) << "\n";
		}
		else {
			cout << tmp - c << "\n";
		}
	}
}