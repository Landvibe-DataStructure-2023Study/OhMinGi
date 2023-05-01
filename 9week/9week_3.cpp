#include <iostream>
#include <vector>

using namespace std;

class PrioirtyQueue {
public:
	vector<int> v;

	bool empty() {
		return v.size() == 0;
	}

	void push(int x) {
		v.push_back(x);
	}

	int pop() {
		if (!empty()) {
			vector<int>::iterator p;
			p = v.begin();
			int max=*p;
			int i = 0;
			int index = i;
			for (p; p != v.end(); p++) {
				if (*p > max) {
					max = *p;
					index = i;
				}
				i++;
			}

			int tmp = v[index];
			v.erase(v.begin() + index);
			return tmp;
		}

		else { return 0; }
	}
};

int main() {
	int n;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;

		PrioirtyQueue pq;
		vector<int> v;

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
			cout << v[0] - v[i] << " ";
		}

		cout << "\n";
	}
}