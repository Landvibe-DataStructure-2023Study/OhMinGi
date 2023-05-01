#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
public:
	vector<int> v;
	vector<int> odd;
	vector<int> even;

	void push(int x) {
		if (x % 5 == 0) {
			if (even.empty()) {
				even.push_back(x);
			}
			else {
				vector<int>::iterator p = even.begin();
				for (p; p != even.end(); p++) {
					if (*p > x) {
						even.insert(p, x);
						return;
					}
				}

				even.push_back(x);
			}
		}

		else if (x % 5 != 0) {
			if (odd.empty()) {
				odd.push_back(x);
			}
			else {
				vector<int>::iterator p = odd.begin();
				for (p; p != odd.end(); p++) {
					if (*p > x) {
						odd.insert(p, x);
						return;
					}
				}

				odd.push_back(x);
			}
		}
	}

	void sort() {

		for (int i = 0; i < odd.size(); i++) {
			v.push_back(odd[i]);
		}


		for (int i = 0; i < even.size(); i++) {
			v.push_back(even[i]);
		}

		
	}

	int pop() {
		int tmp = v.front();
		v.erase(v.begin());
		return tmp;
	}

	/*void push1(int x) {
		v.push_back(x);
	}*/

	/*int pop1() {
		vector<int>::iterator p = v.begin();
		vector<int>::iterator iter = v.begin();
		for (iter; iter != v.end(); iter++) {
			if (*p % 2 == 1 && *iter % 2 == 0) {
				p = iter;
			}
			else if (*p % 2 == *iter % 2) {
				if (*p > *iter) {
					p = iter;
				}
			}
		}

		int tmp = *p;
		v.erase(p);
		return tmp;
	}*/
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

		pq.sort();

		for (int i = 0; i < t; i++) {
			v.push_back(pq.pop());
		}

		for (int i = 0; i < t; i++) {
			cout << v[i] << " ";
		}

		cout << "\n";
	}
}