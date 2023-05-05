#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
	vector<int>v;
	
	Heap() {
		v.push_back(0);
	}

	void swap(int index1,int index2) {
		int tmp = v[index1];
		v[index1] = v[index2];
		v[index2] = tmp;
	}

	int size() {
		return v.size() - 1;
	}

	bool empty() {
		return v.size() == 1;
	}

	void upheap(int index) {
		if (index == 1) return;

		int parent = index / 2;
		if (v[parent] < v[index]) {
			swap(parent, index);
			upheap(parent);
		}
	}

	void downheap(int index) {
		int left = index * 2;
		int right = index * 2 + 1;
		int child;

		if (size() < left) {
			return;
		}
		else if(left==size()) {
			child = left;
		}
		else {
			if (v[left] < v[right]) {
				child = right;
			}
			else {
				child = left;
			}
		}

		if (v[child] > v[index]) {
			swap(index, child);
			downheap(child);
		}
	}

	void insert(int x) {
		v.push_back(x);
		upheap(size());
	}

	void isEmpty() {
		if (empty()) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
		}

		else {
			int tmp = v[1];
			swap(1, size());
			v.pop_back();
			downheap(1);
			cout << tmp << "\n";
		}
	}

	void top() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		}
		cout << v[1] << "\n";
	}

	void print() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		}

		for (int i = 1; i < v.size(); i++) {
			cout << v[i] <<" ";
		}

		cout << "\n";
	}
};

int main() {
	int n;
	cin >> n;

	Heap heap;

	while (n--) {
		string str;
		cin >> str;
		
		if (str == "insert") {
			int x;
			cin >> x;
			heap.insert(x);
		}

		else if (str == "size") {
			cout << heap.size() << "\n";
		}

		else if (str == "isEmpty") {
			heap.isEmpty();
		}

		else if (str == "pop") {
			heap.pop();
		}
		else if (str == "top") {
			heap.top();
		}

		else if (str == "print") {
			heap.print();
		}
	}
}