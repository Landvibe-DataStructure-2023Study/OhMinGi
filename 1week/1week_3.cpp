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

	void find(int z) {

		bool fact = false;
		int num;

		for (int i = 0; i < arraySize; i++) {
			if (arr[i] == z) {	
				num = i;
				fact = true;
				break;
			}
		}

		if (fact == false) {
			cout << -1<<"\n";
		}
		else if (fact == true) {
			cout << num << "\n";
		}
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

		else if (str == "find") {
			cin >> x;
			ar.find(x);
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