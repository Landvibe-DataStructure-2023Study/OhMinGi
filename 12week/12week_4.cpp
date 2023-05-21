#include<iostream>
using namespace std;
#define ISITEM 1
#define NOITEM 0
#define AVAILABLE 2
class entry {
public:
    int num;
    int classnum;
    string name;
    bool check;
    int valid;

    entry() {
        num = 0;
        classnum = 0;
        name = "";
        check = false;
        valid = NOITEM;
    }

    entry(int num, int classnum,string name) {
        this->classnum = classnum;
        this->num = num;
        this->name = name;
        valid = ISITEM;
        check = false;
    }
};

class HashTable {
public:
    int capacity;
    entry* tableNum;
    entry* tableName;
    int size;

    HashTable() {
        capacity = 2000003;
        tableName = new entry[capacity];
        tableNum = new entry[capacity];
        size = 0;
    }

    int hashfnc(int key) {
        return key % capacity;
    }

    int StringToInt(string name) {
        int key = 0;
        int a = 1;
        for (int i = 0; i < 6; i++) {
            key += (name[i] - 'a') * a;
            a *= 26;
        }
        return key;
    }

    void add(int x, int c, string s) {
        int keyName = hashfnc(StringToInt(s));
        int keyNum = hashfnc(x);

        while (tableName[keyName].valid == ISITEM) {
            keyName = hashfnc(keyName + 1);
        }
        tableName[keyName] = entry(x,c, s);

        while (tableNum[keyNum].valid == ISITEM) {
            keyNum = hashfnc(keyNum + 1);
        }
        tableNum[keyNum] = entry(x,c, s);
    }

    void erase(int x) {
        int keyNum = hashfnc(x);
        string s;

        while (tableNum[keyNum].valid != NOITEM) {
            if (tableNum[keyNum].valid == ISITEM && tableNum[keyNum].num == x) {
                s = tableNum[keyNum].name;
                tableNum[keyNum].valid = AVAILABLE;
                cout << s << " " << tableNum[keyNum].classnum << "\n";
            }
            keyNum = hashfnc(keyNum + 1);
        }

        int keyName = hashfnc(StringToInt(s));

        while (tableName[keyName].valid != NOITEM) {
            if (tableName[keyName].valid == ISITEM && tableName[keyName].num == x) {
                tableName[keyName].valid = AVAILABLE;
                if (tableName[keyName].check == true)
                    size--;
                return;
            }
            keyName = hashfnc(keyName + 1);
        }
    }

    void change(int x,int c) {
        int keyNum = hashfnc(x);
        string name;

        while (tableNum[keyNum].valid != NOITEM) {
            if (tableNum[keyNum].valid == ISITEM && tableNum[keyNum].num == x) {
               name= tableNum[keyNum].name;
               tableNum[keyNum].classnum = c;
            }
            keyNum = hashfnc(keyNum + 1);
        }

        int keyname = hashfnc(StringToInt(name));

        while (tableName[keyname].valid != NOITEM) {
            if (tableName[keyname].valid == ISITEM && tableName[keyname].num == x) {
                tableName[keyname].classnum = c;
                return;
            }

            keyname = hashfnc(keyname + 1);
        }
    }

    void name(int x) {
        int keyNum = hashfnc(x);

        while (tableNum[keyNum].valid != NOITEM) {
            if (tableNum[keyNum].valid == ISITEM && tableNum[keyNum].num == x) {
                cout << tableNum[keyNum].name << "\n";
                return;
            }
            keyNum = hashfnc(keyNum + 1);
        }
    }


    void present(string s) {
        int keyName = hashfnc(StringToInt(s));

        while (tableName[keyName].valid != NOITEM) {
            if (tableName[keyName].valid == ISITEM && tableName[keyName].name == s) {
                if (tableName[keyName].check == false)
                    size++;
                tableName[keyName].check = true;
                cout << tableName[keyName].num<<" "<<tableName[keyName].classnum << endl;
                return;
            }
            keyName = hashfnc(keyName + 1);
        }
        cout << "Invalid" << endl;
    }

    void absent(string s) {
        int keyName = hashfnc(StringToInt(s));

        while (tableName[keyName].valid != NOITEM) {
            if (tableName[keyName].valid == ISITEM && tableName[keyName].name == s) {
                if (tableName[keyName].check == true)
                    size--;
                tableName[keyName].check = false;
                cout << tableName[keyName].num<<" "<<tableName[keyName].classnum << endl;
                return;
            }
            keyName = hashfnc(keyName + 1);
        }
        cout << "Invalid" << endl;
    }
};

int main() {
    int t;
    cin >> t;
    HashTable ht;
    while (t--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int a,c;
            string b;
            cin >> a>>c >> b;
            ht.add(a,c, b);
        }
        else if (cmd == "delete") {
            int a;
            cin >> a;
            ht.erase(a);
        }
        else if (cmd == "change") {
            int a,c;
            cin >> a>>c;
            ht.change(a,c);
        }
        else if (cmd == "present") {
            string a;
            cin >> a;
            ht.present(a);
        }
        else if (cmd == "absent") {
            string a;
            cin >> a;
            ht.absent(a);
        }
        else if (cmd == "name") {
            int a;
            cin >> a;
            ht.name(a);
        }
    }
    cout << ht.size << endl;
}