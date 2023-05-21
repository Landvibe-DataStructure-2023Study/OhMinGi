#include<iostream>
using namespace std;
#define NOITEM 0
#define ISITEM 1

class entry {
public:
    string s;
    string p;
    int valid;
    bool log;

    entry() {
        s = "";
        p = "";
        valid = NOITEM;
        log = false;
    }

    entry(string s, string p) {
        this->s = s;
        this->p = p;
        valid = ISITEM;
        log = false;
    }
};

class Hashtable {
public:
    entry* table;
    int capacity;

    Hashtable() {
        capacity = 200003;
        table = new entry[capacity];
    }

    int StringToInt(string s) {
        int key = 0;
        int a = 1;
        for (int i = 0; i < 6; i++) {
            key += (s[i] - 'a') * a;
            a *= 26;
        }
        return key;
    }

    int hashfnc(int key) {
        return key % capacity;
    }

    void signup(string s, string p) {
        int k = StringToInt(s);
        int idx = hashfnc(k);

        while (table[idx].valid == ISITEM) {
            if (table[idx].s == s) {
                cout << "Invalid"<<" "<<table[idx].p << endl;
                return;
            }
            idx = hashfnc(idx + 1);
        }
        table[idx] = entry(s, p);
        cout << "Submit" << endl;
    }

    void login(string s, string p) {
        int k = StringToInt(s);
        int idx = hashfnc(k);


        while (table[idx].valid == ISITEM) {
            if (table[idx].s == s && table[idx].p == p && table[idx].log == true) {
                cout << "Quit" << endl;
                return;
            }
            else if (table[idx].s == s && table[idx].p == p && table[idx].log == false) {
                table[idx].log = true;
                cout << "Submit" << endl;
                return;
            }
            idx = hashfnc(idx + 1);
        }
        cout << "Invalid" << endl;

    }

    void logout(string s) {
        int k = StringToInt(s);
        int idx = hashfnc(k);

        while (table[idx].valid == ISITEM) {
            if (table[idx].s == s && table[idx].log == true) {
                table[idx].log = false;
            }
            idx = hashfnc(idx + 1);
        }
        cout << "Submit" << endl;
    }

    void change(string s, string p) {
        int k = StringToInt(s);
        int idx = hashfnc(k);

        while (table[idx].valid == ISITEM) {
            if (table[idx].s == s && table[idx].log == true) {
                table[idx].p = p;
            }
            idx = hashfnc(idx + 1);
        }
        cout << "Submit" << endl;
    }
};

int main() {
    int t;
    cin >> t;
    Hashtable ht;
    while (t--) {
        string cmd;
        cin >> cmd;
        if (cmd == "signup") {
            string a, b;
            cin >> a >> b;
            ht.signup(a, b);
        }
        else if (cmd == "login") {
            string a, b;
            cin >> a >> b;
            ht.login(a, b);
        }
        else if (cmd == "logout") {
            string a;
            cin >> a;
            ht.logout(a);
        }
        else if (cmd == "change") {
            string a, b;
            cin >> a >> b;
            ht.change(a, b);
        }
    }
}

