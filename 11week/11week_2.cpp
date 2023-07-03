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
		right = left = parent = nullptr;
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
		if (pnode->data > x) {
			pnode->left = n;
		}
		else {
			pnode->right = n;
		}
	}

	Node* search(int x) {
		Node* n = root;

		while (n != nullptr) {
			if (n->data == x) {
				return n;
			}
			else if (n->data < x) {
				n = n->right;
			}
			else {
				n = n->left;
			}
		}

		return nullptr;
	}

	void remove(int x) {
		Node* delNode = search(x);
		if (delNode == nullptr) { return; }

		Node* pnode = delNode->parent;
		Node* childNode;

		if (delNode->left == nullptr && delNode->right == nullptr) {
			childNode = nullptr;
		}
		else if (delNode->left == nullptr && delNode->right != nullptr) {
			childNode = delNode->right;
		}
		else if (delNode->left != nullptr && delNode->right == nullptr) {
			childNode = delNode->left;
		}
		else {
			childNode = delNode->right;
			while (childNode->left != nullptr) {
				childNode = childNode->left;
			}

			delNode->data = childNode->data;
			delNode = childNode;
			pnode = delNode->parent;
			childNode = delNode->right;
		}

		if (pnode == nullptr) {
			root = childNode;
			root->parent = nullptr;
		}

		else if (delNode == pnode->left) {
			pnode->left = childNode;
			if (childNode != nullptr) {
				childNode->parent = pnode;
			}
		}

		else {
			pnode->right = childNode;
			if (childNode != nullptr) {
				childNode->parent = pnode;
			}
		}

		delete delNode;
	}

	void min(Node* node) {
		if (node == nullptr) { return; }

		min(node->left);
		c++;
		if (k == c) {
			cout << node->data << "\n";
			return;
		}
		min(node->right);
	}

	int height(Node* node) {
		if (node == nullptr) {
			return -1;
		}

		return max(height(node->right), height(node->left)) + 1;
	}

	void depth(int x) {
		Node* node = search(x);

		int count = 0;
		while (node->parent != nullptr) {
			count++;
			node = node->parent;
		}

		cout << count << "\n";
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

		else if (str == "min") {
			cin >> k;
			c = 0;
			bst.min(bst.root);
		}

		else if (str == "height") {
			int x;
			cin >> x;
			cout << bst.height(bst.search(x)) << "\n";
		}
	}
}