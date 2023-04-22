#include <iostream>
#include <vector>

using namespace std;

bool b = false;

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

	void preOrder(Node* node,int x) {

		if (node->depth == x && node->childList.size()==0) {
			cout << node->value << " ";
			b = true;
		}

		for (Node* n : node->childList) {
			preOrder(n,x);
		}
	}
};

int main() {
	int n, t;
	cin >> n >> t;

	Tree tree(1);

	for (int i = 0; i < n - 1; i++) {
		int x,y;
		cin >> x >> y;
		tree.InsertNode(x, y);
	}
	
	while (t--) {
		int x;
		cin >> x;
		tree.preOrder(tree.root, x);
		if (b == false) {
			cout << -1;
		}
		cout << "\n";
		b = false;
	}
}
