#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int>arr;

    void swap(int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    void upHeap(int idx) {
        if (idx == 1) return;

        int parent = idx / 2;
        if (arr[idx] < arr[parent]) {
            swap(idx, parent);
            upHeap(parent);
        }
    }

    void downHeap(int idx) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int child;

        if (left > size()) {
            return;
        }

        else if (left == size()) {
            child = left;
        }

        else {
            if (arr[left] < arr[right]) {
                child = left;
            }
            else {
                child = right;
            }
        }

        if (arr[child] < arr[idx]) {
            swap(child, idx);
            downHeap(child);
        }
    }

public:

    Heap() {
        arr.push_back(0);
    }

    int size() {
        return arr.size() - 1;
    }

    bool empty() {
        return arr.size() == 1;
    }

    void isEmpty() {
        if (empty()) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    void insert(int e) {
        arr.push_back(e);
        upHeap(size());
    }

    int pop() {
        if (empty()) return -1;

        int temp = arr[1];
        swap(1, size());
        arr.pop_back();
        downHeap(1);
        return temp;
    }

    int top() {
        if (empty()) return -1;
        return arr[1];
    }

    void print() {
        if (empty()) {
            cout << -1 << '\n';
            return;
        }
        for (int i = 1; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    int tc;

    cin >> tc;
    Heap h;
    while (tc--) {
        string q;

        cin >> q;

        if (q == "insert") {
            int n;
            cin >> n;
            h.insert(n);
        }
        else if (q == "size") {
            cout << h.size() << '\n';
        }
        else if (q == "isEmpty") {
            h.isEmpty();
        }
        else if (q == "pop") {
            cout << h.pop() << '\n';
        }
        else if (q == "top") {
            cout << h.top() << '\n';
        }
        else if (q == "print") {
            h.print();
        }
    }
}