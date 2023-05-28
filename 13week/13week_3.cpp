#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 10001;
bool graph[MAX_SIZE][MAX_SIZE];
bool ver[MAX_SIZE];
int edgeCount[MAX_SIZE];

int main() {
    int t;
    string cmd;
    cin >> t;

    while (t--) {
        cin >> cmd;
        if (cmd == "insertEdge") {
            int s, d;
            cin >> s >> d;
            if (graph[s][d]) {
                cout << "Exist" << endl;
            }
            else {
                graph[s][d] = true;
                graph[d][s] = true;
                edgeCount[s]++;
                edgeCount[d]++;
            }
        }
        else if (cmd == "insertVertex") {
            int s;
            cin >> s;
            if (ver[s]) {
                cout << "Exist" << endl;
            }
            else {
                ver[s] = true;
            }
        }
        else if (cmd == "eraseVertex") {
            int s;
            cin >> s;
            if (!ver[s]) {
                cout << "None" << endl;
            }
            else {
                ver[s] = false;
                for (int i = 1; i < MAX_SIZE; i++) {
                    if (graph[s][i]) {
                        graph[s][i] = false;
                        graph[i][s] = false;
                        edgeCount[i]--;
                    }
                }
                edgeCount[s] = 0;
            }
        }
        else if (cmd == "isAdjacentEven") {
            int s;
            cin >> s;
            cout << (edgeCount[s] % 2 == 0 ? "True " : "False ") << edgeCount[s] << endl;
        }
        else if (cmd == "maxEdgeVertex") {
            int maxEdges = -1;
            int resultVertex = -1;
            bool hasEdges = false;

            for (int i = 1; i < MAX_SIZE; i++) {
                if (ver[i] && edgeCount[i] > maxEdges) {
                    maxEdges = edgeCount[i];
                    resultVertex = i;
                    hasEdges = true;
                }
            }

            if (maxEdges==0 || hasEdges==false) {
                cout << "-1" << endl;
            }
            else {
                cout << resultVertex << endl;
            }
        }
    }

    return 0;
}
