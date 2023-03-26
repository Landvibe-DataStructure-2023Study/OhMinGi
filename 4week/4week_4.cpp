#include <iostream>

using namespace std;

class Queue {
private:
	int frontIdx = 0;
	int rearIdx = -1;
	int dataSize = 0;
	int arr[10000];

public:
	int dequeue() {
		int tmp = arr[frontIdx];
		frontIdx++;
		dataSize--;
		return tmp;
	}

	void enqueue(int x) {
		arr[++rearIdx] = x;
		dataSize++;
	}
};


int main() {
	int n;
	cin >> n;

	while (n--) {
		Queue q1;
		Queue q2;

		int Q1 = 0;
		int Q2 = 0;

		int hp1 = 0;
		int hp2 = 0;

		int result1=0;
		int result2=0;

		int t;
		cin >> t;

		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			q1.enqueue(x);
		}

		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			q2.enqueue(x);
		}

		for (int i = 1; i <= t; i++) {
			result1 = q1.dequeue() + hp1;
			result2 = q2.dequeue() + hp2;

			if (result1 > result2) {
				Q1++;
				hp2 = result1 - result2;
				hp1 = 0;
				cout << "Round" << i << " " << "P1"<<" "<< hp2 << "\n";
			}

			else if (result1 < result2) {
				Q2++;
				hp1 = result2 - result1;
				hp2 = 0;
				cout << "Round" << i << " " << "P2" << " " << hp1 << "\n";
			}

			else {
				hp1 = hp2 = 0;
				cout << "Round" << i <<" Draw" << "\n";
			}
		}

		if (Q1 > Q2) {
			cout << "Total Score "<<Q1<<":"<<Q2 <<" Winner P1" << "\n";
		}

		else if (Q1 < Q2) {
			
			cout << "Total Score " << Q1 << ":" << Q2 << " Winner P2" << "\n";
		}

		else {
			
			cout << "Total Score " << Q1 << ":" << Q2 << " Draw" << "\n";
		}
	}
}

