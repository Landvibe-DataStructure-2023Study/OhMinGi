#include<iostream>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
class entry {
public:
    int key;
    string value;
    int valid;

    entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }

    entry(int key, string value) {
        this->key = key;
        this->value = value;
        valid = ISITEM;
    }
};

class HashTable {
public:
    int capacity;
    entry* table;
    int divisor;

    HashTable(int N, int M) {
        capacity = N;
        table = new entry[capacity];
        divisor = M;
    }

    int hashfnc(int key) {
        return key % capacity;
    }

    int hashfnc2(int key) {
        return divisor - (key % divisor);
    }

    void put(int k, string v) {
        int idx = hashfnc(k);
        int cnt = 1;

        while (cnt <= capacity && table[idx].valid == ISITEM) {
            idx = hashfnc(idx + hashfnc2(k));
            cnt++;
        }
        if (cnt > capacity) return;
        table[idx] = entry(k, v);
        cout << cnt + idx << endl;
    }

    void erase(int k) {
        int idx = hashfnc(k);

        while (table[idx].valid != NOITEM) {
            if (table[idx].valid == ISITEM && table[idx].key == k) {
                cout << table[idx].value << endl;
                table[idx].valid = AVAILABLE;
                return;
            }
            idx = hashfnc(idx + hashfnc2(k));
        }
        cout << "None" << endl;
    }

    void find(int k) {
        int idx = hashfnc(k);

        while (table[idx].valid != NOITEM) {
            if (table[idx].valid == ISITEM && table[idx].key == k) {
                cout << table[idx].value << endl;
                return;
            }
            idx = hashfnc(idx + hashfnc2(k));
        }
        cout << "None" << endl;
    }

    void vacant() {
        int cnt = 0;
        for (int i = 0; i < capacity; i++) {
            if (table[i].valid != ISITEM)
                cnt++;
        }
        cout << cnt << endl;
    }
};

int main() {
    int t, n, m;
    cin >> t >> n >> m;
    HashTable* ht = new HashTable(n, m);
    while (t--) {
        string cmd;
        cin >> cmd;
        if (cmd == "put") { 
            int a;
            string b;
            cin >> a >> b;
            ht->put(a, b);
        }
        else if (cmd == "erase") {
            int a;
            cin >> a;
            ht->erase(a);
        }
        else if (cmd == "find") {
            int a;
            cin >> a;
            ht->find(a);
        }
        else if (cmd == "vacant") {
            ht->vacant();
        }
    }
}

