#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 501;
int graph[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE];

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    for (int i = 0; i < d; i++) {
        int a;
        cin >> a;
        b[a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    while (m--) {
        vector<int> v;
        int arr[MAX_SIZE] = { 0 };
       
        int k, f;
        cin >> k >> f;

        if (f == 1) {
            for (int i = 1; i <= n; i++) {
                if (graph[k][i] == 1 && arr[i] != 1 && b[i] != 1) {
                    
                    v.push_back(i);               
                }
            }
        }
        else if (f == 2) {
            for (int i = 1; i <= n; i++) {
                if (graph[k][i] == 1) {
                    if (b[i] != 1 && arr[i] != 1) {
                       
                        v.push_back(i);
                        arr[i] = 1;
                    }                  

                    for (int t = 1; t <= n; t++) {
                        if (graph[i][t] == 1 && k != t && arr[t] != 1 && b[t] != 1) {
                            v.push_back(t);
                            arr[t] = 1;
                        }
                    }
                }
            }
        }

        bubbleSort(v);

        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }

        if (v.empty()) {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}
