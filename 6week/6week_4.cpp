#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node* parent;
	int value;
	vector<Node*>childlist;

	Node(Node* parent, int value) {
		this->parent = parent;
		this->value = value;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*>nodeList;

	Tree() {
		root = new Node(nullptr, 1);
		nodeList.push_back(root);
	}

	Node* findNode(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == x) {
				return nodeList[i];
			}
		}

		return nullptr;
	}

	void insertNode(int x, int y) {
		Node* node = findNode(x);
		bool b = false;

		if (node == nullptr) {
			cout << -1 << "\n";
			return;
		}

		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == y) {
				b = true;
			}
		}

		if (b == true) {
			cout << -1 << "\n";
		}
		else {
			Node* newNode = new Node(node, y);
			node->childlist.push_back(newNode);
			nodeList.push_back(newNode);
		}
	}

	void deleteNode(int x) {
		Node* node = findNode(x);

		if (node == nullptr || node == root) {
			cout << -1 << "\n";
		}

		else {

			for (int i = 0; i < node->childlist.size(); i++) {
				node->parent->childlist.push_back(node->childlist[i]);
				node->childlist[i]->parent = node->parent;
			}

			for (int i = 0; i < node->parent->childlist.size(); i++) {
				if (node->parent->childlist[i] == node) {
					node->parent->childlist.erase(node->parent->childlist.begin() + i);
					break;
				}
			}

			for (int i = 0; i < nodeList.size(); i++) {
				if (nodeList[i] == node) {
					nodeList.erase(nodeList.begin() + i);
					break;
				}
			}

			delete node;
		}

	}

	void print(int x) {
		Node* node = findNode(x);

		if (node == nullptr || node->childlist.empty()) {
			cout << -1 << "\n";
		}

		else {
			for (int i = 0; i < node->childlist.size(); i++) {
				cout << node->childlist[i]->value << " ";
			}

			cout << "\n";
		}
	}

	int depth(Node* n) {
		Node* node = n;

		int count = 0;

		while (node != root) {
			count++;
			node = node->parent;
		}

		return count;
	}
};

int main() {
	int n, m;
	cin >> n >> m;


	Tree tree;

	while (/*tree.nodeList.size()<n*/ n--) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}

	while (m--) {
		int x, y;
		cin >> x >> y;

		Node* node = tree.findNode(x);
		Node* ynode = tree.findNode(y);

		if (node == nullptr || ynode == nullptr) {
			cout << -1 << "\n";
			continue;
		}

		cout << tree.depth(node) + tree.depth(ynode) << "\n";
	}
}

