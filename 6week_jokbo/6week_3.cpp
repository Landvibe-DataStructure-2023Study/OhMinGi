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

		if (node == nullptr) {
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

	while (n--) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}

	while (m--) {		
		int c;
		cin >> c;
		bool b = false;

		vector <Node*> nv;

		for (int i = 0; i < tree.nodeList.size(); i++) {
			int result= tree.depth(tree.nodeList[i]);

			if (result == c) {
				nv.push_back(tree.nodeList[i]);
				b = true;
			}
		}
		if (b == false) {
			cout << 0 << "\n";
			continue;
		}

		int big=nv[0]->value;
		for (int i = 0; i < nv.size(); i++) {
			if (nv[i]->value > big) {
				big = nv[i]->value;
			}
		}


		cout << big << "\n";
		
	}
}

/*
10 3
1 2
1 3
1 4
2 5
3 6
3 7
6 8
6 9
6 10
6 11
1
0
4
*/