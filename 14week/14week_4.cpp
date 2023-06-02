#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n, m, k, a, b;
vector<int> graph[101];
bool visited[101];
//int c = -1;

int bfs(int start) {
    queue<int> q;

    q.push(start);

    int min = 1001;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (visited[front]) continue;

        visited[front] = true;

        if (front < min) min = front;

        for (auto i : graph[front]) {
            if (!visited[i]) q.push(i);
        }
    }

    return min;
}

/*int DFS(int x) {
    if (x > c) { c=x; }
    visited[x] = true;
    for (int i : graph[x]) {
        if (!visited[i]) DFS(i);
    }
    
    return c;
}*/

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        while (m--) {
            cin >> a >> b;
            graph[a].push_back(b);
           // graph[b].push_back(a);
        }

        while (k--) {
            //c = -1;
            cin >> a;
            cout << bfs(a) << "\n";
            for (int i = 0; i <= 100; i++) {
                visited[i] = false;
            }
        }
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
        }
    }
}
