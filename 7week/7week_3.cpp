#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node* parent;
	int value;
	vector<Node*> childList;
	int depth;

	Node(Node* parent, int value, int depth) {
		this->parent = parent;
		this->value = value;
		this->depth = depth;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> nodeList;

	Tree(int x) {
		root = new Node(nullptr, x, 0);
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

	void InsertNode(int x, int y) {
		Node* node = findNode(x);

		Node* newnode = new Node(node, y, node->depth + 1);
		node->childList.push_back(newnode);
		nodeList.push_back(newnode);
	}

	void postOrder(Node* node) {
		for (int i = 0; i < node->childList.size(); i++) {
			postOrder(node->childList[i]);
		}

		if (node->childList.size() == 0) {
			cout << node->depth << " ";
		}

		else {
			cout << node->childList.size() << " ";
		}

	}
};

int main() {
	int n, t;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;
		Tree tree(1);

		for (int i = 0; i < t - 1; i++) {
			int x, y;
			cin >> x >> y;
			tree.InsertNode(x, y);
		}

		tree.postOrder(tree.root);

		cout << "\n";

	}
}