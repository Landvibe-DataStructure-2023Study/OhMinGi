#include <iostream>

using namespace std;

int n;

class Queue {
public:
	int arr[100];
	int frontIdx = 0;
	int rearIdx = -1;

	void enqueue(int x) {		
			arr[++rearIdx] = x;	
	}

	int dequeue() {		
		return arr[frontIdx++];
	}
};


int main() {
	
	cin >> n;

	while (n--) {
		Queue q1;
		Queue q2;

		int Q1 = 0;
		int Q2 = 0;
		int surplusHp1 = 0, surplusHp2 = 0;

		int x;
		cin >> x;

		for (int i = 0; i < x;i++) {
			int c;
			cin >> c;
			q1.enqueue(c);
		}		

		for (int i = 0; i < x;i++) {
			int c;
			cin >> c;
			q2.enqueue(c);
		}

		
		for (int i =1; i <= x;i++) {

			int cardOfP1 = q1.dequeue() + surplusHp1;
			int cardOfP2 = q2.dequeue() + surplusHp2;

			if (cardOfP1 > cardOfP2) {
				surplusHp1 = cardOfP1 - cardOfP2;
				surplusHp2 = 0;
				Q1++;
				cout << "Round" << i << " " << cardOfP1 << ">" << cardOfP2 << " " << Q1 << ":" << Q2 << "\n";
			}
			else if (cardOfP2 > cardOfP1) {
				surplusHp2 = cardOfP2 - cardOfP1;
				surplusHp1 = 0;
				Q2++;
				cout << "Round" << i << " " << cardOfP1 << "<" << cardOfP2 << " " << Q1 << ":" << Q2 << "\n";
			}
			else {
				surplusHp1 = surplusHp2 = 0;
				cout << "Round" << i << " " << cardOfP1 << "=" << cardOfP2 << " " << Q1 << ":" << Q2 << "\n";
			}

		}

		if (Q1 > Q2) {
			cout << "Winner P1" << "\n";
		}

		else if (Q1 < Q2) {
			cout << "Winner P2" << "\n";
		}


		else if(Q1==Q2) {
			cout << "Draw" << "\n";
		}

	}
}













