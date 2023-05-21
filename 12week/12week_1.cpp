#include <iostream>
#include <string>

#define NOITEM 0
#define ISITEM 1
#define AVAILAVLE 2

using namespace std;

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

    void erase() {   //엔트리의 상태 AVAILABLE로 바꿈
        valid = AVAILAVLE;
    }

};
class hashTable {
private:
    entry* table;   //해시테이블 저장하는 변수
    int capacity;   //해시테이블 용량 변수
    int hashFunc(int key) {
        return key % capacity;
    }
public:
    hashTable(int N) {
        capacity = N;
        table = new entry[capacity];
    }

    void put(int key, string value) {
        int index = hashFunc(key);  //첫번째 탐색 위치는 해시함수의 결과값
        int probe = 1;  //탐색횟수
        while (table[index].valid == ISITEM && probe <= capacity) {
            index = hashFunc(index + 1);
            probe++;
        }

        cout << probe +index << endl;
        if (probe > capacity) { return; }
        table[index] = entry(key, value);
    }
    void erase(int key) {
        find(key);
        int index = hashFunc(key);
        int probe = 1;
        while (table[index].valid != NOITEM && probe <= capacity) {
            if (table[index].valid == ISITEM && table[index].key == key) {
                table[index].erase();
                return;

            }
            index = hashFunc(index + 1);
            probe++;
        }
        return;
    }
    void find(int key) {
        int index = hashFunc(key);
        int probe = 1;
        bool empty = true;
        while (table[index].valid != NOITEM && probe <= capacity) {
            if (table[index].valid == ISITEM && table[index].key == key) {
                cout << table[index].value << endl;
                empty = false;
            }
            index = hashFunc(index + 1);
            probe++;
        }
        if (empty)
            cout << "None" << endl;
    }
    void vacant() {
        int index = 0;
        int count = 0;
        while (index < capacity) {
            if (table[index].valid != ISITEM) {
                count++;
            }
            index++;
        }
        cout << count << endl;
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t >> n;

    hashTable* ht = new hashTable(n);

    while (t--) {
        string cmd;
        cin >> cmd;

        if (cmd == "put") {
            int key;
            string value;
            cin >> key >> value;

            ht->put(key, value);
        }
        else if (cmd == "erase") {
            int key;
            cin >> key;

            ht->erase(key);
        }
        else if (cmd == "find") {
            int key;
            cin >> key;

            ht->find(key);
        }
        else if (cmd == "vacant") {
            ht->vacant();
        }
    }

    return 0;
};
