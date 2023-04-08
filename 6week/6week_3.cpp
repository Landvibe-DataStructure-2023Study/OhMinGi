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

	Tree(int x) {
		root = new Node(nullptr, x);
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
			return;
		}


		Node* newNode = new Node(node, y);
		node->childlist.push_back(newNode);
		nodeList.push_back(newNode);

	}

	void deleteNode(int x) {
		Node* node = findNode(x);

		if (node == nullptr) {
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

	void parent(int x) {
		Node* node = findNode(x);

		if (node == nullptr) {
			cout << -1 << "\n";
		}

		else {

			cout << node->parent->value << "\n";
		}
	}

	void child(int x) {
		Node* node = findNode(x);

		if (node == nullptr || node->childlist.size() == 0) {
			cout << -1 << "\n";
			return;
		}

		for (int i = 0; i < node->childlist.size(); i++) {
			cout << node->childlist[i]->value << " ";
		}

		cout << "\n";
	}

	void min_maxChild(int x) {
		Node* node = findNode(x);

		if (node == nullptr || node->childlist.size() < 2) {
			cout << -1 << "\n";
		}

		else {
			int max = node->childlist[0]->value;

			for (int i = 0; i < node->childlist.size(); i++) {
				if (node->childlist[i]->value >= max) {
					max = node->childlist[i]->value;
				}
			}


			int min = node->childlist[0]->value;

			for (int i = 0; i < node->childlist.size(); i++) {
				if (node->childlist[i]->value <= min) {
					min = node->childlist[i]->value;
				}
			}

			int result = max - min;
			cout << result << "\n";
		}

	}
};

int main() {
	int n;
	cin >> n;

	Tree tree(1);

	while (n--) {
		string str;
		cin >> str;

		if (str == "insert") {
			int x, y;
			cin >> x >> y;
			tree.insertNode(x, y);
		}

		else if (str == "delete") {
			int x;
			cin >> x;
			tree.deleteNode(x);
		}

		else if (str == "parent") {
			int x;
			cin >> x;
			tree.parent(x);
		}

		else if (str == "child") {
			int x;
			cin >> x;
			tree.child(x);
		}

		else if (str == "min_maxChild") {
			int x;
			cin >> x;
			tree.min_maxChild(x);
		}
	}
}

