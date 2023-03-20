#include <iostream>

using namespace std;


class Node {
public:
    int value;
    Node* next;

    friend class Stack;
};

class Stack {
public:
    Node* Top=nullptr;
    int datasize=0;

    bool empty() {
        return datasize == 0;
    }

    void push(int x) {
        Node* node = new Node;
        node->value = x;

        if (Top==nullptr) {
            Top = node;
         }

        else {
            node->next = Top;
            Top = node;
        }

        datasize++;

    }

    int pop() {
        Node* node = Top;
        int tmp = node->value;
        Top = Top->next;
        delete  node;
        datasize--;
        return tmp;
    }

    int top() {
        return Top->value;
    }
};


int main() {

    int n;
    cin >> n;

        while (n--) {
            string word;
            cin >> word;
            Stack stack;


            for (int i{ 0 }; i < word.length(); i++) {

                if (word[i] >= '0' && word[i] <= '9') {
                    stack.push(word[i] - '0');
                }

                else
                {
                    if (!stack.empty())
                    {
                        int tmp = stack.top();
                        stack.pop();

                        if (word[i] == '+')
                        {
                            tmp = stack.top() + tmp;
                        }
                        else if (word[i] == '-')
                        {
                            tmp = stack.top() - tmp;
                        }
                        else if (word[i] == '*')
                        {
                            tmp = stack.top() * tmp;
                        }
                        else if (word[i] == '/')
                        {
                            tmp = stack.top() / tmp;
                        }
                        stack.pop();
                        stack.push(tmp);
                    }
                }
            }

            int n = stack.top();

            if (n < 0) {
                n = -n;
            }

            int answer = 0;

            while (n != 0) {
                answer = answer + n % 10;
                n = n / 10;
            }

            cout << answer << "\n";
        }

    return 0;
}