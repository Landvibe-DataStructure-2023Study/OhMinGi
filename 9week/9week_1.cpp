#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
public:
	vector<int> v;

	bool empty() {
		return v.size() == 0;
	}

	void push(int x) {
		if (empty()) {
			v.push_back(x);
		}
		else {
			vector<int>::iterator p;
			for (p = v.begin(); p != v.end(); p++) {
				if (x < *p) {
					v.insert(p, x);
					return;
				}
			}
			v.insert(v.end(), x);
		}
	}

	int pop() {
		if (!empty()) {
			int x = v.front();
			v.erase(v.begin());
			return x;
		}
		else {
			return 0;
		}
	}
};

int main() {
	int n;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;

		vector<int> v;
		PriorityQueue pq;

		for (int i = 0; i < t; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		for (int i = 0; i < t; i++) {
			pq.push(v.front());
			v.erase(v.begin());
		}

		for (int i = 0; i < t; i++) {
			v.push_back(pq.pop());
		}

		for (int i = 0; i < t; i++) {
			cout << v[i] << " ";
		}

		cout << "\n";
		for (int i = 1; i < t; i++) {
			cout << v[0] + v[i] << " ";
		}

		cout << "\n";
	}
}