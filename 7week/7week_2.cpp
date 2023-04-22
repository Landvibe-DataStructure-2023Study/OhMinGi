#include <iostream>
#include <vector>

using namespace std;

bool b = false;
int t;

class Node {
public:
	Node* parent;
	int value;
	vector<Node*> childList;
	int depth;
	int num;
	int sumnum = 0;

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

		for (Node* n : node->childList) {
			postOrder(n);
		}
		
		if (node->childList.size() == 0) {
			node->sumnum = node->num;
		}

		else {
			node->sumnum += node->num;
			for (int i = 0; i < node->childList.size(); i++) {
				node->sumnum += node->childList[i]->sumnum;
			}
		}
	}

	void postorder(Node* node) {
		for (Node* n : node->childList) {
			postorder(n);
		}

		if (node->sumnum >= t) {
			cout << node->value << " ";
			b = true;
		}

		//cout << node->sumnum << " ";
	}
	void insertnum(int index, int y) {
		Node* node = findNode(index);

		node->num = y;
	}
};

int main() {
	int n;
	cin >> n >> t;

	Tree tree(1);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.InsertNode(x, y);
	}

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertnum(x, y);
	}

		tree.postOrder(tree.root);
		tree.postorder(tree.root);

		if (b == false) {
			cout << -1;
		}
	
}
