#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arraySize;

public:

	Array(int n) {
		this->arraySize = n;
		this->arr = new int[arraySize];
		for (int i = 0; i < arraySize; i++) {
			arr[i] = 0;
		}
	}

	void at(int idx) {
		cout << arr[idx] << endl;
	}

	void add(int idx, int value) {
		for (int i = arraySize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void set(int idx, int value) {
		arr[idx] = value;
	}

	void print() {
		for (int i = 0; i < arraySize; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arraySize; i++) {
			arr[i - 1] = arr[i];
		}

		arr[arraySize - 1] = 0;
	}

	void find_max() {
		int big = arr[0];

		for (int i = 1; i < arraySize; i++) {
			if (arr[i] > big) {
				big = arr[i];
			}
		}

		cout << big << endl;
	}
};

int main() {
	int t = 0, i, x, size = 0;
	string str;
	cin >> t >> size;
	Array ar(size);

	while (t--) {
		cin >> str;
		if (str == "at") {
			cin >> i;
			ar.at(i);
		}

		else if (str == "find_max") {
			ar.find_max();
		}

		else if (str == "print") {
				ar.print();
		}

		else if (str == "remove") {
			cin >> i;
			ar.remove(i);
		}

		else if (str == "set") {
			cin >> i >> x;
			ar.set(i, x);
		}

		else if (str == "add") {
			cin >> i >> x;
			ar.add(i, x);
		}
	}

	return 0;
}