#include <iostream>

using namespace std;

int c, k;

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

	void remove(int x) {
		Node* dnode = search(x);
		Node* pnode = dnode->parent;
		Node* cnode;

		if (dnode->left == nullptr && dnode->right == nullptr) {
			cnode = nullptr;
		}
		else if (dnode->left == nullptr && dnode->right != nullptr) {
			cnode = dnode->right;
		}
		else if (dnode->left != nullptr && dnode->right == nullptr) {
			cnode = dnode->left;
		}
		else {
			cnode = dnode->right;
			while (cnode->left != nullptr) {
				cnode = cnode->left;
			}
			dnode->data = cnode->data;
			dnode = cnode;
			pnode = dnode->parent;
			cnode = dnode->right;
		}

		if (pnode == nullptr) {
			root = cnode;
			root->parent = nullptr;
		}
		else if (dnode == pnode->left) {
			pnode->left = cnode;
			if (cnode != nullptr) {
				cnode->parent = pnode;
			}
		}
		else {
			pnode->right = cnode;
			if (cnode != nullptr) {
				cnode->parent = pnode;
			}
		}

		delete dnode;
	}

	void Max(Node* node) {
		if (node == nullptr) {
			return;
		}
		Max(node->right);
		c++;
		if (c == k) {
			cout << node->data << "\n";
			return;
		}
		Max(node->left);
	}

	int height(Node* node) {
		if (node == nullptr) {
			return -1;
		}

		return max(height(node->left), height(node->right)) + 1;
	}

	void depth(int x) {
		Node* node = search(x);
		int depth = 0;

		while (node->parent != nullptr) {
			node = node->parent;
			depth++;
		}

		cout << depth << "\n";
	}
};

int main() {
	int n;
	cin >> n;
	BST bst;

	while (n--) {
		string str;
		cin >> str;

		if (str == "insert") {
			int x;
			cin >> x;
			bst.insert(x);
			bst.depth(x);
		}

		else if (str == "delete") {
			int x;
			cin >> x;
			bst.depth(x);
			bst.remove(x);
		}

		else if (str == "max") {
			cin >> k;
			c = 0;
			bst.Max(bst.root);
		}

		else if (str == "height") {
			int x;
			cin >> x;
			cout << bst.height(bst.search(x)) << "\n";
		}
	}
}