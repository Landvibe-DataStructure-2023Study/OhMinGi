#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n, m, k, a, b;
vector<int> graph[201];
bool visited[201];
int maxx = -1;

/*int bfs(int start) {
    queue<int> q;

    q.push(start);

    int min = 101;

    while (!q.empty()){
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
}*/

void DFS(int x) {
    if (x > maxx) { maxx = x; }
    visited[x] = true;
    for (int i : graph[x]) {
        if (!visited[i]) DFS(i);
    }
}

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
        }

        while (k--) {
            maxx = -1;
            cin >> a;
            DFS(a);
            cout << maxx << "\n";
            for (int i = 0; i <= 100; i++) {
                visited[i] = false;
            }
        }

        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
        }
    }
}
