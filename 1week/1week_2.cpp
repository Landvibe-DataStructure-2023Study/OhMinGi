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
		
		for (int i{ 0 }; i < arraySize; i++) {
			arr[i] = 0;
		}
	}

	void shift(int d) {
		while (d--) {

			int n = arr[arraySize - 1];

			for (int i = arraySize - 2; i >= 0; i--) {
				arr[i + 1] = arr[i];
			}

			arr[0] = n;
		}
	}

	void Switch(int i, int j) {
		int tmp;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	void print() {
		for (int i = 0; i < arraySize; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}

	void set(int idx, int value) {
		arr[idx] = value;
	}

};

int main() {
	int t = 0, d,i,j, size = 0;
	string str;
	cin >> t >> size;
	Array ar(size);

	for (int t = 0; t < size; t++) {
		int value;
		cin >> value;
		ar.set(t, value);
	}

	while (t--) {
		cin >> str;

		if (str == "shift") {
			
			cin >> d;
			ar.shift(d);
		}

		else if (str == "switch") {
			cin >> i >> j;
			ar.Switch(i, j);
		}

		else if (str == "print") {
			ar.print();
		}
	}
}