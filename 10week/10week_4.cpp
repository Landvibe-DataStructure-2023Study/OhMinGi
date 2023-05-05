#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
	vector<int>v;
	int count = 0;

	Heap() {
		v.push_back(0);
	}

	void swap(int index1, int index2) {
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
		if (v[parent] > v[index]) {
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
		else if (left == size()) {
			child = left;
		}
		else {
			if (v[left] > v[right]) {
				child = right;
			}
			else {
				child = left;
			}
		}

		if (v[child] < v[index]) {
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

	int pop() {
		if (empty()) {
			return -1;
		}

		else {
			int tmp = v[1];
			swap(1, size());
			v.pop_back();
			downheap(1);
			return tmp;
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
			cout << v[i] << " ";
		}

		cout << "\n";
	}

	int Min() {
		int max = v[1];

		for (int i = 1; i < v.size(); i++) {
			if (max > v[i]) {
				max = v[i];
			}
		}

		return max;
	}

	void removeMin() {
		if (empty()) {
			return;
		}

		swap(1, size());
		v.pop_back();
		downheap(1);
	}

	void preorder(int x) {
		

		if (x * 2 <= v.size() - 1) {
			preorder(x * 2);
		}


		if (x * 2 + 1 <= v.size() - 1) {
			preorder(x * 2 + 1);
		}

		cout << v[x] << " ";
	}
};

int main() {
	int n;
	cin >> n;

	while (n--) {
		Heap heap;

		int c, max;
		int count = 0;
		cin >> c >> max;

		while (c--) {
			int x;
			cin >> x;
			heap.insert(x);
		}

		while (heap.Min() < max) {
			if (heap.size() <= 2) {
				count = -1;
				cout << "False\n";
				break;
			}

			count++;
			int v1 = heap.Min();
			heap.removeMin();
			int v2 = heap.Min();
			heap.removeMin();
			int v3 = heap.Min();
			heap.removeMin();
			vector<int> v;
			v.push_back(v1);
			v.push_back(v2);
			v.push_back(v3);
			int m = v1;
			int mi = v1;
			for (int i = 0; i < v.size(); i++) {
				if (m < v[i]) {
					m = v[i];
				}

				if (mi > v[i]) {
					mi = v[i];
				}
			}

			int value = (m + mi) / 2;
			heap.insert(value);
		}


		if (count != -1) {
			cout << count << "\n";
			heap.preorder(1);
			cout << "\n";
		}
	}
}