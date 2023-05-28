#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 10001;
bool graph[MAX_SIZE][MAX_SIZE];
bool ver[MAX_SIZE];

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
        else if (cmd == "eraseEdge") {
            int s, d;
            cin >> s >> d;
            if (!graph[s][d]) {
                cout << "None" << endl;
            }
            else {
                graph[s][d] = false;
                graph[d][s] = false;
            }
        }
        else if (cmd == "isAdjacentOdd") {
            int s;
            cin >> s;
            int count = 0;
            for (int i = 1; i < MAX_SIZE; i++) {
                if (graph[i][s]) {
                    count++;
                }
            }
            if (count % 2 == 0) {
                cout << "False " << count << endl;
            }
            else {
                cout << "True " << count << endl;
            }
        }
        else if (cmd == "minEdgeVertex") {
            int minEdges = MAX_SIZE;
            int resultVertex = -1;
            bool hasEdges = false;

            for (int i = 1; i < MAX_SIZE; i++) {

                if (ver[i]) {
                    hasEdges = false;
                    int edges = 0;
                    for (int j = 1; j < MAX_SIZE; j++) {

                        if (graph[i][j]) {
                            edges++;
                            hasEdges = true;
                        }
                    }
                    if (hasEdges == false) {
                        break;
                    }
                    if (edges < minEdges && edges > 0) {
                        minEdges = edges;
                        resultVertex = i;
                    }
                }
            }

            if (!hasEdges) {
                cout << "-1" << endl;
            }
            else {
                cout << resultVertex << endl;
            }
        }

    }

    return 0;
}
